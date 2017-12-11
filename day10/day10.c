#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 256
#define MAX_LENGTH 100

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

void reverse_section(int list[], int n, int beg, int end) {
  int len = 0;
  int i;

  if (beg <= end) {
    len = end - beg + 1;
  } else {
    len = end + 1 + (n - beg);
  }

  for (i = 0; i < len / 2; i++) {
    int tmp = list[beg];

    list[beg] = list[end];
    list[end] = tmp;

    beg = (beg + 1) % n;
    end = (end - 1 + n) % n;
  }
}

int main() {
  int lengths[MAX_LENGTH];
  int n = 0;

  int i;
  int list[LIST_SIZE];
  int pos = 0;
  int skip = 0;

  while (scanf("%d, ", &lengths[n]) == 1) {
    n += 1;
  }

  for (i = 0; i < LIST_SIZE; i++) {
    list[i] = i;
  }

  for (i = 0; i < n; i++) {
    if (lengths[i] > LIST_SIZE) continue;
    int end_section = (pos + max(0, lengths[i] - 1)) % LIST_SIZE;

    reverse_section(list, LIST_SIZE, pos, end_section);

    pos = (pos + lengths[i] + skip) % LIST_SIZE;
    skip += 1;
  }

  printf("%d\n", list[0] * list[1]);

  return 0;
}
