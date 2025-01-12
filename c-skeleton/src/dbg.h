#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

// M : message. format string
// if NDEBUG define, debug nothing.
#ifdef NDEBUG
  #define debug(M, ...)
#else
  // ##는 가변 인자가 비어있을 때 앞의 쉼표를 자동으로 제거해줍니다. 이를 "argument prescan" 이라 합니다.
  #define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

// errno to err string
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

//------------------------------
//logging

//String Literal Concatenation. C 에선 문자열이 붙어 있으면 자동으로 하나의
//문자열로 처리됨.
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

//------------------------------
// go to err
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
