#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    int res = 0;
    int n = grid.size(), m = grid[0].size();
    for(int i = 0;i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int cnt = 0;
        for (int k = 0; k < m; k++) {
          if (grid[i][k] && grid[j][k]) cnt++;
        }
        if (cnt > 1) res += (cnt * (cnt -1))/2;
      }
    }
    return res;
  }
};

int main() {
  vector<vector<int>> input = {{1,1,1}, {1,1,1}, {1,1,1}};
  Solution sol;
  cout << sol.countCornerRectangles(input) << endl;
  return 0;
}