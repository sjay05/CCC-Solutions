#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<pair<int, int>> p(t);
  for (int i = 0; i < t; i++) {
    cin >> p[i].first >> p[i].second;
  }
  t += 1;
  p.emplace_back(0, 0);
  int ans = 0;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < t; j++) {
      if (i == j && i != t - 1) {
        continue;
      }
      int U = p[i].first;
      int L = p[j].second;
      int cur = inf;
      for (int k = 0; k < t; k++) {
        if (k == i || k == j) {
          continue;
        }
        if (p[k].first > U && p[k].second > L) {
          int dx = p[k].first - U - 1;
          int dy = p[k].second - L - 1;
          cur = min(cur, max(dx, dy));
        }
      }
      if (min(n - U, n - L) < cur) {
        cur = min(n - U, n - L);
      }
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';
  return 0;
}

