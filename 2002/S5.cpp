#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for (int i=(l); i<(r); ++i)
#define sz(x) (int)(x).size()
#define print(x) cout << (x) << endl
#define dbg(x) cout << (#x) << ' ' << (x) << endl
#define all(x) (x).begin(), (x).end()

typedef string str;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

/* ------ END OF TEMPLATE ------ */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ld n, m, p, q;
    cin >> n >> m >> p >> q;
    ld slp = q / (n - p);
    ld b = -slp * p;
    for (int i = 2*n; ; i += n) {
        ld y = slp * i + b;
        ld val = floor(y / m);
        if (y - (val * m) == q)
            break;
        ld dd = y - (val) * m;
        if (dd < 5.0) {
            int ans = (i / n) + val;
            if (dd == 0.0)
                ans -= 2;
            else
                ans -= 1;
            cout << ans << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}
