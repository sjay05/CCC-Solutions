#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000;
int N, A, B;
vector<vector<int>> adj(MAXN);
vector<int> arr(MAXN);

int main() {
    scanf("%d", &N);
    while (true) {
        scanf("%d %d", &A, &B);
        if (A == 0 && B == 0) {
            break;
        }
        adj[A].push_back(B);
    }

    arr[1] = 1;
    for (int i = 1; i <= N; i++) {
        for (auto u : adj[i]) {
            arr[u] += arr[i];
        }
    }
    printf("%d\n", arr[N]);

}