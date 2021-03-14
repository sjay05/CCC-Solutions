#include <bits/stdc++.h>

using namespace std;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s; 
  int cl = count(s.begin(), s.end(), 'L');
  int cm = count(s.begin(), s.end(), 'M');
  int nl = 0;
  for (int i = 0; i < cl; i++) {  
    nl += (s[i] != 'L');
  }
  int nm = 0;
  for (int i = cl; i < cl + cm; i++) {
    nm += (s[i] != 'M');
  }
  int m_in_l = 0;
  for (int i = 0; i < cl; i++) {
    m_in_l += (s[i] == 'M');
  }
  int l_in_m = 0;
  for (int i = cl; i < cl + cm; i++) {
    l_in_m += (s[i] == 'L');
  }
  cout << nl + nm - min(m_in_l, l_in_m) << '\n';
  return 0;
}
