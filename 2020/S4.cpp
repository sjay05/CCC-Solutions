/**
 *    author:  sjay05
 *    created: 30.12.2020 15:18:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0); 
  string foo;
  cin >> foo;
  auto GetC = [&](char c) {
    return (c == 'A' ? 0 : (c == 'B' ? 1 : 2));
  };
  int n = (int) foo.size();
  vector<int> num(n);
  int cntA = 0, cntB = 0, cntC = 0;
  for (int i = 0; i < n; i++) {
    num[i] = GetC(foo[i]);
    cntA += (num[i] == 0);
    cntB += (num[i] == 1);
    cntC += (num[i] == 2);
  } 
  vector<vector<int>> cnt(3, vector<int>(n + 1, 0));
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < 3; i++) {   
      int ft = (i == num[j] ? 1 : 0);
      cnt[i][j + 1] = cnt[i][j] + ft;
    }
  }
  auto GetOps = [&](int ch) {
    set<int> st = {0, 1, 2};
    st.erase(ch);
    return st;
  };
  auto GetCnt = [&](int ch) { 
    if (ch == 0) {
      return cntA;
    } if (ch == 1) {
      return cntB; 
    }
    return cntC;
  };
  auto NotChar = [&](int ch, int lb) {
    int rb = min(n, lb + GetCnt(ch) - 1);
    int ans = 0;
    set<int> ops = GetOps(ch);  
    for (int t : ops) {
      ans += cnt[t][rb] - cnt[t][lb - 1];
    }
    if (lb + GetCnt(ch) - 1 > n) {
      int fb = (lb + GetCnt(ch) - 1) % n;
      for (int t : ops) {
        ans += cnt[t][fb];
      }
    }
    return ans;
  };
  auto GetSec = [&](int x, int y, int lb) {
    int rb = min(n, lb + GetCnt(x) - 1);
    int ans = 0;
    ans += cnt[y][rb] - cnt[y][lb - 1];
    if (lb + GetCnt(x) - 1 > n) {
      int fb = (lb + GetCnt(x) - 1) % n;
      ans += cnt[y][fb];
    }
    return ans;
  };
  int ans = (int) 1e9;
  for (int i = 1; i <= n; i++) {
    int pos = i;
    for (int j = 0; j < 3; j++) {
      if (j != 0) {
        int npos = (pos + cntA - 1) % n + 1 % n;
        int cnt = NotChar(0, pos);
        cnt += NotChar(j, npos);
        cnt -= min(GetSec(0, j, pos), GetSec(j, 0, npos));
        ans = min(ans, cnt);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}


