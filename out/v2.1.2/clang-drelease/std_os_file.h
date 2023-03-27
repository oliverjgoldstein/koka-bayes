#pragma once
#ifndef kk_std_os_file_H
#define kk_std_os_file_H
// Koka generated module: "std/os/file", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_os_path.h"
#include "std_os_dir.h"

// type declarations

// value declarations

kk_std_core__exception kk_std_os_file_prepend(kk_std_core__exception exn, kk_string_t pre, kk_context_t* _ctx); /* (exn : exception, pre : string) -> exception */ 

kk_std_core__error kk_std_os_file_read_text_file_err(kk_string_t path, kk_context_t* _ctx); /* (path : string) -> fsys error<string> */ 

kk_std_core__error kk_std_os_file_write_text_file_err(kk_string_t path, kk_string_t content, kk_context_t* _ctx); /* (path : string, content : string) -> fsys error<()> */ 

kk_string_t kk_std_os_file_read_text_file(kk_std_os_path__path path, kk_context_t* _ctx); /* (path : std/os/path/path) -> <exn,fsys> string */ 

kk_unit_t kk_std_os_file__mlift476_write_text_file(kk_string_t content, kk_std_os_path__path path, kk_unit_t _c_3, kk_context_t* _ctx); /* (content : string, path : std/os/path/path, ()) -> () */ 

kk_unit_t kk_std_os_file_write_text_file(kk_std_os_path__path path, kk_string_t content, kk_std_core_types__optional create_dir, kk_context_t* _ctx); /* (path : std/os/path/path, content : string, create-dir : optional<bool>) -> <exn,fsys> () */ 

void kk_std_os_file__init(kk_context_t* _ctx);

#endif // header
