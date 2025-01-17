#include <stdio.h>
#include <string.h>
#include "dbg.h"

int normal_copy(char *from, char *to, int count) {
  int i = 0;

  for(i = 0; i < count; i++) {
    to[i] = from[i];
  }

  return i;
}


/*
예시로 count가 10인 경우:

n = (10 + 7) / 8 = 2 (반복 횟수)
10 % 8 = 2 이므로 case 2부터 시작
첫 번째 반복에서 2부터 시작해서 2개 복사
두 번째 반복에서 나머지 8개 복사
 */
// https://johngrib.github.io/wiki/duff-s-device/
int duffs_device(char *from, char *to, int count) {
  {
    int n = (count + 7) / 8;

    switch (count % 8) {
      case 0:
        do {
          *to++ = *from++;
          case 7:
          *to++ = *from++;
          case 6:
          *to++ = *from++;
          case 5:
          *to++ = *from++;
          case 4:
          *to++ = *from++;
          case 3:
          *to++ = *from++;
          case 2:
          *to++ = *from++;
          case 1:
          *to++ = *from++;
        } while (--n > 0);
    }
  }
  return count;
}

int zeds_device(char *from, char *to, int count) {
  {
    int n = (count + 7) / 8;

    switch (count % 8) {
      case 0:
again:  *to++ = *from++;

      case 7:
        *to++ = *from++;
      case 6:
        *to++ = *from++;
      case 5:
        *to++ = *from++;
      case 4:
        *to++ = *from++;
      case 3:
        *to++ = *from++;
      case 2:
        *to++ = *from++;
      case 1:
        *to++ = *from++;
      if (--n > 0)
        goto again;
    }
  }
  return count;
}

int valid_copy(char *data, int count, char expects) {
  int i = 0;
  for(i = 0; i < count; i++) {
    if (data[i] != expects) {
      log_err("[%d] %c != %c", i, data[i], expects);
      return 0;
    }
  }
  return 1;
}

int main(int argc, char* argv[]) {

  char from[1000] = { 'a' };
  char to[1000] = { 'c' };
  int rc = 0;

  memset(from, 'x', sizeof(from));
  memset(to, 'y', sizeof(to));
  check(valid_copy(to, 1000, 'y'), "Not Initialized right");

  rc = duffs_device(from, to, 1000);
  check(rc == 1000, "duff failed %d ", rc);

  return 0;

error:
  return 1;
}
