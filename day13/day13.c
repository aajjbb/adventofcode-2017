#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_DEPTH 96

int range[MAX_N];

void readData() {
  int d, r;

  while (scanf("%d: %d", &d, &r) == 2) {
    range[d] = r;
  }
}

int current_position(int time, int range) {
  if (range == 0) {
    return 0;
  }

  int answer = -1;
  int div = time / (range - 1);
  int mod = time % (range - 1);

  if (div % 2 == 0) {
    return mod;
  } else {
    return range - 1 - mod;
  }
}

int main(int argc, char* argv[]) {
  memset(range, 0, sizeof(range));

  readData();
  int t;
  int answer = 0;

  for (t = 0; t <= MAX_DEPTH; t++) {
    int c_pos = current_position(t, range[t]);

    if (c_pos == 0) {
      answer += t * range[t];
    }
  }

  printf("%d", answer);
  puts("");

  return 0;
}
