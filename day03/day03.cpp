#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;

  cin >> N;

  int l = 0, h = 1000;

  // coordinate
  int x = -1;
  int y = -1;

  int root = -1;
  int curr_value = 0;

  while (l <= h) {
    int m = (l + h) / 2;
    int corner = (2 * m + 1) * (2 * m + 1);

    if (corner > N) {
      h = m - 1;
    } else {
      root = (2 * m + 1);
      curr_value = corner;

      x = +(m);
      y = -(m);

      l = m + 1;
    }
  }

  vector<int> dx = {1,0,-1, 0,1};
  vector<int> dy = {0,1, 0,-1,0};

  vector<int> walk = {1,
                      root,
                      root + 1,
                      root + 1,
                      root + 1};

  for (int i = 0; i < (int) walk.size() && curr_value < N; i++) {
    for (int j = 0; j < walk[i]; j++) {
      x += dx[i];
      y += dy[i];

      curr_value += 1;

      if (curr_value == N) {
        break;
      }
    }
  }

  cout << abs(x) + abs(y) << "\n";

  return 0;
}
