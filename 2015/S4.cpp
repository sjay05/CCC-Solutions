/**
 *    author:  sjay05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define bool_operator friend bool operator
#define _ed const ed

struct ed {
    int b, t, h;
    bool_operator <(_ed &a, _ed &b) {
        return a.t > b.t;
    }
};

const int MXN = 5050;
const int INF = 0x3f3f3f3f;

int k, n, m, sr, de;
vector<vector<ed>> adj(MXN);
vector<vector<int>> dist(MXN, vector<int>(MXN, INT_MAX));

void dijk() {
    priority_queue<ed> q;
    dist[sr][0] = 0; q.push({sr, 0, 0});
    while (!q.empty()) {
        ed u = q.top(); q.pop();
        if (u.b == de) break;
        for (ed v : adj[u.b]) {
            int dam = u.h + v.h;
            if (dam < k && u.t + v.t < dist[v.b][dam]) {
                dist[v.b][dam] = u.t + v.t;
                q.push({v.b, u.t+v.t, dam});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }

    cin >> sr >> de; dijk();

    int min_el = INT_MAX;
    for (int i = 0; i <= k; i++) {
        if (dist[de][i] < min_el) {
            min_el = dist[de][i];
        }
    }
    if (min_el == INT_MAX) cout << -1 << "\n";
    else cout << min_el << "\n";
}
