#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
typedef pair<int,int> pii;

int N, M;
int arr[1005][1005];
bool visited[1005][1005];
vector<vector<pii>> helper(1e6+5);

string bfs(pii src) {
    queue<pii> q;
    q.push(src);
    visited[src.f][src.s] = true;
    while (!q.empty()) {
        pii u = q.front(); q.pop();
        int r = u.f; int c = u.s;
        for (pii v : helper[r*c]) {
            if (v.f == 1 && v.s == 1) {
                return "yes";
            }
            if (!visited[v.f][v.s]) {
                visited[v.f][v.s] = true;
                q.push(v);
            }
        }
    }
    return "no";
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        int X;
        for (int j = 0; j < N; j++) {
            cin >> X; arr[i][j] = X;
            helper[X].push_back({i+1,j+1});
        }
    }
    cout << bfs({N, M}) << endl;
}