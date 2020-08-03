/**
 *    author:  sjay05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m, a[3005], b[3005];
int dp[3005][2][105][105];

int rec(int pos, int tak, int l, int r) {
    int &ret = dp[pos][tak][l][r];
    if (ret != -1) return ret;
    if (pos == n + 1) {
        // gone through all a's
        if (l <= r) { // haven't done all b's
            if (tak == 1) return ret = b[r] + rec(pos, 0, l, r - 1); // use b's greatest
            return ret = rec(pos, 1, l + 1, r); // skip and use b's (least)
        }
        return ret = 0;
    } if (tak == 1) {
        // regular case and we must take
        // 1) skip it 2) take it and add price
        ret = max(rec(pos, 0, l, r), a[pos] + rec(pos+1, 0, l, r));
        if (l <= r) ret = max(ret, b[r]+rec(pos, 0, l, r-1));
    } else {
        // must skip
        // 1) skip a's 2) skip b's
        ret = max(ret, rec(pos + 1, 1, l, r));
        if (l <= r) ret = max(ret, rec(pos, 1, l + 1, r));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(b + 1, b + 1 + m);
    cout << rec(1, 1, 1, m) << "\n";
}
