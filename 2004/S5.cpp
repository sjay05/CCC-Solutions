/*
 *  author:  sjay05
 *  created: 21.09.20 21:58:56
 */
#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

/*
 * K-Dimensional Vector (Meta):
 * - Create multi-dimensional with ease.
 * Source: https://codeforces.com/blog/entry/80222
 */

template <class T>
vector<T> create(size_t size, T initialValue) {
  return vector<T>(size, initialValue);
}

template <class T, class... Args>
auto create(size_t head, Args&&... tail) {
  /*
   * Usage:
   * - auto name = create<data_type>(dimensions..., fill value).
   * Example:
   *  auto dp = create<long long>(n, m, k, 1LL)
   *  - Equivalent to dp[n][m][k].
   */
  auto inner = create<T>(tail...);
  return vector<decltype(inner)>(head, inner);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) {
      break;
    }
    const int inf = 1e9 + 778;
    vector <vector <int> > arr(n, vector<int>(m, 0));
    auto dp = create<int>(n + 1, m + 1, 2, 2, -1);

    function<int(int,int,int,int)> solve = [&] (int r, int c, int d, int u) {
      if (r < 0 || c < 0 || r > n - 1 || c > m - 1 || arr[r][c] == -1) {
          return -inf;
      } else if (dp[r][c][d][u] != -1) {
        return dp[r][c][d][u];
      } else if (r == n - 1 && c == m - 1) {
        return arr[r][c];
      } else {
        int max_cnt = -inf;
        if (d == true) {
          max_cnt = max(max_cnt, solve(r - 1, c, 1, 0));
        } if (u == true) {
          max_cnt = max(max_cnt, solve(r + 1, c, 0, 1));
        }
        max_cnt = max(max_cnt, solve(r, c + 1, 1, 1));
        max_cnt += arr[r][c];
        return dp[r][c][d][u] = max_cnt;
      }
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c == '.') arr[i][j] = 0;
        else if (c == '*') arr[i][j] = -1;
        else arr[i][j] = (int) (c - '0');
      }
    }
    cout << solve(n - 1, 0, 1, 1) << '\n';
  }
  return 0;
}

