#include <bits/stdc++.h>

using namespace std;

int main() {
  int size = 1;
  int pos = 0;

  const int skip = 380;
  const int rounds = 50000000;
  const int goal_value = 0;

  int goal = 0;

  // insert values
  for (int r = 0; r < rounds; r++) {
    pos = ((pos + skip) % (size)) + 1;
    size += 1;

    if (pos == 1) {
      goal = r + 1;
    }
  }

  cout << goal << endl;

  return 0;
}
