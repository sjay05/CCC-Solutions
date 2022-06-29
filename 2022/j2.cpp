#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  bool good = true;
  int cnt = 0;
  while (n--) {
    int x, y;
    cin >> x >> y;
    int val = (5 * x) - (3 * y);
    if (val <= 40) {
      good = false;
      continue;
    }
    cnt += 1;
  }
  if (good == true) {
    cout << cnt << "+" << '\n';
    return 0;
  }
  cout << cnt << '\n';
  return 0;
}
