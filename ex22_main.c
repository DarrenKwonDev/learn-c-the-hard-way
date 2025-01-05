#include "ex22.h"
#include "dbg.h"

const char* MY_NAME = "Zed A. Shaw";

void scope_demo(int count) {
  log_info("count is : %d", count);

  if (count > 10) {
    int count = 100; // this bug
    log_info("count in this scope is %d", count);
  }
 
  // if 내부에 있던 int count는 pop되어 없어지고 본래 count를 출력함.
  log_info("count is at exit: %d", count);

  count = 3000;
  
  log_info("count after assign : %d", count);
}

int main(int argc, char* argv[]) {

  // 파일 static 변수인 THE_AGE의 getter를 실험해보기
  log_info("My name : %s, age: %d", MY_NAME, get_age());

  // setter 실험해보기
  set_age(100);
  log_info("My age is now : %d", get_age());

  // extern으로 노출된 변수 체크
  log_info("THE_SIZE is : %d", THE_SIZE);
  print_size();

  THE_SIZE = 9; // extern 변수를 수정하면, 시스템 전체에 영향을 준다

  log_info("THE_SIZE is now : %d", THE_SIZE);
  print_size();

  // ratio 함수 내 static 변수 테스트
  log_info("Ratio at first : %f", update_ratio(2.0)); // return old ratio
  log_info("Ratio again : %f", update_ratio(10.0));
  log_info("Ratio once more : %f", update_ratio(300.0));

  int count = 4;
  scope_demo(count);
  scope_demo(count * 20);

  log_info("count after calling scope_demo : %d", count);

  return 0;
}
