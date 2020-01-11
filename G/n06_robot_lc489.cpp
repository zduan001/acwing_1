#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> pii;

class Robot {
public:
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  bool move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
};

class Solution {
public:  
  void cleanRoom(Robot& robot) {
    this->robot = robot;
    dfs(0,0,0);
  }

  void dfs(int a, int b, int dir) {
    robot.clean();
    s.insert({a,b});
    for(int i = 0; i < 4; i++) {
      int x = a + dx[dir%4], y = b + dy[dir%4];
      if (s.count({x, y})) continue;
      if (robot.move()) {
        dfs(x, y, dir%4);
        robot.turnLeft();
        robot.turnLeft();
      }
      robot.turnLeft();
      dir++;
    }
    robot.turnLeft();
    robot.turnLeft();
    robot.move();
  }

private:
  Robot robot;
  set<pii> s;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {-1, 0, 1, 0};
};

int main() {

}

