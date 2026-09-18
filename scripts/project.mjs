#!/usr/bin/env node
import { existsSync, mkdirSync, readFileSync, readdirSync, realpathSync, statSync, writeFileSync } from 'node:fs';
import path from 'node:path';
import { spawnSync } from 'node:child_process';
import { createHash } from 'node:crypto';
import { fileURLToPath, pathToFileURL } from 'node:url';

const projectRoot = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');

export function parseVersion(output) {
  return output.match(/^(?:version:\s*|Koka\s+|v?)(\d+\.\d+\.\d+(?:-[a-zA-Z0-9.-]+)?)(?:[,\s]|$)/m)?.[1] ?? null;
}

export function assertCompleted(output, marker, exitCode) {
  if (exitCode !== 0) throw new Error(`Command failed (exit ${exitCode ?? 'unknown'}).`);
  if (/^\s*uncaught exception:/m.test(output)) throw new Error('Koka reported an uncaught exception.');
  if (marker && !output.split(/\r?\n/).some(line => line.trim() === marker)) {
    throw new Error(`Missing completion marker: ${marker}`);
  }
}

// A completion marker alone cannot establish coverage: every declared
// algorithm/model/seed cell must actually report a finite passing measurement.
export function assertExampleCoverage(output, family, algorithms, models, seeds) {
  const expected = new Set(algorithms.flatMap(algorithm => models.flatMap(model =>
    seeds.map(seed => `${model},${algorithm},${seed}`))));
  const seen = new Set();
  for (const line of output.split(/\r?\n/).filter(line => line.startsWith('example,'))) {
    const [prefix, actualFamily, model, algorithm, seed, ratio, status, ...extra] = line.split(',');
    const key = `${model},${algorithm},${seed}`;
    if (actualFamily !== family || extra.length || !expected.has(key) || seen.has(key)) {
      throw new Error(`Unexpected or duplicate example result: ${line}`);
    }
    if (!ratio?.trim() || !Number.isFinite(Number(ratio)) || Number(ratio) < 0 || Number(ratio) > 1 || status !== 'PASS') {
      throw new Error(`Example did not meet its declared tolerance: ${line}`);
    }
    seen.add(key);
  }
  if (seen.size !== expected.size) {
    throw new Error(`Incomplete ${family} example matrix: ${seen.size}/${expected.size} cells reported.`);
  }
}

export function toolPaths(root, platform = process.platform) {
  return {
    node: path.join(root, '.tools', 'node', ...(platform === 'win32' ? ['node.exe'] : ['bin', 'node'])),
    koka: path.join(root, '.tools', 'koka', 'bin', platform === 'win32' ? 'koka.exe' : 'koka'),
  };
}

export function collectModules(root) {
  const visit = directory => readdirSync(path.join(root, directory), { withFileTypes: true })
    .sort((a, b) => a.name.localeCompare(b.name, 'en'))
    .flatMap(entry => {
      const relative = `${directory}/${entry.name}`;
      return entry.isDirectory() ? visit(relative) : entry.isFile() && entry.name.endsWith('.kk') ? [relative] : [];
    });
  return [...visit('lib'), ...visit('examples'), 'model.kk'].sort();
}

export function parseCommand(args, environment = process.env) {
  const requested = args[0] ?? 'run';
  const command = requested === 'inference' ? 'run' : requested;
  if (command === 'run') {
    if (args.length > 2) throw new Error(`Usage: bayes ${requested} [model.kk]`);
    const configured = requested === 'inference' ? environment.KOKA_BAYES_MODEL : undefined;
    return { command, file: args[1] ?? configured ?? 'model.kk', explicitFile: args.length === 2 || configured !== undefined };
  }
  if (args.length > 1) throw new Error(`Unexpected arguments after ${command}. Run bayes help.`);
  return { command };
}

export function resolveModelFile(root, file, base = root) {
  const resolved = path.resolve(base, file);
  if (path.extname(resolved).toLowerCase() !== '.kk') throw new Error('Choose a Koka model file ending in .kk.');
  if (!existsSync(resolved) || !statSync(resolved).isFile()) throw new Error(`Model file not found: ${resolved}`);
  return resolved;
}

function modelSource(file) {
  const source = readFileSync(file, 'utf8');
  const declared = source.match(/^\s*module\s+([\w/-]+)/m)?.[1];
  if (declared) {
    const parents = Array(declared.split('/').length - 1).fill('..');
    return { file, includes: [path.resolve(path.dirname(file), ...parents)] };
  }
  if (/^[a-z][a-z0-9]*\.kk$/.test(path.basename(file))) return { file, includes: [path.dirname(file)] };

  // Koka infers `my/coin` from a headerless `my_coin.kk`. Compile an unchanged
  // copy under a stable safe name so users can freely name a single model file.
  const directory = path.join(projectRoot, '.koka', 'models');
  mkdirSync(directory, { recursive: true });
  const name = `user${createHash('sha256').update(file).digest('hex').slice(0, 20)}.kk`;
  const staged = path.join(directory, name);
  if (!existsSync(staged) || readFileSync(staged, 'utf8') !== source) writeFileSync(staged, source);
  return { file: staged, includes: [path.dirname(file), directory] };
}

const suites = {
  smoke: ['tests/smoke.kk', 'smoke checks passed'],
  'finite-support': ['tests/finite_support.kk', 'Finite support checks passed.'],
  enumeration: ['tests/enumeration_checks.kk', 'Finite enumeration checks passed.'],
  'inference-regressions': ['tests/inference_regressions.kk', 'inference regression checks passed'],
  'inference-audit': ['tests/inference_audit.kk', 'inference audit passed: exact joint marginals, asymmetric kernels, rejection, particle evidence'],
  'sir-inference': ['tests/sir_inference.kk', 'SIR inference checks passed.'],
  'sir-report-checks': ['tests/sir_report_checks.kk', 'SIR report checks passed.'],
  'smc-regressions': ['tests/smc_incremental.kk', 'incremental SMC regression checks passed'],
  'rmsmc-handlers': ['tests/handler_composition_rmsmc.kk', 'RMSMC handler composition checks passed.'],
  'pmmh-handlers': ['tests/handler_composition_pmmh.kk', 'PMMH handler composition checks passed.'],
  'smc2-handlers': ['tests/handler_composition_smc2.kk', 'SMC2 handler composition checks passed.'],
  'handler-multishot': ['tests/handler_multishot.kk', 'Multi-shot handler checks passed.'],
  'handler-laws': ['tests/handler_laws.kk', 'Handler scoring laws passed.'],
  'sequential-observations': ['tests/sequential_observations.kk', 'Sequential observation stream checks passed.'],
  'inference-transformations': ['tests/inference_transformations.kk', 'Inference transformation checks passed.'],
  'handler-smc': ['tests/handler_smc_checks.kk', 'Checkpoint SMC checks passed.'],
  benchmark: ['tests/correctness.kk', 'inference correctness checks passed (30 runs; 3 fixed seeds per model/algorithm)'],
  'autodiff-test': ['tests/autodiff_checks.kk', 'autodiff checks passed: analytic values/gradients, sharing, Gaussian density, finite differences, isolation'],
  'gradient-tests': ['tests/gradient_samplers.kk', 'Gradient inference checks passed.'],
  'differentiable-model': ['tests/differentiable_model.kk', 'Differentiable model checks passed.'],
  'model-api': ['tests/model_api.kk', 'Model API tests passed.'],
  'trace-examples': ['tests/trace_examples.kk', 'Trace example matrix passed (36 runs).'],
  'particle-examples': ['tests/particle_examples.kk', 'Particle example matrix passed (45 runs).'],
  'gradient-examples': ['tests/gradient_examples.kk', 'Gradient example matrix passed (18 runs).'],
};

const exampleMatrices = {
  'trace-examples': ['trace', ['simulate', 'LW', 'LWIS', 'MH'],
    ['beta-binomial', 'gamma-poisson', 'finite-mixture'], [1301, 1303, 1307]],
  'particle-examples': ['particle', ['SMC', 'RMSMC', 'PMMH', 'SMC2', 'checkpoint-SMC'],
    ['classification', 'hidden-process', 'sensor-calibration'], [3011, 3023, 3037]],
  'gradient-examples': ['gradient', ['HMC', 'MALA'],
    ['thermometer', 'linear-regression', 'logistic-intercept'], [1201, 1213, 1217]],
};

const algorithmSuites = {
  'test-lw': 'LW inference checks passed (6 runs).',
  'test-lwis': 'LWIS inference checks passed (6 runs).',
  'test-mh': 'MH inference checks passed (6 runs).',
  'test-smc': 'SMC inference checks passed (3 runs).',
  'test-rmsmc': 'RMSMC inference checks passed (3 runs).',
  'test-pmmh': 'PMMH inference checks passed (3 runs).',
  'test-smc2': 'SMC2 inference checks passed (3 runs).',
  'test-hmc': 'HMC gradient inference checks passed (3 posterior runs).',
  'test-mala': 'MALA gradient inference checks passed (3 posterior runs).',
};

export function main(args = process.argv.slice(2)) {
  const request = parseCommand(args);
  const { command } = request;
  const tools = toolPaths(projectRoot);
  const canonical = file => {
    const real = realpathSync(file);
    return process.platform === 'win32' ? real.toLowerCase() : real;
  };
  if (existsSync(tools.node) && canonical(process.execPath) !== canonical(tools.node)) {
    const rerun = spawnSync(tools.node, [fileURLToPath(import.meta.url), ...args], { stdio: 'inherit' });
    if (rerun.error) throw rerun.error;
    return rerun.status ?? 1;
  }
  if (command === 'help' || command === '--help') {
    console.log('Edit model.kk: model, data, inference, and results live together.');
    console.log('Start: make setup, then make inference. Test one method: make test-mh.');
    console.log('bayes                          Run model.kk');
    console.log('bayes run examples/temperature.kk  Run the thermometer example');
    console.log('bayes check                    Compile, test, and run the starter models');
    console.log('bayes examples                 Demonstrate sampling methods and finite enumeration');
    console.log('bayes example-matrix           Check sampling methods on three models and three seeds');
    console.log('bayes test-enumerate           Check finite supports, exact posteriors and composition');
    console.log('bayes test-sir                 Check a small exact SIR posterior and report summaries');
    console.log('bayes demo-enumerate           Run three finite enumeration examples');
    console.log('bayes demo-hmc                 Run one demonstration (also demo-mala, demo-lw, etc.)');
    console.log('More checks: test, inference-tests, handler-composition, benchmark, gradient-tests, autodiff, compile, doctor');
    return 0;
  }

  const expectedNode = readFileSync(path.join(projectRoot, '.node-version'), 'utf8').trim();
  const expectedKoka = readFileSync(path.join(projectRoot, '.koka-version'), 'utf8').trim();
  const koka = process.env.KOKA || (existsSync(tools.koka) ? tools.koka : 'koka');
  const env = { ...process.env, PATH: [path.dirname(process.execPath), path.dirname(tools.koka), process.env.PATH ?? ''].join(path.delimiter) };
  // Explicit project-local output avoids Koka falling back to a home-directory cache.
  const baseFlags = ['--target=jsnode', '--console=raw', '--verbose=0', '--include=lib', '--include=.', '--include=tests', `--builddir=${path.join(projectRoot, '.koka')}`];
  const logDirectory = path.join(projectRoot, '.koka', 'logs');
  mkdirSync(logDirectory, { recursive: true });

  function execute(label, executable, arguments_, marker = null, showOutput = false, source = null) {
    // The x64 GHC runtime runs under emulation on Windows ARM64. Use one
    // capability there; this does not change the native Node execution target.
    const commandArguments = executable === koka && process.platform === 'win32' && process.arch === 'arm64'
      ? ['+RTS', '-N1', '-RTS', ...arguments_] : arguments_;
    const result = spawnSync(executable, commandArguments, {
      cwd: projectRoot, env, encoding: 'utf8', maxBuffer: 32 * 1024 * 1024,
      // The full posterior audit can exceed 10 minutes on hosted Intel Macs.
      timeout: (label === 'inference-audit' ? 20 : 10) * 60 * 1000, windowsHide: true,
    });
    const output = `${result.stdout ?? ''}${result.stderr ?? ''}`;
    const log = path.join(logDirectory, `${label.replace(/[^a-zA-Z0-9_-]/g, '_')}.log`);
    writeFileSync(log, output);
    try {
      if (result.error) throw result.error;
      assertCompleted(output, marker, result.status);
    } catch (error) {
      let diagnostic = output.split(/\r?\n/).slice(-60).join('\n');
      if (source) {
        diagnostic = diagnostic.replaceAll(source.compiled, source.original)
          .replaceAll(path.basename(source.compiled), path.basename(source.original));
        console.error(`Model: ${source.original}`);
      }
      console.error(diagnostic);
      throw new Error(`${label}: ${error.message}\nFull log: ${log}`);
    }
    if (showOutput) {
      // Quiet compilation keeps the user's output intact, including arbitrary headings.
      process.stdout.write(result.stdout ?? '');
    }
    return output;
  }

  function doctor(announce = true) {
    if (parseVersion(process.version) !== expectedNode) {
      throw new Error(`Node ${expectedNode} is required; found ${process.version}. Run the setup script for your platform.`);
    }
    const version = parseVersion(execute('koka-version', koka, ['--version']));
    if (version !== expectedKoka) throw new Error(`Koka ${expectedKoka} is required; found ${version ?? 'unknown'}. Run setup.`);
    if (announce) console.log(`Koka ${version}; Node ${expectedNode}; ${process.platform}/${process.arch}`);
  }
  function compile() {
    const modules = collectModules(projectRoot);
    console.log(`Compiling ${modules.length} library and model files...`);
    for (const module of modules) {
      if (module.startsWith('lib/')) execute(`compile-${module}`, koka, [...baseFlags, '--library', '-c', module]);
      else {
        const original = path.join(projectRoot, module);
        const source = modelSource(original);
        execute(`compile-${module}`, koka, [...baseFlags, ...source.includes.map(directory => `--include=${directory}`), '-c', source.file],
          null, false, { compiled: source.file, original });
      }
    }
    console.log('Compilation passed.');
  }
  function suite(name, show = false) {
    const [file, marker] = suites[name];
    console.log(`Checking ${name}...`);
    const output = execute(name, koka, [...baseFlags, '-e', file], marker, show);
    if (Object.hasOwn(exampleMatrices, name)) assertExampleCoverage(output, ...exampleMatrices[name]);
    console.log(`${name}: passed.`);
  }
  function algorithmSuite(name) {
    console.log(`Checking ${name.slice(5).toUpperCase()} inference...`);
    const file = ['test-hmc', 'test-mala'].includes(name) ? 'tests/gradient_samplers.kk' : 'tests/correctness.kk';
    execute(name, koka, [...baseFlags, `--main-entry=${name}`, '-e', file], algorithmSuites[name], true);
  }
  function test() {
    execute('runner-tests', process.execPath, ['--test', '--test-concurrency=1', 'tests/runner.test.mjs', 'tests/workflow.test.mjs']);
    for (const name of Object.keys(suites)) suite(name);
    console.log('All tests passed (finite enumeration, 36 baseline inference benchmark runs, 99 multi-model runs, 27 joint-posterior comparisons, plus SIR, regression, model-handler and AD checks).');
  }
  function runFile(file, { base = projectRoot, marker = null, entry = 'main' } = {}) {
    const resolved = resolveModelFile(projectRoot, file, base);
    const source = modelSource(resolved);
    execute(`run-${path.relative(projectRoot, resolved)}`, koka,
      [...baseFlags, ...source.includes.map(directory => `--include=${directory}`), `--main-entry=${entry}`, '-e', source.file],
      marker, true, { compiled: source.file, original: resolved });
  }
  function examples() {
    runFile('examples/exact_inference.kk', { marker: 'Finite enumeration examples passed.' });
    runFile('examples/inference.kk', { marker: 'Finite inference budgets produce approximate posterior estimates.' });
    runFile('examples/gradient_inference.kk', { marker: 'Gradient inference examples completed.' });
    runFile('examples/compositional_inference.kk', { marker: 'Compositional inference example passed.' });
  }

  doctor(command !== 'run');
  if (command === 'doctor') return 0;
  if (command === 'compile') compile();
  else if (command === 'test') test();
  else if (command === 'correctness' || command === 'benchmark') suite('benchmark', true);
  else if (command === 'inference-tests') { suite('benchmark', true); suite('gradient-tests', true); }
  else if (command === 'test-enumerate') { suite('finite-support', true); suite('enumeration', true); }
  else if (command === 'test-sir') { suite('sir-report-checks', true); suite('sir-inference', true); }
  else if (command === 'example-matrix') {
    for (const name of Object.keys(exampleMatrices)) suite(name, true);
    console.log('Multi-model validation passed (90 posterior runs and 9 simulation runs).');
  }
  else if (command === 'handler-composition') {
    for (const name of ['rmsmc-handlers', 'pmmh-handlers', 'smc2-handlers', 'handler-multishot', 'handler-laws', 'sequential-observations', 'inference-transformations', 'handler-smc']) suite(name, true);
  }
  else if (Object.hasOwn(algorithmSuites, command)) algorithmSuite(command);
  else if (Object.hasOwn(suites, command)) suite(command);
  else if (command === 'run') runFile(request.file, { base: request.explicitFile ? process.cwd() : projectRoot });
  else if (command === 'autodiff') runFile('examples/autodiff.kk');
  else if (command === 'examples') examples();
  else if (command === 'check') {
    compile(); test();
    runFile('model.kk');
    runFile('examples/gaussian.kk');
    runFile('examples/temperature.kk', { marker: 'Room temperature from noisy thermometer readings' });
    runFile('examples/autodiff.kk', { marker: 'This example optimizes a log density; it does not draw posterior samples.' });
    examples();
    console.log('End-to-end check passed.');
  } else {
    // Existing shortcuts still select an entry function in the model file.
    const demos = {
      'linear-regression': ['examples/linear_regression.kk', 'main'],
      hmm: ['examples/hmm.kk', 'main'],
      'sir-simulate': ['examples/sir.kk', 'run-sir-simulate'],
      'sir-infer': ['examples/sir.kk', 'run-sir-infer'],
      'sir-bootstrap': ['examples/sir.kk', 'run-sir-bootstrap'],
      'sir-report': ['examples/sir_report.kk', 'main'],
      'demo-lw': ['examples/inference.kk', 'run-lw'],
      'demo-lwis': ['examples/inference.kk', 'run-lwis'],
      'demo-mh': ['examples/inference.kk', 'run-mh'],
      'demo-smc': ['examples/inference.kk', 'run-smc'],
      'demo-rmsmc': ['examples/inference.kk', 'run-rmsmc'],
      'demo-pmmh': ['examples/inference.kk', 'run-pmmh'],
      'demo-smc2': ['examples/inference.kk', 'run-smc2'],
      'demo-hmc': ['examples/gradient_inference.kk', 'run-hmc'],
      'demo-mala': ['examples/gradient_inference.kk', 'run-mala'],
      'demo-handlers': ['examples/compositional_inference.kk', 'main'],
      'demo-enumerate': ['examples/exact_inference.kk', 'main'],
    };
    if (!Object.hasOwn(demos, command)) throw new Error(`Unknown command: ${command}. Run bayes help.`);
    const [file, entry] = demos[command];
    runFile(file, { entry });
  }
  return 0;
}

if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) {
  try { process.exitCode = main(); }
  catch (error) { console.error(error.message); process.exitCode = 1; }
}
