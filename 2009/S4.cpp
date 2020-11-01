#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T>
class graph {
  public:
  struct edge {
    int from, to;
    T cost;
  };
  
  vector <edge> edges;
  vector <vector <int> > g;
  int n;

  graph(int _n) : n(_n) {
    g.reserve(n);
    g.resize(n);
  }

  virtual void add(int from, int to, T cost) = 0;
};

template <typename T>
class undigraph : public graph<T> {
  public:
  using graph<T>::n;
  using graph<T>::g;
  using graph<T>::edge;
  using graph<T>::edges;

  undigraph(int n) : graph<T>(n) {
  }

  void add(int from, int to, T cost = -1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
  }
};

template <typename T>
vector<T> dijkstra(const graph<T> &g, int start) {
  assert(0 <= start && start < g.n);
  vector<T> dist(g.n, numeric_limits<T>::max());
  priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > s;
  dist[start] = 0;
  s.emplace(dist[start], start);
  while (!s.empty()) {
    T expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (dist[i] != expected) {
      continue;
    }
    for (int id : g.g[i]) {
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ i;
      if (dist[i] + e.cost < dist[to]) {
        dist[to] = dist[i] + e.cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist;
}  

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, t;
  cin >> n >> t;
  undigraph<int> g(n);
  for (int i = 0; i < t; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    --x; --y;
    g.add(x, y, c);
  }
  int k;
  cin >> k;
  vector<pair<int, int>> pen(k);
  for (int i = 0; i < k; i++) {
    cin >> pen[i].first >> pen[i].second;
    --pen[i].first;
  }                                   
  int d;
  cin >> d;
  vector<int> dist = dijkstra(g, --d);
  const int inf = numeric_limits<int>::max();
  int ans = inf;  
  for (int i = 0; i < k; i++) {
    int cost = pen[i].second;
    cost += dist[pen[i].first];
    ans = min(ans, cost);
  }
  cout << ans << '\n';
  return 0;
}

