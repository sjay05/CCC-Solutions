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

int y;

int main() {
    scanf("%i",&y);
    y += 1;
    while (true) {
        string s = to_string(y);
        bool ft = false;
        for (int i = 0; i < sz(s); i++) {
            for (int j = i+1; j < sz(s); j++) {
                if (s[j] == s[i]) ft = true;
                else continue; 
            }
        }
        if (!ft) {
            printf("%i\n",y);
            break;
        } else {
            y++;
        }
    }
}