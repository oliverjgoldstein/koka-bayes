Daan questions:
Not setting optinline produces same errors as before

Setting it as optinline=10 gives the folowing:
```
Running Importance Sampling...
/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/main2.js:34
  var hist_166 = $sampling.importance__sampling($model_dash_resources.sequential__gaussian(3.0));
                                                ^

ReferenceError: $model_dash_resources is not defined
    at main (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/main2.js:34:49)
    at Object.<anonymous> (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/main2.js:48:1)
    at runFactory (/Users/joosko/work/studies/fmf/phd/koka/koka/node_modules/amdefine/amdefine.js:183:30)
    at define (/Users/joosko/work/studies/fmf/phd/koka/koka/node_modules/amdefine/amdefine.js:277:13)
    at Object.<anonymous> (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/main2.js:3:1)
    at Module._compile (internal/modules/cjs/loader.js:1200:30)
    at Object.Module._extensions..js (internal/modules/cjs/loader.js:1220:10)
    at Module.load (internal/modules/cjs/loader.js:1049:32)
    at Function.Module._load (internal/modules/cjs/loader.js:937:14)
    at Function.executeUserEntryPoint [as runMain] (internal/modules/run_main.js:71:12)
failure while running program:
  node ../../../../koka/koka/out/koka-bayes-output/main2.js

(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: cannot unify (NoMatch)
                      std/core/types/maybe<a>
                   =~ std/core/types/maybe<std/core/types/maybe<a>>
                 when comparing formal and actual argument
                   std/core/hnd/cast-ev2(std/core/([].2))
                 TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TVar (TypeVar {typevarId = 3, typevarKind = KCon V, typevarFlavour = Bound})]
TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TVar (TypeVar {typevarId = 3, typevarKind = KCon V, typevarFlavour = Bound})]]
 in definition: (x, exn-get/exn-get)
 private val x : std/core/types/maybe<a>;
(1, 0): warning: cannot unify (NoMatch)
                      std/core/types/maybe<a>
                   =~ std/core/types/maybe<std/core/types/maybe<a>>
                 when comparing formal and actual argument
                   std/core/hnd/cast-ev2(std/core/([].2))
                 TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TVar (TypeVar {typevarId = 3, typevarKind = KCon V, typevarFlavour = Bound})]
TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TVar (TypeVar {typevarId = 3, typevarKind = KCon V, typevarFlavour = Bound})]]
 in definition: (x, exn-get/exn-get)
 private val x : std/core/types/maybe<a>;
(1, 0): warning: cannot unify (NoMatch)
                      std/core/types/maybe<a>
                   =~ std/core/types/maybe<std/core/types/maybe<a>>
                 when comparing formal and actual argument
                   std/core/hnd/cast-ev2(std/core/([].2))
                 TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TVar (TypeVar {typevarId = 3, typevarKind = KCon V, typevarFlavour = Bound})]
TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TVar (TypeVar {typevarId = 3, typevarKind = KCon V, typevarFlavour = Bound})]]
 in definition: (x, exn-get/exn-get)
 private val x : std/core/types/maybe<a>;
(1, 0): warning: cannot unify (NoMatch)
                      std/core/types/maybe<a>
                   =~ std/core/types/maybe<std/core/types/maybe<a>>
                 when comparing formal and actual argument
                   std/core/hnd/cast-ev2(std/core/([].2))
                 TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TVar (TypeVar {typevarId = 3, typevarKind = KCon V, typevarFlavour = Bound})]
TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TApp (TCon (TypeCon {typeconName = std/core/types/maybe, typeconKind = KApp (KApp (KCon (->)) (KCon V)) (KCon V)})) [TVar (TypeVar {typevarId = 3, typevarKind = KCon V, typevarFlavour = Bound})]]
 in definition: (x, exn-get/exn-get)
 private val x : std/core/types/maybe<a>;
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
```

Seeting it to 2
````
Here once again
Running Importance Sampling...
/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/main2.js:18
  var hist_166 = $sampling.importance__sampling($model_dash_resources.sequential__gaussian(3.0));
                                                ^

ReferenceError: $model_dash_resources is not defined
    at main (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/main2.js:18:49)
    at Object.<anonymous> (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/main2.js:24:1)
    at runFactory (/Users/joosko/work/studies/fmf/phd/koka/koka/node_modules/amdefine/amdefine.js:183:30)
    at define (/Users/joosko/work/studies/fmf/phd/koka/koka/node_modules/amdefine/amdefine.js:277:13)
    at Object.<anonymous> (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/main2.js:3:1)
    at Module._compile (internal/modules/cjs/loader.js:1200:30)
    at Object.Module._extensions..js (internal/modules/cjs/loader.js:1220:10)
    at Module.load (internal/modules/cjs/loader.js:1049:32)
    at Function.Module._load (internal/modules/cjs/loader.js:937:14)
    at Function.executeUserEntryPoint [as runMain] (internal/modules/run_main.js:71:12)
failure while running program:
  node ../../../../koka/koka/out/koka-bayes-output/main2.js

(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
(1, 0): warning: expecting function type in application
````

Setting it to 1 or 0:
```
Here once again
Running Importance Sampling...
/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/model_dash_resources.js:78
  return $std_core_hnd.yield_bind($effects_dash_and_dash_types.sample(), function(_y_8 /* std/core/types/double */ ) {
                                  ^

ReferenceError: $effects_dash_and_dash_types is not defined
    at standard_normal (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/model_dash_resources.js:78:35)
    at normal (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/model_dash_resources.js:85:35)
    at Object._open_at2 (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/std_core_hnd.js:598:13)
    at /Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/model_dash_resources.js:314:65
    at Object.yield_bind (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/std_core_hnd.js:763:12)
    at /Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/model_dash_resources.js:313:36
    at Object._lift22808_for (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/std_core.js:4342:37)
    at /Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/model_dash_resources.js:312:51
    at /Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/std_core_hnd.js:1004:15
    at Object.local_var (/Users/joosko/work/studies/fmf/phd/koka/koka/out/koka-bayes-output/std_core_hnd.js:1006:6)
failure while running program:
  node ../../../../koka/koka/out/koka-bayes-output/main2.js
```

