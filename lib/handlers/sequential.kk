module handlers/sequential

// A checkpoint saves the rest of the computation without evaluating it.
// Resuming the saved continuation reinstalls this handler and stops at the next
// checkpoint. Effects in `e` retain the semantics of their enclosing handlers.
pub effect checkpoint
  ctl checkpoint() : ()

pub type suspension<e,a>
  Completed(value : a)
  Suspended(next : () -> e suspension<e,a>)

pub fun suspend<a,e>(action : () -> <checkpoint|e> a) : e suspension<e,a>
  handle(action)
    return(value) Completed(value)
    ctl checkpoint() Suspended(fn(){ resume(()) })

pub fun advance<a,e>(state : suspension<e,a>) : e suspension<e,a>
  match state
    Completed(_) -> state
    Suspended(next) -> next()

pub fun complete<a,e>(state : suspension<<div|e>,a>) : <div|e> a
  match state
    Completed(value) -> value
    Suspended(next) -> complete(next())

pub fun run-sequential<a,e>(action : () -> <checkpoint,div|e> a) : <div|e> a
  complete(suspend(action))
