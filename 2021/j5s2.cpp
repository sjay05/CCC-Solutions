#include <bits/stdc++.h>

using namespace std;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int m, n, k;
  cin >> m >> n >> k;
  vector<int> delta_row(m);
  vector<int> delta_col(n);
  while (k--) {
    char op;
    int id;
    cin >> op >> id;
    --id;
    delta_row[id] += (op == 'R');
    delta_col[id] += (op == 'C');
  }
  vector<vector<int>> delta(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      delta[i][j] += delta_row[i];
    }
  }
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      delta[i][j] += delta_col[j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cnt += (delta[i][j] % 2 == 1);
    }
  } 
  cout << cnt << '\n';
  return 0;
}
