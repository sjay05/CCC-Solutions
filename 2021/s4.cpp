#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w, d;
  cin >> n >> w >> d; 
  vector<vector<int>> g(n);
  for (int i = 0; i < w; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[y].push_back(x);
  }
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<int> dist(n, inf);
  dist[n - 1] = 0;
  vector<int> que(1, n - 1);
  for (int b = 0; b < (int) que.size(); b++) {
    for (int to : g[que[b]]) {  
      if (dist[to] > dist[que[b]] + 1) {
        dist[to] = dist[que[b]] + 1;
        que.push_back(to);
      }
    }
  } 
  multiset<pair<int, int>> st;
  for (int i = 0; i < n; i++) {   
    if (dist[p[i]] == -1) {
      st.insert({inf, p[i]});
      continue;
    }
    st.insert({i + dist[p[i]], p[i]});
  }
  while (d--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    st.erase({x + dist[p[x]], p[x]});
    st.insert({y + dist[p[x]], p[x]});
    st.erase({y + dist[p[y]], p[y]});
    st.insert({x + dist[p[y]], p[y]});
    swap(p[x], p[y]); 
    auto mn = st.begin();
    cout << mn->first << '\n';
  }
  return 0;
}
