/*===================================
#	Author:		sjay05
#	File:		ccc07s5
#	Desc:		Dynamic Programming
#   Link:       https://dmoj.ca/problem/ccc07s5
===================================*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, k, w; cin >> t;
    while (t--) {
        cin >> n >> k >> w;
        vector<int> arr(n), sum(n);
        int dp[k+1][n+1]; 
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum[i] = arr[i];
        }
        for (int i = 0; i < n; ++i) 
            for (int j = 1; j < w; ++j) 
                if (i+j <= (int) arr.size()-1) 
                    sum[i] += sum[i+j];
                
        for (int i = 1; i <= k; ++i) {
            for (int j = n-1; j >= 0; --j) {
                if (i > n-w) 
                    dp[i][j] = sum[j];
                else 
                    dp[i][j] = max(dp[i][j+1], dp[i-1][j+w]+sum[j]);
            }
        }
        cout << dp[k][0] << '\n';
    }
}