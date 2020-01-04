#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define N 10005

int n, m;
vector<int> g[N];
int dfn[N], low[N];
bool in_stk[N];
stack<int> stk;
int timestamp;
int id[N];
int dout[N], din[N];
int sizer[N];
int scc_cnt;

void tarjan(int u) {
  dfn[u] = low[u] = ++timestamp;
  stk.push(u); in_stk[u] = true;
  for (int v : g[u]) {
    if (!dfn[v]) {
        tarjan(v);
        low[u] = min (low[u], low[v]);
    } else if (in_stk[v]){
        low[u] = min (low[u], dfn[v]);
    }
  }
  
  if (dfn[u] == low[u]) {
    int y;
    ++scc_cnt;
    do {
        y = stk.top(); stk.pop();
        in_stk[y] = false;
        id[y] = scc_cnt;
        sizer[scc_cnt]++;
    } while (y != u);
  }
}

// this is acwing_1174. which is almost same as 
// min_node_travel all.
int main() {
  cin >> n >> m;
  for (int i = 0;i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }

  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }

  for (int u = 1; u <= n; u++) {
    for (auto v : g[u]) {
      int a = id[u], b = id[v];
      if (a!=b) {
        dout[a]++;
        din[b]++;
      }
    }
  }

  int res = 0, sum = 0;
  for (int i = 1; i <= scc_cnt; i++) {
    if (!dout[i]) {
      res = sizer[i];
      if (sum != 0) {
        sum = 0; break;
      }
    }
    sum = res;
  }

  cout << sum << endl;
  return 0;
}
