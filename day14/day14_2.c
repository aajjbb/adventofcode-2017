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

void dfs(int x, int y, int maze[LINE_NUM][LINE_NUM], int memo[LINE_NUM][LINE_NUM]) {
  int i;

  memo[x][y] = 1;

  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};

  for (i = 0; i < 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];

    if (xx >= 0 && yy >= 0 && xx < LINE_NUM && yy < LINE_NUM &&
        maze[xx][yy] == 1 && !memo[xx][yy]) {
      dfs(xx, yy, maze, memo);
    }
  }
}

int main(int argc, char* argv[]) {
  char input[STR_MAX_SIZE];
  int maze[LINE_NUM][LINE_NUM];
  int memo[LINE_NUM][LINE_NUM];
  int hash[STR_MAX_SIZE];
  int i, j, k;
  int answer = 0;

  scanf("%s", input);

  for (i = 0; i < LINE_NUM; i++) {
    char line_id[STR_MAX_SIZE];

    int len = sprintf(line_id, "%s-%d", input, i);

    get_knoth_hash(line_id, len, hash);
    
    for (j = 0; j < 16; j++) {
      printf("%x ", hash[j]);
      for (k = 0; k < 8; k++) {
        memo[i][8 * j + k] = 0;

        if (hash[j] & (1 << (7 - k))) {
          maze[i][8 * j + k] = 1;
        } else {
          maze[i][8 * j + k] = 0;
        }
      }
    }
    puts("");
  }
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      printf("%d", maze[i][j]);
    }
    puts("");
  }
  puts("");
  for (i = 0; i < LINE_NUM; i++) {
    for (j = 0; j < LINE_NUM; j++) {
      if (maze[i][j] == 1 && memo[i][j] == 0) {
        answer += 1;

        dfs(i, j, maze, memo);
      }
    }
  }

  printf("%d", answer);
  puts("");
  return 0;
}
