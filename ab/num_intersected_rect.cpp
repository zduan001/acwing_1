// use leetcode 323 as the decription.
#include <iostream>
#include <vector>
#include <unordered_set> 

using namespace std;

#define N 1005

typedef pair<int, int> pii;

class Solution{
public:
  int countComponent(int n, vector<pii>& edges) {
    for (int i = 0;i < n; i++) p[i] = i;

    for (auto edge : edges) {
      int x = edge.first, y = edge.second;
      int a = find(x), b = find(y);
      if (a!= b) {
        p[a] = b;
        // find(a);
      }
    }

    unordered_set<int> s;
    for (int i = 0;i < n; i++) {
      find(i);
      s.insert(p[i]); 
    }
    return s.size();
  }

  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }

private: 
  int p[N];
};

int main() {
  vector<pii> edges = {{0,1}, {1,2}, {3,4}};
  Solution sol;
  cout << sol.countComponent(5, edges) << endl;
  
  return 0;
}
