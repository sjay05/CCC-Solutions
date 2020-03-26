/* CCC '20 S4 - Swapping Seats */
// only partials ... (12/15) :-(
#include <bits/stdc++.h>

using namespace std;

constexpr const char sp = ' ';
#define pii pair<int,int>
#define debug(x) cerr<<(#x)<<" = "<<(x)<<endl
#define f first
#define s second

string seq; 
int Ca; // # of A's

pii get_range(int i) {
    int l = (int) seq.size();
    int b, e; b = i;
    if (i + Ca >= l) e = (i + Ca) - l;
    else e = i + Ca;
    return make_pair(b, e);
}

int main() {
    cin >> seq; 
    vector<int> psaB((int) seq.size(), 0);
    for (int c = 0; c < (int) seq.size(); c++) {
        if (seq[c] == 'A') Ca++;
        if (c == 0 && seq[c] == 'B')
            psaB[0] = 1;
        else if (seq[c] == 'B') 
            psaB[c] = psaB[c-1] + 1;
        else
            psaB[c] = psaB[c-1];
    }
    vector<int> buf;
    int l = (int) seq.size();
    for (int i = 0; i < l; i++) {
        pii meta = get_range(i);
        int Bcount;
        if (meta.f > meta.s) {
            Bcount = psaB[l-1] - psaB[meta.f-1];
            if (meta.s != 0) Bcount += psaB[meta.s-1];
        } else {
            if (meta.f == 0) Bcount = psaB[meta.s-1];
            else Bcount = psaB[meta.s-1] - psaB[meta.f-1];
        }
        buf.push_back(Bcount);
    }
    int mi = INT_MAX;
    for (int i : buf)
        mi = min(mi, i);

    cout << mi << endl;
}