/**
 *    author:  sjay05
**/
#include <bits/stdc++.h>

using namespace std;

int r, c, k, a, b;
int cats[30][30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> r >> c >> k;
    memset(cats, 0, sizeof(cats));
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        cats[a][b] = 1;
    }
    int dp[30][30];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (cats[i][j] == 0) {
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    cout << dp[r][c] << endl;
}
