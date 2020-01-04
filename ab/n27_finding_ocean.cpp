/**
* Given: An array of strings where L indicates land and W indicates water,
* and a coordinate marking a starting point in the middle of the ocean.
*
* Challenge: Find and mark the ocean in the map by changing appropriate Ws to Os.
* An ocean coordinate is defined to be the initial coordinate if a W, and
* any coordinate directly adjacent to any other ocean coordinate.
*
* void findOcean(String[] map, int row, int column);
*
* String[] map = new String[]{
* "WWWLLLW",
* "WWLLLWW",
* "WLLLLWW"
* };
* printMap(map);
*
* STDOUT:
* WWWLLLW
* WWLLLWW
* WLLLLWW
*
* findOcean(map, 0, 1);
*
* printMap(map);

*
* STDOUT:
* OOOLLLW
* OOLLLWW
* OLLLLWW
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

class Solution {
public:
  vector<string> findOcean(vector<string> land, int x, int y) {
    if (land[x][y] != 'W') return land;
    int n = land.size(), m = land[0].length();
    queue<pii> q;
    land[x][y] = 'O';
    q.push({x,y});

    while(q.size()) {
      pii front = q.front(); q.pop();
      int x = front.first, y = front.second;

      for (int i = 0;i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b <0 || b>=m) continue;
        if (land[a][b] != 'W') continue;
        land[a][b] = 'O';
        q.push({a,b});
      }
    }
    return land;
  }

private:
  int dx[4] = {0,0,-1, 1};
  int dy[4] = {-1, 1, 0, 0};
};

int main() {
  vector<string> input = {"WWWLLLW", "WWLLLWW", "WLLLLWW"};

  Solution sol;
  vector<string> res = sol.findOcean(input, 0, 1);
  for (string str : res) {
    cout << str << endl;
  }
  return 0;
}
