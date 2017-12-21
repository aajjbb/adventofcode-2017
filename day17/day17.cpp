#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> data = {0};
  int pos = 0;

  const int skip = 380;
  const int rounds = 2017;
  const int goal_value = 2017;

  // insert values
  for (int r = 0; r < rounds; r++) {
    pos = ((pos + skip) % ((int) data.size())) + 1;
    data.insert(data.begin() + pos, r + 1);
  }

  vector<int>::iterator goal = find(data.begin(), data.end(), goal_value);
  goal++;

  cout << *goal << endl;

  return 0;
}
