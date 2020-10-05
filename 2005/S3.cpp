/**
 *    author:  sjay05
 *    created: 05.10.2020 10:24:58
**/
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

template <class T>
vector<T> create(size_t size, T initialValue) {
  return vector<T>(size, initialValue);
}

template <class T, class... Args>
auto create(size_t head, Args&&... tail) {
  /*
   * Usage:
   * - auto name = create<data_type>(dimensions..., fill value).
   * Example:
   *  auto dp = create<long long>(n, m, k, 1LL)
   *  - Equivalent to dp[n][m][k].
   */
  auto inner = create<T>(tail...);
  return vector<decltype(inner)>(head, inner);
}

typedef vector <vector <int> > matrix;

matrix multiply(matrix &a, matrix &b) {
  matrix mult;
  int m = a.size();
  int n = a.back().size();
  int p = b.size();
  int q = b.back().size();
  mult = vector <vector <int> > (m * p, vector <int> (n * q));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < p; k++) {
        for (int l = 0; l < q; l++) {
          int prod = a[i][j] * b[k][l];
          mult[i * p + k][j * q + l] = prod;
        }
      }
    }
  }
  return mult;
}

void get_output(matrix &ret) {
  const int inf = (int) 1e9 + 778;
  int maxel = -inf;
  int minel = inf;
  int maxrw = -inf;
  int minrw = inf;
  int maxcol = -inf;
  int mincol = inf;
  
  int r = ret.size();
  int c = ret.back().size();
  for (int i = 0; i < r; i++) {
    maxel = max(maxel, *max_element(ret[i].begin(), ret[i].end()));
    minel = min(minel, *min_element(ret[i].begin(), ret[i].end()));
  }
  for (int i = 0; i < r; i++) {
    maxrw = max(maxrw, accumulate(ret[i].begin(), ret[i].end(), 0));
    minrw = min(minrw, accumulate(ret[i].begin(), ret[i].end(), 0));
  }
  for (int j = 0; j < c; j++) {
    int acc = 0;
    for (int i = 0; i < r; i++) {
      acc += ret[i][j];
    }
    maxcol = max(maxcol, acc);
    mincol = min(mincol, acc);
  }
  cout << maxel << '\n' << minel << '\n' << maxrw << '\n' << minrw << '\n' << maxcol << '\n' << mincol << '\n';
}

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  int r, c;
  cin >> r >> c;
  vector <vector <int> > org(r, vector <int> (c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> org[i][j];
    }
  }
  for (int qq = 0; qq < tt - 1; qq++) {
    int ra, ca;
    cin >> ra >> ca;
    vector <vector <int> > aux(ra, vector <int> (ca));
    for (int i = 0; i < ra; i++) {
      for (int j = 0; j < ca; j++) {
        cin >> aux[i][j];
      }
    }      
    org = multiply(org, aux);
  }
  get_output(org);
  return 0;
}


