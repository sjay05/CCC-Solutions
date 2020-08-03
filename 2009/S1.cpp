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

bool chk2 (int x) {
    double sr = sqrt(x);
    return ((sr - floor(sr)) == 0);
}

bool chk3 (int x) {
    int root(round(cbrt(x)));
    return x == root * root * root;
}

int main() {
    int a, b, cnt = 0;
    scanf("%i%i",&a,&b);
    for (int i = a; i <= b; i++) {
        if (chk2(i) && chk3(i)) {
            cnt++;
        }
    }
    printf("%i\n",cnt);
}
