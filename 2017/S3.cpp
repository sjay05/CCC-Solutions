/**
 *    author:  sjay05
**/
#include <bits/stdc++.h>

using namespace std;

#define forn(i,l,r) for (int i=(l); i<(r); ++i)
#define sz(x) (int)(x).size()
#define dbg(x) cout << (#x) << ' ' << (x) << endl
#define str string

typedef long long int64;
typedef vector<int> vec_i;
typedef vector<int64> vec_ll;
typedef pair<int,int> pii;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

/*-------- CONSTANTS --------*/

const int MXN = 1000005;
const int MXL = 2001;
int N, arr[MXN];

int main() {
    scanf("%i",&N);
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < N; i++) {
        scanf("%i",&arr[i]);
    }
    int dp[MXL*2], cc[MXL];
    memset(dp, 0, sizeof dp);
    memset(cc, 0, sizeof cc);
    for (int i = 0; i < N; i++) {
        cc[arr[i]] += 1;
    }
    for (int x = 1; x < MXL; x++) {
        for (int y = x; y < MXL; y++) {
            if (x == y) dp[x+y] += cc[x]/2;
            else dp[x+y] += min(cc[x], cc[y]);
        }
    }
    int mh = 0, ff = 0;
    for (int i = 0; i < MXL*2; i++) {
        mh = max(mh, dp[i]);
    }
    for (int i = 0; i < MXL*2; i++) {
        if (dp[i] == mh) ff++;
    }
    printf("%i %i",mh,ff);
}
