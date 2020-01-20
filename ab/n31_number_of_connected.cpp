#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef pair<int, int> pii;

// leetcode 323
class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
      int p[n];
      for (int i = 0;i <n; i++) p[i] = i;
      for(int i = 0;i < edges.size(); i++) {
        int a = edges[i].first;
        int b = edges[i].second;

        int x = find(a, p), y = find(b, p);
        if (x!=y) p[x] = y;
      }

      set<int> s;
      for (int i = 0;i<n;i++) {
        s.insert(find(i, p));
      }
      return s.size();
    }
private:
    int find(int x, int p[]) {
      if (x != p[x]) p[x] = find(p[x], p);
      return p[x];
    }
};

int main() {
  vector<pii> edges = {{0,1}, {1,2}, {3,4}, {2,3}};
  Solution sol;
  cout << sol.countComponents(5, edges) << endl;
  return 0;
}
