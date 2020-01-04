#include <iostream>
#include <map>

using namespace std;

// 想想实在是没啥好写的。就先搁着吧。
struct Node {
  string army_name;
  int loc, strength;
};

class Diplomacy{
public:
  Diplomacy(){}

  void hold() {return;}

  void move(int from, int to) {

  }

  void support(int from, int to) {

  }

private:
  map<string, Node*> names;
  map<int, Node*> locs;
};

int main() {
  return 0;

}