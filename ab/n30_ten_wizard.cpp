#include <iostream> 
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define N 20

typedef pair<int, int> pii;

vector<int> g[N];
int dist[N];
bool st[N];

int dijkstra(int s, int e) {
  priority_queue<pii, vector<pii>, greater<pii>> q;
  memset(dist, 0x3f, sizeof dist);
  dist[s] = 0;
  q.push({0, s});

  while(q.size()) {
    pii front = q.top(); q.pop();
    int u = front.second;
    if (st[u]) continue;
    st[u] = true;
    for (int v : g[u]) {
      int w = (u-v) * (u-v);
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u]+w;
        q.push({dist[v], v});
      }
    }
  }
  return dist[e];
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
