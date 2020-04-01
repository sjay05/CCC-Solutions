/*===================================
#	Author:		sjay05
#	File:		CCC '07 S3 - Friends
#	Desc:		Graph Theory
===================================*/
#include <bits/stdc++.h>

using namespace std;

/*
Editorial:
Build an adj list, out of the input with 
one-directional edges. For the Q queries,
run BFS and maintain visited + dist. If not
visited, return "no", else return dist[dest]-1,
since "degree of seperation" starts from 0.
*/

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rev(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define debug(x) cerr << (#x) << ' ' << x << endl
#define print(x) cout << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

void scan(){}template<class T, class...A>
void scan(T&t, A&...a) { cin >> t, scan(a...); }

/* --- END OF TEMPLATE --- */

#define INF 0x2710

vector<vector<int>> adj(INF);
int n, a, b, x, y;

pair<bool,int> bfs(int src, int dest) {
    queue<int> q; q.push(src);
    vector<bool> visited(INF);
    vector<int> dist(INF);
    visited[src] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &x : adj[u]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                dist[x] = dist[u]+1;
            }
        }
    }
    if (!visited[dest])
        return {false, 0};
    else
        return {true, dist[dest]-1};
}

int main() {
    cin >> n;
    while (n--) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    while (true) {
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        else {
            pii ans = bfs(x, y);
            if (!ans.first) {
                cout << "No\n";
            } else {
                cout << "Yes " << ans.second << endl;
            }
        }
    }
}