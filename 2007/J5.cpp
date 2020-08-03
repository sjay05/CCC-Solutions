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

int64 A, B, M, dp[100];
vector<int> pos = {0, 990, 1010, 1970, 2030, 2940, 3060, \
                3930, 4060, 4970, 5030, 5990, 6010, 7000};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> M;
    if (M != 0) {
        for (int i = 1; i <= M; i++) {
            int x; cin >> x;
            pos.push_back(x);
        }
    }
    memset(dp, 0, sizeof dp);
    sort(pos.begin(), pos.end()); dp[0] = 1;
    for (int i = 1; i < sz(pos); i++) {
        for (int j = i-1; j >= 0; j--) {
            int dif = pos[i]-pos[j];
            if (dif >= A && dif <= B) {
                dp[i] += dp[j];
            }
        }
    }
    cout << dp[sz(pos)-1] << "\n";
}
