/* CCC '13 S4 - Who is Taller? */
#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000001
vector<vector<int>> adj(MAXN);

bool bfs(int src, int dest) {
	vector<bool> visited(MAXN);
	queue<int> q; q.push(src);
	visited[src] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto &x : adj[u]) {
			if (!visited[x]) {
				visited[x] = true;
				q.push(x);
			}
		}
	}
	if (visited[dest]) return true;
	else return false;
}

int main() {
	int N, M, X, Y;
	scanf("%i %i", &N, &M);
	while (M--) {
		scanf("%i %i", &X, &Y);
		adj[X].push_back(Y);
	}
	int p, q; scanf("%i %i", &p, &q);
	if (bfs(p, q)) {
		printf("yes\n");
	} else if (bfs(q, p)) {
		printf("no\n");
	} else {
		printf("unknown\n");
	}
}
