#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

class Solution_684 {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n = edges.size();

      int p[n+1];
      for (int i = 1; i <= n; i++) p[i] = i;

      for (auto item : edges) {
        int u = item[0], v = item[1];
        int a = find(u,p),  b = find(v,p);
        if (a == b) return item;
        else p[a] = b;
      }
      vector<int> res; 
      return res;
    }

    int find (int x, int p[]) {
      if (x != p[x]) p[x] = find(p[x], p);
      return p[x];
    }
};

class Solution_685 {
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    int ind[n+1], outd[n+1];
    memset(ind, 0, sizeof ind);
    unordered_set<int> st;  
    vector<int> res;
    int lastidx = -1;
    int twop = -1;
    for (int i = 0; i < edges.size(); i++) {
        vector<int> e = edges[i];
        int u = e[0], v = e[1];
        st.insert(u); st.insert(v);
        if (st.size() == i + 1 && lastidx < 0) lastidx = i;
        ind[v]++; outd[u]++;
        if (ind[v] > 1) {
          twop= v;
          break;
        }
    }

    if (twop == -1) return edges[lastidx];
    int e1 = -1, e2 = -1;
    for (int i = 0; i < edges.size(); i++) {
      vector<int> e = edges[i];
      if (e[1] == twop) {
        if (e1 >= 0) e2 = i;
        else e1 = i;
      } 
    }

    int p[n+1];
    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 0; i < n; i++) {
      if (i == e1 || i == e2) continue;
      int u = edges[i][0], v = edges[i][1];
      int a = find(u, p), b = find(v, p);
      p[a] = b;
      // if (a == b) return edges[i];
    }

    int u = edges[e1][0], v = edges[e1][1];
    int a = find(u, p), b = find(v, p);
    if (a == b) return edges[e1];
    else return edges[e2];
  }

  int find(int x, int p[]) {
    if (x != p[x]) p[x] = find(p[x], p);
    return p[x];
  }
};



int main() {
  // Solution sol;
  // vector<vector<int>> input = {{1,2},{1,3},{2,3}};
  // vector<int> res = sol.findRedundantConnection(input);
  // for (int x : res) cout << x << " ";
  // cout << endl;


  Solution_685 sol;
  vector<vector<int>> input = {{1,2},{2,3},{3,4},{4,1},{1,5}};
  vector<int> res = sol.findRedundantDirectedConnection(input);
  for (int x : res) cout << x << " ";
  cout << endl;
  
  return 0;
}