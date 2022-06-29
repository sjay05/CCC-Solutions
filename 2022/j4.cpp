#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  set<pair<string, string>> xs;
  for (int i = 0; i < x; i++) {
    string a, b;
    cin >> a >> b;
    xs.emplace(make_pair(min(a, b), max(a, b)));
  }
  int y;
  cin >> y;
  set<pair<string, string>> ys;
  for (int i = 0; i < y; i++) {
    string a, b;
    cin >> a >> b;
    ys.emplace(make_pair(min(a, b), max(a, b)));
  }
  int g;
  cin >> g;
  set<pair<string, string>> xs_good;
  set<pair<string, string>> ys_bad;
  for (int it = 0; it < g; it++) {
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j) {
          continue;
        }
        pair<string, string> p = {min(s[i], s[j]), max(s[i], s[j])};
        xs_good.insert(p);
        if (ys.find(p) != ys.end()) {
          ys_bad.insert(p);
        }
      }
    }
  }
  int ans = 0; 
  for (auto& p : xs) {
    if (xs_good.find(p) == xs_good.end()) {
      ans += 1;
    }
  }
  ans += ys_bad.size();
  cout << ans << '\n';
  return 0;
}

