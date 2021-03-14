#include <bits/stdc++.h>

using namespace std;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<double> a(n + 1);
  for (int i = 0; i < n + 1; i++) {
    cin >> a[i];
  }
  vector<double> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  double ans = 0.0;
  for (int i = 1; i < n + 1; i++) {   
    if (a[i] == a[i - 1]) {
      ans += a[i] * w[i - 1];
      continue;
    }
    double box = w[i - 1] * min(a[i], a[i - 1]);
    double tri_len = max(a[i], a[i - 1]) - min(a[i], a[i - 1]);
    double tri_a = tri_len * w[i - 1] / 2.0;
    ans += box + tri_a;
  } 
  cout << fixed << setprecision(5) << ans << '\n';
  return 0;
}
