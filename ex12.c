#include <stdio.h>

int main(int argc, char* argv[])
{
  int areas[] = {10, 12, 13, 14, 20};
  char name[] = "Zed";
  char full_name[] = {
    'Z', 'e', 'd',
    ' ', 'A', '.', ' ',
    'S', 'h', 'a', 'w', '\0'
  };

  // areas[5] = 100; // no. array is fixed length

  printf("The size of an int : %ld \n", sizeof(int));
  printf("The size of area (int[]]) : %ld \n", sizeof(areas)); // return byte size of arr
  printf("The number of ints in areas : %ld \n", sizeof(areas) / sizeof(int));
  printf("The first area is %d, the 2nd %d. \n", areas[0], areas[1]); // c는 out of index여도 별다른 컴파일 에러 안 남
  printf("The size of a char : %ld \n", sizeof(char));
  printf("The size of name (char[]): %ld \n", sizeof(name)); // null char를 포함하여 4를 반환
  printf("The number of chars: %ld \n", sizeof(name) / sizeof(char)); // char가 4개 있는 것으로 판단됨.
  printf("The size of full_name (char[]) : %ld \n", sizeof(full_name));
  printf("The number of chars: %ld \n", sizeof(full_name) / sizeof(char));
  printf("name : %s | full_name : %s \n", name, full_name);

  return 0;

}
