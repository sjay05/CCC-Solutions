/**
 *    author:  sjay05
**/
#include <bits/stdc++.h>

using namespace std;

#define forn(i,l,r) for (int i=(l); i<(r); ++i)
#define sz(x) (int)(x).size()
#define dbg(x) cout << (#x) << ' ' << (x) << "\n"
#define str string

typedef long long int64;
typedef vector<int> vec_i;
typedef vector<int64> vec_ll;
typedef pair<int,int> pii;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

/*-------- CONSTANTS --------*/

const int MXN = 105;
int N, arr[MXN];

int main() {
    scanf("%i",&N);
    for (int i = 0; i < N; i++) {
        scanf("%i",&arr[i]);
    }
    double ans = INF;
    sort(arr, arr+N);
    for (int i = 1; i <= N-1; i++) {
        int v1 = abs(arr[i]-arr[i-1]);
        int v2 = abs(arr[i+1]-arr[i]);
        ans = min(ans, v1/2.0 + v2/2.0);
    }
    printf("%.1f\n",ans);
}
