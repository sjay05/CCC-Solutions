/**
 *    author:  sjay05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int maxn = 100000 + 5;
int n, m, xx, a, b, max_d, max_n, ans = 0, ret = 0;
bool pho[maxn];
vector<vi> adj(maxn);

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            if (pho[v]) {
                pho[u] = true;
            }
        }
    }
}

void dfs_diam(int n, int p, int dis) {
    if (dis > max_d) {
        max_d = dis;
        max_n = n;
    }
    for (int v : adj[n]) {
        if (v != p && pho[v]) {
            dfs_diam(v, n, dis + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> xx;
        pho[xx] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(xx, -1);
    for (int i = 0; i < n; i++) {
        if (pho[i]) {
            ans++;
        }
    }
    dfs_diam(xx, -1, 0);
    dfs_diam(max_n, -1, 0);
    ret += 2 * (ans - 1);
    cout << ret - max_d << "\n";
}

/*
Process:
- In order to go through all the pho
restaurants we must go into a subtree
if a pho-restaurant is in it. So
first we mark all the nodes we MUST MUST
visit even if it is not a restaurant.


For Ex:
1 -> 2 -> 3
          |
          4
If (4) is a pho, we must visit 3 as there
is no other way of going to 4. So once
mandated nodes are marked, find the number
of such nodes and for now image you went over
all edges twice. If (ans) is the number of
MUST nodes, total edge length will be 2 * (ans - 1),
also since there are N - 1 edges for N nodes
in this problem.

BUT, since it is not mandatory to come back where
we started, we can find the LONGEST distance
we can avoid and this happens to be the diameter
of the tree (longest distance between two nodes).
*/
