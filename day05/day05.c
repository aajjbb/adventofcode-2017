#include <stdlib.h>
#include <stdio.h>

#define MAX_N 100000

int main(int argc, char* argv[]) {
  int buffer[MAX_N];
  int tmp;

  int N = 0;
  while (scanf("%d", &tmp) == 1) {
    buffer[N++] = tmp;
  }

  int pos = 0;
  int steps = 0;

  while (pos >= 0 && pos < N) {
    int next_pos = pos + buffer[pos];
    buffer[pos] += 1;
    pos = next_pos;
    steps += 1;
  }

  printf("%d\n", steps);

  return 0;
}
