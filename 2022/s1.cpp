#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  int ans = 0;
  for (int it = 0; it < (int) 1e6 + 1; it++) {
    long long four = it * 4LL;
    long long rem = n - four;
    if (rem < 0) {
      continue;
    }
    if (rem % 5 == 0) {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}

