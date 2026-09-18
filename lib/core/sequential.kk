module core/sequential

import core/model
import handlers/sequential

pub struct step-output<s,o>
  state       : s
  observation : o

pub struct prefix-output<p,s,o>
  parameter     : p
  current-state : s
  states        : list<s>
  observations  : list<o>

pub struct sequential-model<e,p,s,o,a>
  prior   : model<e,p>
  initial : p -> <obs-reader,model-dist,div|e> s
  step    : (p, int, s) -> <obs-reader,model-dist,div|e> step-output<s,o>
  finish  : prefix-output<p,s,o> -> a

pub fun prefix-model<p,s,o,a,e>(steps : int, spec : sequential-model<e,p,s,o,a>) : model<e,prefix-output<p,s,o>>
  fn(){
    val parameter = prior(spec)()
    prefix-run(steps, parameter, spec)
  }

pub fun prefix-model-given<p,s,o,a,e>(steps : int, parameter : p, spec : sequential-model<e,p,s,o,a>) : model<e,prefix-output<p,s,o>>
  fn(){ prefix-run(steps, parameter, spec) }

pub fun as-model<p,s,o,a,e>(steps : int, spec : sequential-model<e,p,s,o,a>) : model<e,a>
  fn(){
    val prefix-state = prefix-model(steps, spec)()
    finish(spec)(prefix-state)
  }

pub fun as-model-given<p,s,o,a,e>(steps : int, parameter : p, spec : sequential-model<e,p,s,o,a>) : model<e,a>
  fn(){
    val prefix-state = prefix-model-given(steps, parameter, spec)()
    finish(spec)(prefix-state)
  }

pub fun prefix-run<p,s,o,a,e>(steps : int, parameter : p, spec : sequential-model<e,p,s,o,a>) : <obs-reader,model-dist,div|e> prefix-output<p,s,o>
  run-sequential(fn(){ checkpointed-prefix(steps, parameter, spec) })

// Expose the same sequential model as a resumable effectful computation. The
// first checkpoint follows initialization; each later one follows a model step.
// The ordinary prefix API uses the handler that runs every checkpoint to completion.
pub fun checkpointed-prefix<p,s,o,a,e>(steps : int, parameter : p, spec : sequential-model<e,p,s,o,a>) : <checkpoint,obs-reader,model-dist,div|e> prefix-output<p,s,o>
  val start = mask<checkpoint>{ initial(spec)(parameter) }
  checkpoint()
  run-steps(max(0, steps), parameter, spec, 0, start, [], [])

fun run-steps<p,s,o,a,e>(remaining : int,
                             parameter : p,
                             spec : sequential-model<e,p,s,o,a>,
                             index : int,
                             current : s,
                             states : list<s>,
                             observations : list<o>) : <checkpoint,obs-reader,model-dist,div|e> prefix-output<p,s,o>
  if remaining <= 0
    then Prefix-output(parameter, current, states, observations)
    else
      val step1 = mask<checkpoint>{ step(spec)(parameter, index, current) }
      checkpoint()
      run-steps(remaining - 1,
                parameter,
                spec,
                index + 1,
                step1.state,
                states ++ [step1.state],
                observations ++ [step1.observation])
