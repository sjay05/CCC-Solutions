#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace rng_distribution {

int int_r(int a, int b) {
  return uniform_int_distribution<>(a, b)(rng);
}

double real_r(double a, double b) {
  return uniform_real_distribution<>(a, b)(rng);
}                                                 

string string_r(int len) {
  const string alpha = "abcdefghijklmnopqrstuvwxyz";
  string ret = "";
  for (int i = 0; i < len; i++) {
    ret += alpha[rng() % (alpha.size() + 1)];
  }
  return ret;
}  

template <typename T>
void shuffle(vector<T> &a) {
  int n = (int) a.size();
  for (int i = 0; i < n; i++) {
    swap(a[i], a[rng() % (i + 1)]);
  }
}
}; 

using namespace rng_distribution;

template <class T>
vector<T> create(size_t size, T initialValue) {
  return vector<T>(size, initialValue);
}

template <class T, class... Args>
auto create(size_t head, Args&&... tail) {
  auto inner = create<T>(tail...);
  return vector<decltype(inner)>(head, inner);
}

auto arr = create<int>(3, 3, 0);
auto bad = create<int>(3, 3, 0);

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cnt = 0;
  int inf = -1;
  vector<int> nums;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      string s;
      cin >> s;
      if (s == "X") {
        cnt += 1;
        bad[i][j] = 1;
      } else {
        arr[i][j] = atoi(s.c_str());
        nums.push_back(arr[i][j]);
      }
    }
  }
  if (cnt == 9) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (j > 0) {
          cout << " ";
        }
        cout << 0;
      }
      cout << '\n';
    }
    return 0;
  }
  sort(nums.begin(), nums.end());
  inf = -1000000001;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (bad[i][j]) {
        arr[i][j] = inf;
      }
    }
  }
  while (true) {
    vector <vector <int> > a = arr;
    auto find_col = [&](int c) {
      int cnt = 0;
      for (int i = 0; i < 3; i++) {
        cnt += (a[i][c] == inf ? 0 : 1);
      }
      return cnt;
    };
    auto find_row = [&](int c) {
      int cnt = 0;
      for (int i = 0; i < 3; i++) {
        cnt += (a[c][i] == inf ? 0 : 1);
      }
      return cnt;
    };
    auto check = [&]() {
      bool ok = true;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (a[i][j] == inf) {
            ok = false;
            break;
          }
        }
        if (!ok) {
          break;
        }
      }
      if (!ok) return false;
      for (int i = 0; i < 3; i++) {
        int d1 = a[i][0] - a[i][1];
        int d2 = a[i][1] - a[i][2];
        if (d1 != d2) {
          return false;
        }
      }
      for (int i = 0; i < 3; i++) {
        int d1 = a[0][i] - a[1][i];
        int d2 = a[1][i] - a[2][i];
        if (d1 != d2) {
          return false;
        }
      }
      return true;
    };
    auto fill_row = [&](int i, int j) {
      if (j == 1) {
        int d = a[i][2] - a[i][0];
        a[i][j] = a[i][0] + (d / 2);
      } else if (j == 0) {
        int d = a[i][2] - a[i][1];
        a[i][j] = a[i][1] - d;
      } else if (j == 2) {
        int d = a[i][1] - a[i][0];
        a[i][j] = a[i][1] + d;
      }
    };
    auto fill_col = [&](int i, int j) {
      if (i == 1) {
        int d = a[2][j] - a[0][j];
        a[i][j] = a[0][j] + (d / 2);
      } else if (i == 0) {
        int d = a[2][j] - a[1][j];
        a[i][j] = a[1][j] - d;
      } else if (i == 2) {
        int d = a[1][j] - a[0][j];
        a[i][j] = a[1][j] + d;
      }
    };
    auto fill_all = [&]() {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (a[i][j] != inf) {
            continue;
          } if (find_row(i) == 2) {
            fill_row(i, j);
          } else if (find_col(j) == 2) {
            fill_col(i, j);
          }
        }  
      }
    };
    auto find_bad = [&]() {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (a[i][j] == inf) {
            return false;
          }
        }
      }
      return true;
    };
    bool ok = false;
    auto check_bad = [&]() {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (a[i][j] == inf) {
            if (find_row(i) >= 2) {
              return true;
            } if (find_col(j) >= 2) {
              return true;
            }
          }
        }
      }
      return false;
    };
    while (1) {
      while (check_bad()) {
        fill_all();
      }
      if (check()) {
        ok = true;
        break;
      }
      if (find_bad()) {
        break;
      }
      for (int i = 0; i < 3; i++) {
        bool ff = 0;
        for (int j = 0; j < 3; j++) {
          if (a[i][j] == inf) {
            a[i][j] = int_r(-1000000, 1000000);
            ff = 1;
            break;
          }
        }
        if (ff) break;
      }
    }
    if (ok) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (j > 0) {
            cout << " ";  
          }
          cout << a[i][j];
        }
        cout << '\n';
      }
      break;
    } 
  }
  return 0;
}
