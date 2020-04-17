#include <bits/stdc++.h>

using namespace std;

struct ed {
    int u, v, w;
    int qu;
};

bool cmp(ed &a, ed &b) {
    if (a.w == b.w)
        return a.qu < b.qu;
    else
        return a.w < b.w;
}

int n, m, d, a, b, c;

const int MAXN = 1000005;
vector<int> id(MAXN);
vector<ed> edges;

int root(int i) {
    while (i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void merge(int p, int q) {
    int a = root(p);
    int b = root(q);
    id[a] = b;
}

int MST() {
    int num = 0, cost = 0;
    for (ed &e : edges) {
        if (root(e.u) != root(e.v)) {
            if (e.qu >= n) {
                num += 1;
            }
            cost += e.w;
            merge(e.u, e.v);
        }
    }
    return num;
}

int main() {
    for (int i = 0; i < MAXN; i++)
        id[i] = i;

    cin >> n >> m >> d;
    int co = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        ed e = {a, b, c, ++co};
        edges.push_back(e);
    }
    sort(edges.begin(), edges.end(), cmp);
    int ans = MST();
    cout << ans << endl;
    // for (ed &e : edges) {
    //     cout << e.u << " " << e.v << " " << e.w << " " << e.qu << endl;
    // }
}
