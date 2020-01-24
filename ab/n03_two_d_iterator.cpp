
#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public: 
    Solution(vector<vector<int>> input){
      vec = input;
      i = -1; j = -1; 
    }

    bool has_next() {return check(false);}

    bool move_next() {return check(true);}

    bool check(bool move) {
      int x, y;
      if (i == -1 && j == -1) {x = 0, y = 0;} 
      else {x = i; y = j+1;}
      while(x < vec.size() && y >= vec[x].size()) {
        x++; y = 0;
      }
      bool res = false;
      if (x < vec.size() && y < vec[x].size()) res = true;
      else res = false;
      if (move) {i = x; j = y;}
      return res;
    }

    int next() {
      if (move_next()) {
        return vec[i][j];
      } else {
        return -1;
      }
    }

    int cur() {
      if (i < vec.size() && j < vec[i].size()) return vec[i][j];
      return -1;
    }

    void remove() {
      vec[i].erase(vec[i].begin() + j);
      move_next();
    }

    void reset() {
      i = -1, j = -1;
    }

  private:
    vector<vector<int>> vec;
    int i, j;
};

class TwoDIter{
public:
  TwoDIter(vector<vector<int>>& input) {
    begin = input.begin();
    end = input.end();
    pos = 0;
  }

  int next() {
    hasNext();
    return (*begin)[pos++];
  }

  bool hasNext() {
    while(begin != end && pos >= (*begin).size()) {
      begin++;
      pos = 0;
    }
    return begin != end;
  }

private:
  vector<vector<int>>::iterator begin, end;
  int pos;

};

int main() {
    vector<vector<int>> input = {{1,2}, {}, {3}, {}, {4}, {}};
    TwoDIter iter(input);
    while(iter.hasNext()){
      cout << iter.next() << endl;
    }


  // vector<vector<int>> input = {{1,2}, {}, {3}, {}, {}, {}};
  // Solution sol(input);
  // for (int i = 0;i < 10; i++) {
  //   cout << sol.next() << endl;
  //   if (i == 1) {
  //     cout << "----------" << endl;
  //     sol.remove();
  //   }
  // }
  
  // sol.reset();
  // for (int i = 0;i < 10; i++) {
  //   cout << sol.next() << endl;
  //   // if (i == 1) {
  //   //   cout << "----------" << endl;
  //   //   sol.remove();
  //   // }
  // }

  // // vector<int> test = {1, 2, 3, 4, 5, 6, 7};
  // // auto it = test.begin();
  // // while( it != test.end()) {
  // //   cout << *it << endl;
  // //   if (*it == 4) test.erase(it);
  // //   else it = next(it);
  // // }
  return 0;
}