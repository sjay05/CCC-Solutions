/**
 *    author:  sjay05
**/
/*
TLE - 20/100 (Doesn't Pass All Test Cases)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const int MXN = 5050;

int n, t, k, d;
map<int,int> pen;

int adj[MXN][MXN];
vector<int> dist(MXN, INF);
vector<bool> vis(MXN, false);

void dijk(int u) {
    vis[u] = true; // mark true
    for (int _m = 1; _m <= n; _m++) {
        if (!vis[_m]) {
            if (dist[u] + adj[u][_m] < dist[_m])
                // only if < inf
                dist[_m] = dist[u] + adj[u][_m];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;
    for (int i = 0; i < t; i++) {
        int x, y, co; cin >> x >> y >> co;
        // bi-direct
        adj[x][y] = co;
        adj[y][x] = co;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int z, p_z; cin >> z >> p_z;
        // assign map
        pen[z] = p_z;
    }
    cin >> d; dist[d] = 0;
    for (int i = 0; i < n; i++) {
        int u_v = 0; // pick arbitrary node unvis
        for (int no = 1; no <= n; no++) {
            if (!vis[no] && dist[no] < dist[u_v])
                // not vis and less dist (!inf)
                u_v = no;
        }
        dijk(u_v);
    }
    int min_d = dist[d] + pen[d];
    for (int x = 1; x <= n; x++) {
        min_d = min(min_d, dist[x]+pen[x]);
    }
    cout << min_d << "\n";
}
