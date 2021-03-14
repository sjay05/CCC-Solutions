#include <bits/stdc++.h>

using namespace std;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  int b;
  cin >> b; 
  int res = 5 * b - 400;
  cout << res << '\n';            
  cout << (res == 100 ? 0 : (res < 100 ? 1 : -1)) << '\n';
  return 0;
}


