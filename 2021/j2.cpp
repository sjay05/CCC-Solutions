#include <bits/stdc++.h>

using namespace std;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<string> st(n);
  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> st[i] >> val[i];
  }
  int p = *max_element(val.begin(), val.end());
  for (int i = 0; i < n; i++) {
    if (val[i] == p) {
      cout << st[i] << '\n';
      return 0;
    }
  }
  return 0;
}

