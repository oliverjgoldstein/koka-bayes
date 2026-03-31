module core/env

import core/obsvalue
import core/obsvar

struct env-entry
  name   : string
  values : list<observable>

pub struct env
  entries : list<env-entry>

pub fun empty() : env
  Env([])

pub fun singleton(v : obsvar<a>, values : list<a>) : env
  set(v, values, empty())

pub fun set(v : obsvar<a>, values : list<a>, environment : env) : env
  Env(set-raw(v.name, encode-all(v.codec, values), environment.entries))

pub fun append(v : obsvar<a>, value : a, environment : env) : env
  append-raw(v.name, encode-value(v.codec, value), environment)

pub fun append-raw(key : string, value : observable, environment : env) : env
  Env(append-raw-entry(key, value, environment.entries))

pub fun merge(left : env, right : env) : env
  right.entries.foldl(left, fn(acc, entry){ merge-entry(acc, entry) })

pub fun get(v : obsvar<a>, environment : env) : list<a>
  decode-all(v.codec, lookup-raw(v.name, environment.entries))

// Focus a sequential environment on one time step. Singleton entries are
// treated as global bindings and preserved as-is.
pub fun focus-step(index : int, environment : env) : env
  Env(environment.entries.flatmap(fn(entry){
    match focus-values(index, entry.values)
      Nil -> []
      values1 -> [Env-entry(entry.name, values1)]
  }))

// Trim a sequential environment to a prefix of the supplied step count.
// Singleton entries are treated as global bindings and preserved as-is.
pub fun take-prefix(limit : int, environment : env) : env
  Env(environment.entries.flatmap(fn(entry){
    match prefix-values(limit, entry.values)
      Nil -> []
      values1 -> [Env-entry(entry.name, values1)]
  }))

pub fun maybe-consume(v : obsvar<a>, environment : env) : (maybe<a>, env)
  val (found, entries1) = consume-raw(v.name, environment.entries)
  match found
    Nothing -> (Nothing, Env(entries1))
    Just(value0) ->
      match decode-value(v.codec, value0)
        Just(value) -> (Just(value), Env(entries1))
        Nothing     -> (Nothing, Env(entries1))

pub fun maybe-consume-name(key : string, environment : env) : (maybe<observable>, env)
  val (found, entries1) = consume-raw(key, environment.entries)
  (found, Env(entries1))

pub fun show(environment : env) : string
  "[" ++ show-entries(environment.entries) ++ "]"

fun encode-all(codec : codec<a>, values : list<a>) : list<observable>
  values.map(fn(value){ encode-value(codec, value) })

fun decode-all(codec : codec<a>, values : list<observable>) : list<a>
  values.flatmap(fn(value){
    match decode-value(codec, value)
      Just(x) -> [x]
      Nothing -> []
  })

fun show-entry(entry : env-entry) : string
  entry.name ++ "=" ++ "[" ++ entry.values.map(show-obsvalue).join(", ") ++ "]"

fun show-entries(entries : list<env-entry>) : string
  entries.map(show-entry).join(", ")

fun lookup-raw(key : string, entries : list<env-entry>) : list<observable>
  match entries
    Nil -> []
    Cons(entry, rest) ->
      if entry.name == key
        then entry.values
        else lookup-raw(key, rest)

fun merge-entry(environment : env, entry : env-entry) : env
  entry.values.foldl(environment, fn(acc, value){ append-raw(entry.name, value, acc) })

fun set-raw(key : string, values : list<observable>, entries : list<env-entry>) : list<env-entry>
  match entries
    Nil -> [Env-entry(key, values)]
    Cons(entry, rest) ->
      if entry.name == key
        then Cons(Env-entry(key, values), rest)
        else Cons(entry, set-raw(key, values, rest))

fun append-raw-entry(key : string, value : observable, entries : list<env-entry>) : list<env-entry>
  match entries
    Nil -> [Env-entry(key, [value])]
    Cons(entry, rest) ->
      if entry.name == key
        then Cons(Env-entry(key, entry.values ++ [value]), rest)
        else Cons(entry, append-raw-entry(key, value, rest))

fun consume-raw(key : string, entries : list<env-entry>) : (maybe<observable>, list<env-entry>)
  match entries
    Nil -> (Nothing, [])
    Cons(entry, rest) ->
      if entry.name == key
        then
          match entry.values
            Nil -> (Nothing, Cons(entry, rest))
            Cons(value, values1) -> (Just(value), Cons(Env-entry(key, values1), rest))
        else
          val (found, rest1) = consume-raw(key, rest)
          (found, Cons(entry, rest1))

fun focus-values(index : int, values : list<observable>) : list<observable>
  if values.length <= 1
    then values
    else
      match nth-observable(index, values)
        Just(value) -> [value]
        Nothing     -> []

fun prefix-values(limit : int, values : list<observable>) : list<observable>
  if values.length <= 1
    then values
    else take-observables(max(0, limit), values)

fun nth-observable(index : int, values : list<observable>) : maybe<observable>
  match values
    Nil -> Nothing
    Cons(value, rest) ->
      if index <= 0
        then Just(value)
        else nth-observable(index - 1, rest)

fun take-observables(limit : int, values : list<observable>) : list<observable>
  if limit <= 0
    then []
    else
      match values
        Nil -> []
        Cons(value, rest) -> Cons(value, take-observables(limit - 1, rest))
