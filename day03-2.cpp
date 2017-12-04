#include <bits/stdc++.h>

using namespace std;

int main() {
  int N = 361527;

  int x = 0;
  int y = 0;

  vector<int> dx = {1,0,-1, 0,1};
  vector<int> dy = {0,1, 0,-1,0};

  vector<int> neigh_x = {0, 0, -1, 1, -1, 1, -1, 1};
  vector<int> neigh_y = {-1, 1, 0, 0, -1, 1, 1, -1};

  map<pair<int, int>, int> memo;

  memo[make_pair(0, 0)] = 1;

  int curr_value = 0;

  for (int root = 1; curr_value <= N; root += 2) {
    vector<int> walk = {1,
                        root,
                        root + 1,
                        root + 1,
                        root + 1};

    for (int i = 0; i < (int) walk.size() && curr_value <= N; i++) {
      for (int j = 0; j < walk[i]; j++) {
        x += dx[i];
        y += dy[i];

        int cell_value = 0;

        for (int k = 0; k < 8; k++) {
          cell_value += memo[make_pair(x + neigh_x[k],
                                       y + neigh_y[k])];
        }

        curr_value = cell_value;

        if (curr_value > N) {
          break;
        }

        memo[make_pair(x, y)] = curr_value;
      }
    }
  }

  cout << curr_value << "\n";

  return 0;
}
