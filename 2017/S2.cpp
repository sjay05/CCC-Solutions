/**
 *    author:  sjay05
**/
#pragma GCC optimize("Ofast")
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

const int MXN = 105;
int n, arr[MXN];

int main() {
    scanf("%i",&n);
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; i++) {
        scanf("%i",&arr[i]);
    }
    sort(arr, arr+n);
    if (n % 2 == 0) {
        for (int i = 0; i < n/2; i++) {
            printf("%i %i ",arr[n/2-i-1],arr[n/2+i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= n/2; i++) {
            printf("%i %i ",arr[n/2-i+1],arr[n/2+i]);
        }
        printf("%i\n",arr[0]);
    }
}
