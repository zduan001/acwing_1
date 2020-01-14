#include <iostream>
#include <vector>

using namespace std;

class _2DIterator{
public:
    _2DIterator(vector<vector<int>> input) : cont(input) {
      i = 0, j = 0;
    }

    int get_val() {
      if (i < cont.size() && j < cont[i].size()) {
        return cont[i][j];
      }
      return -1;
    }

    void next() {
      j++;
      while( i < cont.size() && j >= cont[i].size()) {
        i++, j = 0;
      }
    }

private:
  vector<vector<int>> cont;
  int i, j;

};

// this need to be tested.... more.
class TwoDIterWithIter{
  public:
  TwoDIterWithIter(vector<vector<int>> input) : cont (input) {
    l1 = cont.begin();
    l2 = cont.begin()->begin();
  }

  int get_val() {
    if (l1 != cont.end() && l2 != (*l1).end()) return *l2;
    else return -1;
  }

  void next() {
    if (l2++ != (*l1).end()) return;
    else {
      while(l1++ != cont.end() && (*l1).size > 0 && l2 != (*l1).end()) {
      }
    }
  }

  private:
  vector<vector<int>> cont;
  vector<vector<int>>::iterator l1;
  vector<int>::iterator l2;
};

int main() {
  vector<vector<int>> input = {{1,2}, {}, {3}, {}, {}};
  _2DIterator ite(input);

  for (int i= 0;i < 10; i++) {
    cout << ite.get_val() << endl;
    ite.next();
  }

  return 0;
}