
#include <iostream>
#include <cstring>

using namespace std;

#define N 305
#define INF 0x3f3f3f3f

int g[N][N];
int dx[N], dy[N];
bool visx[N], visy[N];
int match[N];
int slack[N];

int n, lack;

bool find(int u) {
  visx[u] = 1;
  for (int v = 1; v <=n; v++) {
    if (visy[v]) continue;
    int t = dx[u] + dy[v] - g[u][v];
    if (t==0) {
      visy[v] = true;
      if (match[v] == -1 || find(match[v])) {
        match[v] = u;
        return true;
      }
    }else {
      slack[v] = min(slack[v], t);
    }
  }
  return false;
}

void km() {
  memset(dx, 0, sizeof dx);
  memset(dy, 0, sizeof dy);
  memset(match, -1, sizeof match);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) { 
      dx[i] = max(dx[i], g[i][j]);
    }
  }

  for (int i = 1; i <= n; i++) {
    memset(slack, 0x3f, sizeof slack);
    while(true) {
      memset(visx, false, sizeof visx);
      memset(visy, false, sizeof visy);

      if (find(i)) break;

      int d = INF;
      for (int j = 1; j <= n; j++) {
        if (!visy[j]) d = min(d, slack[j]);
      }

      for (int j = 1; j <= n; j++) {
        if (visx[j]) dx[j] -=d;
        if (visy[j]) dy[j] +=d;
        else slack[j] -= d;
      }
    }
  }
}

int main() {
  while(cin >> n, n) {
    int i, j, res = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> g[i][j];
      }
    }
    km();
    for (int i = 1; i <= n; i++) {
      res += g[match[i]][i];
    }
    cout << res << endl;
  }
  return 0;
}

// input
// 2
// 100 10
// 15 23
// out put :
// 123

// input: 
// 3
// 3 0 4
// 2 1 3
// 0 0 5
// output:
// 9
