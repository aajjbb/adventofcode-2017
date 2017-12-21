#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STR 100000

int evaluate(char* str) {
  int len = strlen(str);
  int i;
  int in_garbage = 0;
  int answer = 0;
  int group_value = 0;

  for (i = 0; i < len; i++) {
    if (str[i] == '!') {
      i += 1;
      continue;
    }

    if (str[i] == '>') {
      in_garbage = 0;
    } else {
      if (in_garbage) {
        answer += 1;
        continue;
      } else {
        if (str[i] == '<') {
          in_garbage = 1;
        }
      }
    }
  }

  return answer;
}

void test() {
  assert(evaluate("<>") == 0);
  assert(evaluate("<random characters>") == 17);
  assert(evaluate("<{!>}>") == 2);
  assert(evaluate("<!!>") == 0);
  assert(evaluate("<!!!>>") == 0);
}

int main(int argc, char* argv[]) {
  test();

  char input[MAX_STR];

  scanf("%s", input);

  printf("%d", evaluate(input));
  puts("");

  return 0;
}
