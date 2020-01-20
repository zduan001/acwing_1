#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define N 105
typedef pair<int, int> pii;

int n = 10;

vector<int> g[N];

int dijkstra(int src, int distination) {
  int dist[n];
  bool st[n];
  memset(dist, 0x3f, sizeof dist);
  memset(st, false, sizeof st);
  dist[src] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, src});
  while(pq.size()) {
    pii item = pq.top(); pq.pop();
    int u = item.second;
    if (st[u]) continue;
    st[u] = true;
    for (int v : g[u]) {
      int w = (u-v) * (u-v);
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u]+w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist[distination];
}

int main() {
  g[0] = {1,2,3};
  g[1] = {8, 6, 4};
  g[2] = {4, 5, 6};
  g[6] = {1, 9};
  g[8] = {1};
  cout << dijkstra(1, 9) << endl;
  return 0;
}