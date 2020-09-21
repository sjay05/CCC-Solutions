#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T>
class fenwick2d {
  public:
  vector <vector <T> > fenw;
  int n, m;

  fenwick2d(int _n, int _m) : n(_n), m(_m) {
    fenw.resize(n);
    for (int i = 0; i < n; i++) {
      fenw[i].resize(m);
    }
  }
  void modify(int i, int j, T v) {
    int x = i;
    while (x < n) {
      int y = j;
      while (y < m) {
        fenw[x][y] = max(fenw[x][y], v);
        y += (y & -y);
      }
      x += (x & -x);
    }
  }
  T get(int i, int j) {
    T v{};
    int x = i;
    while (x > 0) {
      int y = j;
      while (y > 0) {
        v = max(v, fenw[x][y]);
        y -= (y & -y);
      }
      x -= (x & -x);
    }
    return v;
  }
};

const int N = 3000 + 5;

int a[N][N];

int main() {
#ifdef lc
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = n; j > (n - i); j--) {
      cin >> a[i][j];
    }
  }
  fenwick2d<long long> ft(N + 2, N + 2);
  long long ret = 0;
  for (int rw = 0; rw < n; rw++) {
    for (int jp = 0; jp <= rw; jp++) {
      pair<int, int> pos = {n - jp, n - rw + jp};
      assert(n - jp >= 1 && n - jp <= n); 
      ft.modify(pos.first, pos.second, {a[pos.first][pos.second]});
    } 
    int clm = rw - k;
    if (rw >= (k - 1)) {
      for (int jp = 0; jp <= clm + 1; jp++) {
        pair<int, int> pos2 = {n - jp, n - (clm + 1) + jp};
        ret += ft.get(pos2.first, pos2.second);
      }
    }
  }
  cout << ret << '\n';
  return 0;
}

