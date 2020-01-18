#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
#define Matrix vector<vector<int>>

Matrix adj(MAXN);
int dp[MAXN];

int main() {
    int n; scanf("%d", &n);
    while (true) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 0 and y == 0) break;
        if (x || y) adj[x].push_back(y);
    }
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            dp[j] += dp[i];
        }
    }
    printf("%d\n", dp[n]);
}