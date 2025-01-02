#include <stdio.h>
#include <ctype.h>


// 아직도 전방선언은 중요하다. C를 작성한다면...
// 전방 선언을 안하면 암시적 선언을 함. int를 반환하는 함수
int can_print_it(char ch);
void print_letters(char arg[]);


void print_arguments(int argc, char* argv[]) {
  int i = 0;

  for(i = 0; i < argc; i++) {
    print_letters(argv[i]);
  }
}

void print_letters(char arg[]) {
  int i = 0;

  for(i = 0; arg[i] != '\0'; i++) {
    char ch = arg[i];
    if (isalpha(ch) || isblank(ch)) {
      printf("'%c' == %d", ch, ch);
    }
  }

  printf("\n");
}

int main(int argc, char* argv[]) {
  print_arguments(argc, argv);
  return 0;
}
