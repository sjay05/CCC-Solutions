#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; scanf("%i", &N);
    vector<pair<int,int>> pts(N+1);
    for (int i = 1; i <= N; i++) {
        scanf("%i%i", &pts[i].first, &pts[i].second);
    }
    vector< pair< int,pair<int,int> > > gs;
    vector<int> dp(N+1), mtain(N+1), dist(N+1); 
    for (int x = 0; x <= N; x++) {
        for (int y = x+1; y <= N; y++) {
             int diff_x = pts[x].first - pts[y].first;
             int diff_y = pts[x].second - pts[y].second;
             gs.push_back({pow(diff_x, 2) + pow(diff_y, 2), {x, y}});
        }
    }
    sort(gs.begin(), gs.end());
    for (auto p : gs) {
        int d = p.first;
        auto a = p.second.first;
        auto b = p.second.second;
        if (d != dist[a]) {
            dist[a] = d;
            mtain[a] = dp[a];
        } if (d != dist[b]) {
            dist[b] = d;
            mtain[b] = dp[b];
        } if (a == 0) {
            dp[a] = max(dp[a], mtain[b]);
        } else {
            dp[a] = max(dp[a], mtain[b]+1);
            dp[b] = max(dp[b], mtain[a]+1);
        }
    }
    printf("%i\n", dp[0]+1);
}