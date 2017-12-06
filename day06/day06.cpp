#include <bits/stdc++.h>

using namespace std;

void distribute(vector<int>& bank, const int N) {
  // get the largest portion
  int curr_best = -1;
  int pos = -1;

  for (int i = 0; i < N; i++) {
    if (curr_best < bank[i]) {
      curr_best = bank[i];
      pos = i;
    }
  }

  bank[pos] = 0;
  pos = (pos + 1) % N;

  while (curr_best > 0) {
    bank[pos] += 1;
    pos = (pos + 1) % N;
    curr_best -= 1;
  }
}

int main() {
  int N = 0, tmp;
  int iterations = 0;
  vector<int> bank;

  map<vector<int>, int> mapper;

  while (cin >> tmp) {
    bank.push_back(tmp);
    N += 1;
  }

  mapper[bank] = 1;

  while (true) {
    distribute(bank, N);

    iterations += 1;

    if (mapper[bank] > 0) {
      break;
    }

    mapper[bank] = iterations;
  }

  cout << iterations << endl;

  return 0;
}
