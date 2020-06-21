/*===================================
#	Author:		sjay05
#	File:		ccc07s5
#	Desc:		Dynamic Programming
===================================*/
// Link:       https://dmoj.ca/problem/ccc07s5

#include <bits/stdc++.h>

using namespace std;

/*
To solve this problem, we must employ
a 2D dynamic programming approach. First,
we need a (sum) array. For any given pin
we need to know the sum of the next (width)
pins. For example, if our pin was (i), and 
the width was 3, then sum[i] =  sum[i] + 
sum[i+1] + sum[i+2]. 

Example:
  Pins: 2   8   5   1   9   6   9   3   2 
  Sums: 15  14  15  16  24  18  14  5   2

Next, we need to decide how to solve this 
problem by solving sub-problems. We going to 
have a 2D dp array. Our state is going to be 
dp[i][j], (i) being the number of bowling 
balls used, and (j) being the number of pins
we are solving the sub-problem for. We start
with 0 bowling balls, and this means all of
dp[0] will be 0. We will be iterating (j) from
right to left.

For any dp[i][j] (i != 0) - we are given two 
options. For any dp[i][j] it is the max out of 
the two:

1) Don't add (i) in group, and use the result
one to the right
2) Include (i) and include the result (idx+width)
places to the right. 
*/

void io() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}

int main() {
  int t, n, k, w; cin >> t; 
  while (t--) {
    cin >> n >> k >> w;
    vector<int> arr(n), sum(n);
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      sum[i] = arr[i];
    }
    for (int i = 0; i < n; ++i)
      for (int j = 1; j < w; ++j)
        if (i + j <= (int) arr.size() - 1) 
            sum[i] += sum[i + j];

    for (int i = 1; i <= k; ++i) {
      for (int j = n - 1; j >= 0; --j) {
        if (i > n - w)
          dp[i][j] = sum[j];
        else
          dp[i][j] = max(dp[i][j + 1], dp[i - 1][j + w] + sum[j]);
      }
    }
    cout << dp[k][0] << '\n';
  }
}