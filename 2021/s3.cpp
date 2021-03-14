#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long) 1e18;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n), w(n), d(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> w[i] >> d[i];
  }
  auto Get = [&](int pos) {
    if (pos < 0) {
      return inf;
    }
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      if (p[i] == pos || abs(pos - p[i]) < d[i]) {  
        continue;
      }
      { 
        if (p[i] < pos) {
          cnt += (long long) abs(p[i] - (pos - d[i])) * w[i];
        } else {
          cnt += (long long) abs(p[i] - (pos + d[i])) * w[i];
        }
      }
    }
    return cnt;
  };  
  long long ans = inf;
  int low = 0, high = 1e9;
  while (low <= high) {
    int mid = (low + high) >> 1;  
    ans = min({ans, Get(mid), Get(mid - 1), Get(mid + 1)});
    if (Get(mid) < Get(mid - 1)) {
      low = mid + 1;
    } else {  
      high = mid - 1;
    }
  } 
  cout << ans << '\n';
  return 0;
}
