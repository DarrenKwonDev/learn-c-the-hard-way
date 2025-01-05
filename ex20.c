#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char* message) {
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s \n", message);
  }
  exit(1);
}

// compare_cb is ptr to (int a, int b) -> int
typedef int (*compare_cb)(int a, int b);

int* bubble_sort(int* numbers, int count, compare_cb cmp)
{
  int temp = 0;
  int i = 0;
  int j = 0;
  int* target = malloc(count * sizeof(int)); // 해제는 함수 바깥에서

  if (target == NULL)
    die("Memory error");

  memcpy(target, numbers, count * sizeof(int));

  for(i = 0; i < count; i++) {
    for(j = 0; j < count - 1; j++) {
      if (cmp(target[j], target[j + 1]) > 0) {
        temp = target[j + 1];
        target[j + 1] = target[j];
        target[j] = temp;
      }
    }
  }

  return target;
}


// cmp 함수가 
// 양수를 반환하면 == a > b 라면 == b가 앞으로, a가 뒤로
// [1, 2, 3, 4] 와 같은 오름차순으로 정렬됨
int sorted_order(int a, int b) { return a - b; } // 오름차순
int reverse_order(int a, int b) { return b - a; } // 내림차순
int strange_order(int a, int b) {
  if (a == 0 || b == 0) {
    return 0;
  } else {
    return a % b;
  }
}

void test_sorting(int* numbers, int count, compare_cb cmp) {
  int i = 0;
  int *sorted = bubble_sort(numbers, count, cmp);

  if (sorted == NULL)
    die("Failed to sort as requested.");
  
  for(i = 0; i < count; i++)
    printf("%d ", sorted[i]);
  printf("\n");

  free(sorted);
}

void destory(compare_cb cmp)
{
  int i = 0;
  unsigned char* data = (unsigned char*)cmp;

  for(i = 0; i < 1; i++)
  {
    data[i] = i;
  }
  printf("\n");
}

void dump(compare_cb cmp)
{
  int i = 0;
  unsigned char* data = (unsigned char*)cmp;

  for(i = 0; i < 25; i++) {
    printf("%02x:", data[i]);
  }
  printf("\n");
}


int main(int argc, char* argv[]) {
  if (argc < 2) die("USAGE: ex18 <count>4 3 1 5 6");

  int count = argc - 1;
  int i = 0;
  char** inputs = argv + 1; // argv[0] 은 count이므로 offset 연산으로 다음 것을 지정.

  int *numbers = malloc(count * sizeof(int));
  if (numbers == NULL) die("Memory error.");

  for(i = 0; i < count; i++)
    numbers[i] = atoi(inputs[i]);

  test_sorting(numbers, count, sorted_order);
  test_sorting(numbers, count, reverse_order);
  test_sorting(numbers, count, strange_order);
  
  free(numbers);

  printf("SORTED:");
  dump(sorted_order);

  printf("SORTED:");
  dump(sorted_order);

  return 0;
}






