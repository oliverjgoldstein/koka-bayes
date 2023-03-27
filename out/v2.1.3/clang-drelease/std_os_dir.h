#pragma once
#ifndef kk_std_os_dir_H
#define kk_std_os_dir_H
// Koka generated module: "std/os/dir", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_os_path.h"

// type declarations

// value declarations

kk_std_core__exception kk_std_os_dir_prepend(kk_std_core__exception exn, kk_string_t pre, kk_context_t* _ctx); /* (exn : exception, pre : string) -> exception */ 

kk_std_core__error kk_std_os_dir_prim_copy_file(kk_string_t from, kk_string_t to, bool preserve_mtime, kk_context_t* _ctx); /* (from : string, to : string, preserve-mtime : bool) -> fsys error<()> */ 

kk_std_core__error kk_std_os_dir_ensure_dir_err(kk_string_t path, kk_integer_t mode, kk_context_t* _ctx); /* (path : string, mode : int) -> fsys error<()> */ 

bool kk_std_os_dir_prim_is_dir(kk_string_t dir, kk_context_t* _ctx); /* (dir : string) -> fsys bool */ 

kk_std_core__error kk_std_os_dir_prim_list_dir(kk_string_t dir, kk_context_t* _ctx); /* (dir : string) -> fsys error<vector<string>> */ 

bool kk_std_os_dir_prim_is_file(kk_string_t path, kk_context_t* _ctx); /* (path : string) -> fsys bool */ 

kk_unit_t kk_std_os_dir_copy_file(kk_std_os_path__path from, kk_std_os_path__path to, kk_std_core_types__optional preserve_mtime, kk_context_t* _ctx); /* (from : std/os/path/path, to : std/os/path/path, preserve-mtime : optional<bool>) -> <exn,fsys> () */ 

kk_unit_t kk_std_os_dir_ensure_dir(kk_std_os_path__path dir, kk_context_t* _ctx); /* (dir : std/os/path/path) -> <exn,fsys> () */ 
 
// Is the path a valid directory?

static inline bool kk_std_os_dir_is_directory(kk_std_os_path__path dir, kk_context_t* _ctx) { /* (dir : std/os/path/path) -> fsys bool */ 
  kk_string_t _x1888 = kk_std_os_path_string(dir, _ctx); /*string*/
  return kk_std_os_dir_prim_is_dir(_x1888, _ctx);
}

kk_std_core__list kk_std_os_dir_list_directory(kk_std_os_path__path dir, kk_context_t* _ctx); /* (dir : std/os/path/path) -> fsys list<std/os/path/path> */ 

kk_unit_t kk_std_os_dir__mlift1407_copy_directory(kk_std_core__list dirs, kk_std_os_path__path to, kk_unit_t wild__0, kk_context_t* _ctx); /* (dirs : list<std/os/path/path>, to : std/os/path/path, wild_0 : ()) -> <exn,fsys,div> () */ 

kk_unit_t kk_std_os_dir__mlift1408_copy_directory(kk_std_os_path__path to0, kk_std_core_types__tuple2_ _y_5, kk_context_t* _ctx); /* (to : std/os/path/path, (list<std/os/path/path>, list<std/os/path/path>)) -> <fsys,div,exn> () */ 

kk_unit_t kk_std_os_dir__mlift1409_copy_directory(kk_std_os_path__path dir, kk_std_os_path__path to1, kk_unit_t wild__, kk_context_t* _ctx); /* (dir : std/os/path/path, to : std/os/path/path, wild_ : ()) -> <exn,fsys> () */ 

kk_unit_t kk_std_os_dir_copy_directory(kk_std_os_path__path dir0, kk_std_os_path__path to2, kk_context_t* _ctx); /* (dir : std/os/path/path, to : std/os/path/path) -> <pure,fsys> () */ 

kk_unit_t kk_std_os_dir_copy_file_to_dir(kk_std_os_path__path from, kk_std_os_path__path dir, kk_context_t* _ctx); /* (from : std/os/path/path, dir : std/os/path/path) -> <exn,fsys> () */ 
 
// Is the path a valid file?

static inline bool kk_std_os_dir_is_file(kk_std_os_path__path path, kk_context_t* _ctx) { /* (path : std/os/path/path) -> fsys bool */ 
  kk_string_t _x2126 = kk_std_os_path_string(path, _ctx); /*string*/
  return kk_std_os_dir_prim_is_file(_x2126, _ctx);
}

kk_std_core__list kk_std_os_dir_list_directory_recursive(kk_std_os_path__path dir, kk_std_core_types__optional max_depth, kk_context_t* _ctx); /* (dir : std/os/path/path, max-depth : optional<int>) -> <div,fsys> list<std/os/path/path> */ 

void kk_std_os_dir__init(kk_context_t* _ctx);

#endif // header
