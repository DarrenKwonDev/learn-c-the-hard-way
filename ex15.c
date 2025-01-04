#include <stdio.h>

int main(int argc, char* argv[]) 
{
  int ages[] = {23, 43, 12, 89, 2};
  char* names[] = { "Alan", "Frank", "Mary", "John", "Lisa" };

  //----------------------------------------
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  for(i = 0; i < count; i++) {
    printf("%s has %d years alive.\n", names[i], ages[i]);
  }

  printf("---\n");

  //----------------------------------------
  int* cur_age = ages;    // ages 배열을 int 단위의 포인터로 읽겠다

  // cur_name + 1 하면, char* names[] 의 두번째 원소를 가리키는 포인터
  char** cur_name = names; // names 배열을 char 포인터의 포인터로 읽겠다

  for(i = 0; i < count; i++) {
    printf("%s is %d years old. \n", *(cur_name + i), *(cur_age + i));
  }

  printf("---\n");

  //----------------------------------------
  for(i = 0; i < count; i++) {
    printf("%s is %d years old again. \n", cur_name[i], cur_age[i]); // ptr + i와 ptr[i] 는 같다.
  }
  
  printf("---\n");

  //----------------------------------------
  for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
    printf("%s lived %d years so far. \n", *cur_name, *cur_age);
  }

  return 0;
}
