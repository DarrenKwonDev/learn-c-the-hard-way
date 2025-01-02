#include <stdio.h>
#include <ctype.h>

void print_vowel(char* pWord) {
  if (pWord == NULL) {
    return;
  }

  int i = 0;
  for (i = 0; pWord[i] != '\0'; i++) {
    char letter = pWord[i];
    letter = tolower(letter);

    switch (letter) {
      case 'a':
      case 'A':
        printf("%d: 'A'\n", i);
        break;

      case 'e':
      case 'E':
        printf("%d: 'E'\n", i);
        break;

      case 'i':
      case 'I':
        printf("%d: 'I'\n", i);
        break;

      case 'o':
      case 'O':
        printf("%d: 'O'\n", i);
        break;

      case 'u':
      case 'U':
        printf("%d: 'U'\n", i);
        break;

      case 'y':
      case 'Y':
        if (i > 2) {
          printf("%d: 'Y'\n", i);
        }
        break;

      default:
        printf("%d: %c is not a vowel \n", i, letter);
    }
  }

}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    printf("ERROR: You need arguments. \n");
    return 1;
  }

  int i = 0;
  int cnt = argc - 1;


  for(int j = 1; j <= cnt; j++) {
    print_vowel(argv[j]);
  }

  return 0;
}
