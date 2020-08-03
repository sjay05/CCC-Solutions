/**
 *    author:  sjay05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct ed {
    int u, v, w;
};

bool cmp (ed &a, ed &b) {
    return a.w > b.w;
}

int c, r, d;
vector<ed> edges;
vector<int> id(10001);
vector<bool> dest(10001);

inline int root(int i) {
    while (i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

inline void merge(int p, int q) {
    int a = root(p);
    int b = root(q);
    id[a] = b;
}

int MST() {
    int vis = 0;
    for (ed &e : edges) {
        if (root(e.u) != root(e.v)) {
            if (dest[e.u]) {
                dest[e.u] = false; vis += 1;
            }
            if (dest[e.v]) {
                dest[e.v] = false; vis += 1;
            }
            if (vis == d) {
                return e.w;
            }
            merge(e.u, e.v);
        }
    }
    return 0;
}

int main() {
    scanf("%i%i%i",&c,&r,&d);
    for (int ci = 1; ci <= c; ci++) {
        id[ci] = ci;
    }
    while (r--) {
        int u, v, w;
        scanf("%i%i%i",&u,&v,&w);
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < d; i++) {
        int x; scanf("%i",&x);
        dest[x] = true;
    }
    printf("%i\n", MST());
}
