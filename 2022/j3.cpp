#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<string> all;
  string t;
  auto Check = [&](char c) {
    return ('0' <= c && c <= '9');
  };
  for (int i = 0; i < n; i++) {
    t += s[i];
    if (i == n - 1 || (Check(s[i]) && !Check(s[i + 1]))) {
      all.push_back(t);
      t.clear();
    }
  }
  for (string t : all) {
    int id = -1;
    int len = (int) t.size();
    for (int i = 0; i < len; i++) {
      if (t[i] == '+' || t[i] == '-') {
        id = i;
        break;
      }
    }
    cout << t.substr(0, id) << " " << (t[id] == '+' ? "tighten" : "loosen") << " " << t.substr(id + 1, len - id - 1) << '\n';
  }
  return 0;
}
