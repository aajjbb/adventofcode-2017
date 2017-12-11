#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
  char lengths_s[MAX_LENGTH];
  int lengths[MAX_LENGTH];
  int n = 0;

  int i, j, rounds;
  int list[LIST_SIZE];
  int pos = 0;
  int skip = 0;

  scanf("%s", lengths_s);

  // using chars as ints (bytes)
  for (i = 0; i < strlen(lengths_s); i++) {
    lengths[n] = (int) lengths_s[i];
    n++;
  }
  // adding the additional values - hard_coded
  lengths[n++] = 17;
  lengths[n++] = 31;
  lengths[n++] = 73;
  lengths[n++] = 47;
  lengths[n++] = 23;
  
  for (i = 0; i < LIST_SIZE; i++) {
    list[i] = i;
  }

  for (rounds = 0; rounds < 64; rounds++) {
    for (i = 0; i < n; i++) {
      if (lengths[i] > LIST_SIZE) continue;
      int end_section = (pos + max(0, lengths[i] - 1)) % LIST_SIZE;

      reverse_section(list, LIST_SIZE, pos, end_section);

      pos = (pos + lengths[i] + skip) % LIST_SIZE;
      skip += 1;
    }
  }

  for (i = 0; i < 16; i++) {
    int curr_value = 0;

    for (j = 0; j < 16; j++) {
      curr_value ^= list[16 * i + j];
    }

    printf("%x", curr_value);
  }

  puts("");

  return 0;
}
