#include <iostream>
#include <vector>

using namespace std;

class Iter{
public:
  Iter(vector<vector<int>> input) : container(input) {
    container = input;
    reset();
  }

  void next() {
    j++;
    while(i < container.size() && j >= container[i].size()) {
      i++; j= 0;
    }
  }

  void remove() {
    if (i < container.size() && j < container[i].size()) {
      container[i].erase(container[i].begin()+j);
      return;
    }
  }

  int get_val() {
    if (i < container.size() && j < container[i].size()) {
      return container[i][j];
    } else {
      next();
      if (i < container.size() && j < container[i].size()) {
        return container[i][j];
      }
    }
    return -1; // or throw exception.
  }
private:
  int i, j;
  vector<vector<int>> container;

  void reset() {
    i = 0, j = 0;
    while(i < container.size() &&  j >= container[i].size()) {
      i++; j = 0;
    }
  }
};

int main() {
  vector<vector<int>> input = {{1,2}, {}, {3}, {}, {}, {}};
  Iter iter(input);

  cout << iter.get_val() << endl;
  iter.next();
  cout << iter.get_val() << endl;
  iter.next();
  cout << iter.get_val() << endl;
  iter.next();
  cout << iter.get_val() << endl;
  iter.next();

  return 0;
}
