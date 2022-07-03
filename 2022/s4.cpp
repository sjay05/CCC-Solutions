#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  vector<int> p(n);
  vector<long long> cnt(c);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    cnt[p[i]] += 1;
  }
  long long all = accumulate(cnt.begin(), cnt.end(), 0LL);
  int id = -1;
  for (int i = 0; i < c; i++) {
    if (cnt[i] > 0) {
      id = i;
      break;
    }
  }
  int L = id;
  int R = (L + c / 2) % c;
  long long cur = 0;
  if (L < R) {
    for (int i = L; i <= R; i++) {
      cur += cnt[i];
    }
  } else {
    for (int i = R; i <= L; i++) {
      cur += cnt[i];
    }
    cur -= cnt[L] - cnt[R];
    cur = all - cur;
  }
  auto Get2 = [&](long long x) {
    return x * (x - 1) / 2;
  };
  auto Get3 = [&](long long x) {
    return x * (x - 1) * (x - 2) / 6;
  };
  long long val = 0;
  while (L < c) {
    if (cnt[L] > 0) {
      long long use = cur;
      val += cnt[L] * Get2(use - cnt[L]);
      val += Get2(cnt[L]) * (use - cnt[L]);
      val += Get3(cnt[L]);
      if (c % 2 == 0 && L > R && cnt[L] > 0 && cnt[R] > 0) {
        val -= cnt[L] * Get2(cnt[R]);
        val -= Get2(cnt[L]) * cnt[R];
      } 
    }
    if (L == c - 1) {
      break;
    }
    cur -= cnt[L];
    L = (L + 1) % c;
    R = (R + 1) % c;
    cur += cnt[R];
  }
  cout << Get3(n) - val << '\n';
  return 0;
}

