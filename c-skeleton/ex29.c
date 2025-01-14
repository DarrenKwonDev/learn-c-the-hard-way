#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int (*lib_function) (const char* data);

int main(int argc, char* argv[]) {
  int rc = 0;
  check(argc == 4, "USAGE: ex29 libex29.so function data");
  
  char* lib_file = argv[1];
  char* func_to_run = argv[2];
  char* data = argv[3];

  void* lib = dlopen(lib_file, RTLD_NOW); // lib_file에 지정된 라이브러리 로드
  check(lib != NULL, "Failed to open the library %s: %s", lib_file, dlerror());

  lib_function func = dlsym(lib, func_to_run); // lib에서 func_to_run에 저장된 문자열을 사용한다.
  check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());

  rc = func(data); // 실제로 함수를 사용한다.
  check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

  rc = dlclose(lib);
  check(rc == 0, "Failed to close %s", lib_file);

  return 0;

error:
  return 1;

}
