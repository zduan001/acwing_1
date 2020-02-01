#include <bits/stdc++.h>

using namespace std;


// class Solution3 {
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int x) {
//       int dist[n][n];
//       memset(dist, 0x3f, sizeof dist);
//       for (int i = 0;i < n; i++) dist[i][i] = 0;
//       for (int k = 0; k < edges.size(); k++) {
//         int u = edges[k][0];
//         int v = edges[k][1];
//         int w = edges[k][2];
//         dist[u][v] = w;
//         dist[v][u] = w;
//       }

//       for(int k = 0; k< n; k++) {
//         for (int i = 0; i < n; i++) {
//           for(int j = 0; j < n; j++) {
//             if (dist[i][j] > dist[i][k] + dist[k][j]) {
//               dist[i][j] = dist[i][k] + dist[k][j];
//             }
//           }
//         }
//       }

//       vector<int> p[n];
//       for(int i = 0;i < n; i++) {
//         int cnt = 0;
//         for (int j = 0; j < n ; j++) {
//           if (i == j ) continue;
//           if (dist[i][j] <= x ) cnt++;
//         }
//         p[cnt].push_back(i);
//       }

//       int i;
//       for (i = 0;i < n; i++) {
//         if (p[i].size() > 0) break;
//       }
//       if (p[i].size() == 0 ) return -1;
//       sort(p[i].begin(), p[i].end());
//       reverse(p[i].begin(), p[i].end());
//       return p[i][0];

//     }
// };

// #define N 305

// class Solution2 {
// public:
//     int minDifficulty(vector<int>& jobDifficulty, int d) {
        
//     }


//     int m, p;

//   struct Node {
//       int l, r;
//       int v;
//   } tr[4*N];


//   void build(int u, int l, int r) {
//       tr[u] = {l,r};
//       if (l == r) return;
//       int mid = (l+r) >> 1;
//       build(u<<1, l, mid);
//       build((u<<1)+1, mid+1, r);
//   }

//   void push_up(int u) {
//       tr[u].v = max(tr[u<<1].v, tr[u<<1|1].v);
//   }

//   int query(int u, int l, int r) {
//       if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
      
//       int mid = tr[u].l + tr[u].r >> 1;
//       int v = 0;
//       if (l <= mid) v = query(u << 1, l, r);
//       if (r > mid) v = max(v, query(u<<1|1, l, r));
//       return v;
//   }

//   void update(int u, int x, int v) {
//       if (tr[u].l == x && tr[u].r == x) tr[u].v = v;
//       else {
//           int mid = tr[u].l + tr[u].r >> 1;
//           if (x <= mid) update (u<<1, x, v);
//           else update(u<<1|1, x, v);
//           push_up(u);
//       }
//   }
// };
// need to study the last question very carefully, I feel
// I always fail this type of question.

// class Solution {
// public:
//     int minDifficulty(vector<int>& a, int d) {
//       int n = a.size();
//       if (d > n) return -1;
//       int dp[n][d+1];
//       memset(dp, 0x3f, sizeof dp);

//       for (int i = 0; i < n; i++) {
//         int dif = a[i];
//         for (int j = i; j >=0 ; j--) {
//           dif = max(dif, a[j]);
//           if (j == 0) dp[i][1] = dif;
//           else {
//             for (int k = 2; k <=d; k++) {
//               dp[i][k] = max(dp[i][k], dif+ dp[j-1][k-1]);
//             }
//           }
//         }
//       }
//       return dp[n-1][d];
//     }
// };


class Solution {
public:
    int minDifficulty(vector<int>& a, int d) {
      memset(dp, 0x3f, sizeof dp);
      int res = dfs(0, d, a);
      return res == INF ? -1 : res;
    }

    int dfs(int idx, int d, vector<int>& a) {
      if (d == 0)   {
        if (idx == a.size()) return 0;
         return INF;
      }
      if(idx == a.size()) return INF;

      if(dp[idx][d] == INF) {
        int dif = 0;
        for(int i = idx; i < a.size(); i++) {
          dif = max(dif, a[i]);
          dp[idx][d] = min(dp[idx][d], dif+dfs(i+1, d-1, a));
        }
      }
      return dp[idx][d];
    }
private:
  int dp[305][12];
  const int INF = 0x3f3f3f3f;
};



int main() {
  return 0;

}


