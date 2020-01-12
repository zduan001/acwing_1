#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <sstream>

using namespace std;

#define N 505
#define M 105

typedef pair<int, int> pii;

int n, m;
bool g[N][N];
int stop[N];
int dist[N];
bool st[N];

void dijkstra() {
  priority_queue<pii, vector<pii>, greater<pii>> p;
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;

  p.push({dist[1], 1});
  while(p.size()) {
    auto item = p.top();p.pop();
    int u = item.second;
    if (st[u]) continue;
    st[u] = true;
    for(int v = 1; v <= n; v++) {
      if (g[u][v] && dist[v] > dist[u]+1) {
        dist[v] = dist[u]+1;
        p.push({dist[v], v});
      }
    }
  }
}
// 这个方法在一条线路的每个站之间都建一条路，然后计算最短路。 换乘次数就是追段路 减 1
// 还有一种办法，把每个站拆点成每条路+点，一条线路之间的距离是0. 在一个车站不同线路之间
// 的距离为一。

int main(){
  cin >> m >> n;
  string line;
  getline(cin, line); // take out the last new line character.
  memset(g, false, sizeof g);

  for (int i = 0; i < m; i++) {
    getline(cin, line);
    stringstream ssin(line);
    int cnt = 0, p;
    while(ssin>>p) stop[cnt++] = p;
    for (int i = 0; i < cnt; i++) {
      for (int j = i+1; j < cnt; j++) {
        g[stop[i]][stop[j]]= true;
      }
    }
  }
  dijkstra();
  if(dist[n] == 0x3f3f3f3f) cout << "NO";
  else {
    if (dist[n] == 0) cout << 0;
    else cout << dist[n]-1;
  }
  cout << endl;
}
