#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

// 전역변수는  header에서 extern되어 다른 .c 에서 사용될 수 있
int THE_SIZE = 1000;

// 해당 파일에서만 사용, extern 불가.
static int THE_AGE = 37;

// 그러나 해당 함수들을 통해 static 변수에 접근 가능.
int get_age() {
  return THE_AGE;
}

void set_age(int age) {
  THE_AGE = age;
}

// 함수 호출 때마다 이전 ratio를 유지함. 왜냐면 함수 내 static 변수이기 때문.
double update_ratio(double new_ratio) {
  static double ratio = 1.0; // 프로그램 라이프 사이클 전체에 존재

  double old_ratio = ratio;
  ratio = new_ratio;

  return old_ratio;
}

void print_size() {
  log_info("I think size is : %d,", THE_SIZE);
}
