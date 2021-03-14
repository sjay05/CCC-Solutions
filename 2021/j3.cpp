#include <bits/stdc++.h>

using namespace std;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  string prev(1, '.');
  while (true) {
    string s;
    cin >> s;
    if (s == "99999") {
      break;
    }
    int n0 = (int) (s[0] - '0');
    int n1 = (int) (s[1] - '0');
    {
      if (n0 + n1 == 0) {
        cout << prev << " ";
      } else if ((n0 + n1) % 2 == 0) {
        cout << "right ";
        prev = "right";
      } else if ((n0 + n1) % 2 == 1) {
        cout << "left ";
        prev = "left";
      }
    }
    cout << s.substr(2, 3) << '\n';
  }
  return 0;
}


