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

int main() {
    int j; scanf("%i",&j);
    if (j < 4) printf("0\n");
    else {
        if (j == 4) printf("1\n");
        else {
            printf("%i\n",(j-1)*(j-2)*(j-3)/6);
        }
    }

}
