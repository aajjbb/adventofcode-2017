#include <stdio.h>
#include <stdlib.h>

#define LINE_NUM 128
#define STR_MAX_SIZE 100
#define LIST_SIZE 256

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


void get_knoth_hash(char* base_str, int base_str_len, int* hash) {
  int i, j;
  int rounds;
  int lengths[STR_MAX_SIZE];
  int n = 0;
  int list[LIST_SIZE];
  int pos = 0;
  int skip = 0;

  // using chars as ints (bytes)
  for (i = 0; i < base_str_len; i++) {
    lengths[n] = (int) base_str[i];
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

    hash[i] = curr_value;
  }
}

int main(int argc, char* argv[]) {
  char input[STR_MAX_SIZE];
  int hash[STR_MAX_SIZE];
  int i, j;
  int answer = 0;

  scanf("%s", input);

  for (i = 0; i < LINE_NUM; i++) {
    char line_id[STR_MAX_SIZE];

    int len = sprintf(line_id, "%s-%d", input, i);

    get_knoth_hash(line_id, len, hash);

    for (j = 0; j < 16; j++) {
      answer += __builtin_popcount(hash[j]);
    }
  }

  printf("%d", answer);
  puts("");

  return 0;
}
