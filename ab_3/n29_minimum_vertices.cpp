#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define N 105

int n;
vector<int> g[N];
int low[N], dfn[N];
int timestamp, top;
bool in_stk[N];
stack<int> stk;
int din[N], dout[N];
int id[N], scc_cnt;

void tarjan(int u) {
  dfn[u] = low[u] = ++timestamp;
  stk.push(u); in_stk[u] = true;
  for (auto v : g[u]) { // 1. wrote g[u] as g[N]. 
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if(in_stk[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }

  if (dfn[u] == low[u]) {
    scc_cnt++;
    int y;
    do{
      y = stk.top(); stk.pop();
      in_stk[y] = false;
      id[y] = scc_cnt;
    } while(y!= u);
  }
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int b; 
    while(cin >> b, b) {
      g[i].push_back(b);
    }
  }
  for (int i = 1;i <=n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  for (int u = 1;u <= n; u++) {
    for (int v : g[u]) {
      int a = id[u], b = id[v];
      if (a!= b) {
        dout[a]++;
        din[b]++;
      }
    }
  }

  int zout = 0, zin = 0;
  for (int i = 1;i <= scc_cnt; i++) {
    if (din[i] == 0) zin++;
    if (dout[i] == 0) zout++;
  }

  cout << zin << endl;
  if (scc_cnt==1) cout << 0 << endl;
  else cout << max(zin, zout) << endl;
  return 0;
}
