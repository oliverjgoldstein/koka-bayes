import assert from 'node:assert/strict';
import { mkdtempSync, rmSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import path from 'node:path';
import { spawnSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';
import test from 'node:test';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const runner = path.join(root, 'scripts', 'project.mjs');

function run(file, cwd) {
  return spawnSync(process.execPath, [runner, 'run', file], {
    cwd, encoding: 'utf8', timeout: 120_000, maxBuffer: 8 * 1024 * 1024,
  });
}

// A standalone user file deliberately has no module declaration or completion marker.
function coin(data, inference) {
  return `import bayes
val flip = obs-bool("flip")
val data = [${data}]
fun coin-model() : model<e,float64>
  fn(){
    val p = beta'(1.0, 1.0)
    for(data.length) fn(_){ val _ = bernoulli(flip, p); () }
    p
  }
pub fun main()
  val observations = set(flip, data, empty())
  val posterior = ${inference}
  println("My result: " ++ posterior-mean(posterior).show)
`;
}

test('a single copied file can change its data and inference method and run from outside the project', context => {
  const directory = mkdtempSync(path.join(tmpdir(), 'standalone model with spaces '));
  context.after(() => rmSync(directory, { recursive: true, force: true }));
  const file = path.join(directory, 'my_coin.kk');
  const check = (result, minimum, maximum) => {
    assert.equal(result.error, undefined);
    assert.equal(result.status, 0, result.stdout + result.stderr);
    const match = result.stdout.match(/^My result: ([^\r\n]+)$/m);
    assert.ok(match, result.stdout);
    const estimate = Number(match[1]);
    assert.ok(estimate > minimum && estimate < maximum, String(estimate));
  };
  writeFileSync(file, coin('True, True, True, True, True, True, True, True',
    'likelihood-weighting(1500, observations, coin-model(), seed=2027)'));
  check(run('my_coin.kk', directory), 0.8, 1.0);
  writeFileSync(file, coin('False, False, False, False, False, False, False, False',
    'metropolis-hastings(2000, 300, observations, coin-model(), seed=2027)'));
  check(run(file, directory), 0.0, 0.2);
});

test('a model runtime exception or compile error makes the runner fail', context => {
  const directory = mkdtempSync(path.join(tmpdir(), 'failing model '));
  context.after(() => rmSync(directory, { recursive: true, force: true }));
  const file = path.join(directory, 'broken_model.kk');
  writeFileSync(file, 'pub fun main() { throw("intentional model failure") }\n');
  const runtime = run(file, directory);
  assert.equal(runtime.error, undefined);
  assert.notEqual(runtime.status, 0, runtime.stdout + runtime.stderr);
  assert.match(runtime.stderr, /intentional model failure/);
  assert.match(runtime.stderr, /broken_model\.kk/);
  writeFileSync(file, 'pub fun main() { this-is-not-defined() }\n');
  const compile = run(file, directory);
  assert.equal(compile.error, undefined);
  assert.notEqual(compile.status, 0, compile.stdout + compile.stderr);
});
