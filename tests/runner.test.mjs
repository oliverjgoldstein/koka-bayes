import assert from 'node:assert/strict';
import { mkdir, mkdtemp, rm, writeFile } from 'node:fs/promises';
import { tmpdir } from 'node:os';
import { join } from 'node:path';
import test from 'node:test';

import {
  assertCompleted,
  collectModules,
  parseCommand,
  parseVersion,
  resolveModelFile,
  toolPaths,
} from '../scripts/project.mjs';

test('versions recognize compiler and runtime output without accepting prereleases as stable', () => {
  assert.equal(parseVersion('Koka 3.2.3, 01:29:29 Mar 18 2026\nversion: 3.2.3\n'), '3.2.3');
  assert.equal(parseVersion('version: 3.2.3\r\n'), '3.2.3');
  assert.equal(parseVersion('v24.21.0\n'), '24.21.0');
  assert.equal(parseVersion('Koka 3.2.3-alpha1, development\n'), '3.2.3-alpha1');
  assert.notEqual(parseVersion('v24.21.0-rc.1\n'), '24.21.0');
  assert.equal(parseVersion('could not launch compiler'), null);
});

test('completion requires a successful process and an executed whole-line marker', () => {
  const marker = 'smoke checks passed';
  assert.doesNotThrow(() => assertCompleted(`check: smoke\r\n${marker}\r\n`, marker, 0));
  assert.throws(() => assertCompleted('created: smoke.mjs\n', marker, 0));
  assert.throws(() => assertCompleted(`println("${marker}")\n`, marker, 0));
  assert.throws(() => assertCompleted(`${marker}\n`, marker, 1));
  assert.throws(() => assertCompleted(`${marker}\n`, marker, null));
  assert.throws(() => assertCompleted(`${marker}\nuncaught exception: failed assertion\n`, marker, 0));
});

test('local executable paths preserve spaces and use the proper archive layouts', () => {
  const root = join(tmpdir(), 'workspace with spaces');
  for (const platform of ['linux', 'darwin']) {
    const paths = toolPaths(root, platform);
    assert.equal(paths.node, join(root, '.tools', 'node', 'bin', 'node'));
    assert.equal(paths.koka, join(root, '.tools', 'koka', 'bin', 'koka'));
  }
  const windows = toolPaths(root, 'win32');
  assert.equal(windows.node, join(root, '.tools', 'node', 'node.exe'));
  assert.equal(windows.koka, join(root, '.tools', 'koka', 'bin', 'koka.exe'));
});

test('module discovery includes the library, examples, and user model while excluding tests and archives', async (context) => {
  const root = await mkdtemp(join(tmpdir(), 'koka runner test '));
  context.after(() => rm(root, { recursive: true, force: true }));
  await mkdir(join(root, 'lib', 'nested space'), { recursive: true });
  await mkdir(join(root, 'archive'), { recursive: true });
  await mkdir(join(root, 'examples'), { recursive: true });
  await mkdir(join(root, 'tests'), { recursive: true });
  await Promise.all([
    writeFile(join(root, 'lib', 'z.kk'), 'module z\n'),
    writeFile(join(root, 'lib', 'a.kk'), 'module a\n'),
    writeFile(join(root, 'model.kk'), 'pub fun main() { println("custom model") }\n'),
    writeFile(join(root, 'lib', 'notes.md'), 'not a module\n'),
    writeFile(join(root, 'lib', 'nested space', 'main.kk'), 'module nested/main\n'),
    writeFile(join(root, 'lib', 'nested space', 'b.kk'), 'module nested/b\n'),
    writeFile(join(root, 'examples', 'coin.kk'), 'module examples/coin\n'),
    writeFile(join(root, 'archive', 'archived.kk'), 'module archived\n'),
    writeFile(join(root, 'tests', 'smoke.kk'), 'module smoke\n'),
  ]);
  const modules = await collectModules(root);
  assert.deepEqual(modules, [
    'examples/coin.kk',
    'lib/a.kk',
    'lib/nested space/b.kk',
    'lib/nested space/main.kk',
    'lib/z.kk',
    'model.kk',
  ]);
});

test('the default command runs model.kk and explicit files need no registry', () => {
  assert.deepEqual(parseCommand([]), { command: 'run', file: 'model.kk', explicitFile: false });
  assert.deepEqual(parseCommand(['run']), parseCommand([]));
  assert.deepEqual(parseCommand(['run', 'my project/custom.kk']), {
    command: 'run', file: 'my project/custom.kk', explicitFile: true,
  });
  assert.deepEqual(parseCommand(['help']), { command: 'help' });
  assert.throws(() => parseCommand(['run', 'one.kk', 'two.kk']), /Usage/);
  assert.throws(() => parseCommand(['check', 'ignored']), /Unexpected/);
});

test('make inference accepts a model path through the environment without changing ordinary runs', () => {
  const environment = { KOKA_BAYES_MODEL: 'my models/coin_model.kk' };
  assert.deepEqual(parseCommand(['inference'], environment), {
    command: 'run', file: environment.KOKA_BAYES_MODEL, explicitFile: true,
  });
  assert.deepEqual(parseCommand(['inference'], {}), parseCommand(['run'], {}));
  assert.deepEqual(parseCommand(['run'], environment), parseCommand(['run'], {}));
  assert.deepEqual(parseCommand(['inference', 'other.kk'], environment), {
    command: 'run', file: 'other.kk', explicitFile: true,
  });
});

test('model paths resolve against the caller and fail clearly for missing or invalid inputs', async (context) => {
  const root = await mkdtemp(join(tmpdir(), 'model file paths '));
  context.after(() => rm(root, { recursive: true, force: true }));
  await mkdir(join(root, 'models'));
  await writeFile(join(root, 'models', 'custom.kk'), 'pub fun main() {}\n');
  assert.equal(resolveModelFile(root, 'custom.kk', join(root, 'models')), join(root, 'models', 'custom.kk'));
  assert.throws(() => resolveModelFile(root, 'missing.kk'), /Model file not found/);
  assert.throws(() => resolveModelFile(root, 'readme.md'), /ending in .kk/);
});
