/**
 *    author:  sjay05
 *    created: 16.11.2020 12:54:53
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int inf = (int) 1e9;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<int> seq(4);
    for (int i = 0; i < 4; i++) {
      cin >> seq[i];
    }
    sort(seq.begin(), seq.end());
    int mx = -inf;
    auto Do = [&](int a, int b, int op) {
      if (op == 0) {
        return a + b;
      } if (op == 1) {
        return a - b;
      } if (op == 2) {
        return a * b;
      } if (op == 3) {
        if (b && a % b == 0) {
          return a / b;
        }
      }
      return -inf;
    };
    do {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          for (int k = 0; k < 4; k++) {           
            int a = seq[0], b = seq[1], c = seq[2], d = seq[3];
            int v1 = Do(Do(Do(a, b, i), c, j), d, k);
            if (v1 >= 0 && v1 <= 24) {
              mx = max(mx, v1); 
            }
            int v2 = Do(Do(a, b, i), Do(c, d, j), k);
            if (v2 >= 0 && v2 <= 24) {
              mx = max(mx, v2);
            }
            int v3 = Do(Do(a, Do(b, c, i), j), d, k);
            if (v3 >= 0 && v3 <= 24) {
              mx = max(mx, v3);
            }
            int v4 = Do(a, Do(b, Do(c, d, k), j), i);
            if (v4 >= 0 && v4 <= 24) {
              mx = max(mx, v4);
            }
            int v5 = Do(a, Do(Do(b, c, j), d, k), i); 
            if (v5 >= 0 && v5 <= 24) {
              mx = max(mx, v5);
            }
          }
        }
      }
    } while (next_permutation(seq.begin(), seq.end()));
    cout << mx << '\n';
  }
  return 0;
}


