"""
author: sjay05
"""

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 5;
ll n, k, p, arr[maxn], idx[maxn], seg[4 * maxn], dp[maxn];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    seg[v] = arr[tl];
  } else {
    int mid = (tl + tr) / 2;
    build(v * 2, tl, mid);
    build(v * 2 + 1, mid + 1, tr);
    seg[v] = max(seg[v * 2], seg[v * 2 + 1]);
  }
}

int rmq(int v, int tl, int tr, int l, int r) {
  if (l > r) {
      return INT_MIN;
  }
  if (l == tl && r == tr) {
      return seg[v];
  }
  int mid = (tl + tr) / 2;
  int left_v = rmq(v * 2, tl, mid, l, min(r, mid));
  int right_v = rmq(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
  return max(left_v, right_v);
}

bool chk(int pos) {
  if (idx[pos + 1] == idx[pos])
    return true;
  else
    return false;
}

int main() {
  scanf("%lli%lli",&n,&k);
  for (int i = 1; i <= n; i++) {
    scanf("%lli",&arr[i]);
    idx[i] = (i + k - 1) / k;
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    if (idx[i] != idx[i - 1]) {
      p = max(i - k, 0LL);
    } if (p < i - k) {
      p = i - k;
    }
    dp[i] = dp[p] + rmq(1, 1, n, p + 1, i);
    while (true) {
      int val = rmq(1, 1, n, p + 2, i);
      if (chk(p) && dp[i] <= dp[p + 1] + val) {
        p++;
        dp[i] = dp[p] + rmq(1, 1, n, p + 1, i);
      } else {
        break;
      }
    }
  }
  printf("%lli\n",dp[n]);
}
