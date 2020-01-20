#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

class Solution {
public:
  vector<string> findOcean(vector<string> land, int x, int y) {
    int n = land.size(), m = land[0].size();
    queue<pii> q;
    q.push({x,y});

    while(q.size()) {
      auto item = q.front(); q.pop();
      int a = item.first, b = item.second;
      if (land[a][b] != 'W') continue;
      land[a][b] = 'O';
      for (int i = 0;i < 4; i++) {
        int x = a+ dx[i], y = b + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (land[x][y] == 'W') q.push({x,y});
      }
    }
    return land;
  }
private:
  int dx[4] = {0,0,-1,1};
  int dy[4] = {-1,1,0,0};
};

int main()  {
  vector<string> input = {"WWWLLLW", "WWLLLWW", "WLLLLWW"};

  Solution sol;
  vector<string> res = sol.findOcean(input, 0, 1);
  for (string str : res) {
    cout << str << endl;
  }
  return 0;
}

// should also look at 
// • Leetocde #200 Number of Islands
// • Leetocde #305 Number of Islands II
// • Leetocde #694 Number of Distinct Islands
// • Leetocde #711 Number of Distinct Islands
// • Leetocde #695 Max area of Islands
// • Leetcode #463 Island Perimeter