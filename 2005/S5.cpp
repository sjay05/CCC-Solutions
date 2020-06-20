#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for (int i=(l); i<(r); ++i)
#define sz(x) (int)(x).size()
#define ps(x) cout << (x) << endl
#define dbg(x) cout << (#x) << ' ' << (x) << endl
#define memfill(x, a) memset((x), (a), sizeof(x))
#define all(x) (x).begin(), (x).end()

typedef string str;
typedef long long int64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const int64 LLINF = 1LL << 60LL;

template <typename T1, typename T2>
ostream& operator<<(ostream& output, const pair<T1,T2> &p) {
    output << "(" << p.first << ", " << p.second << ")";
    return output;
}

/*-------- END OF TEMPLATE --------*/

#define f first
#define s second

typedef double ld;

const int MAX = 1e5 + 5;

int t, s, bit[MAX];

pii arr[MAX];

bool cmp(const pii &a, const pii &b) {
    return a.f < b.s;
}

void upd(int p, int v) {
    for (; p <= t; p += p & -p)
        bit[p] += v;
}

int sum(int l) {
    int res = 0;
    for (; l > 0; l -= l & -l)
        res += bit[l];
    return res;
}

int main() {
    scanf("%i",&t);
    for (int i = 0; i < t; ++i) {
        scanf("%i",&s);
        arr[i] = {s, i+1};
    }
    sort(arr, arr+t); ld ret = 0;
    for (int i = 0; i < t; i++) {
        int xx = arr[i].s; upd(xx, 1);
        ret += xx - sum(xx-1);
    }
    printf("%.2f\n",ret/t);
}
