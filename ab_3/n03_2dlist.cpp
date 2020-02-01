#include <iostream>
#include <vector>

using namespace std;

// lint code 601 https://www.lintcode.com/problem/flatten-2d-vector/description
// class _2DIterator{
// public:
//     _2DIterator(vector<vector<int>> input) : cont(input) {
//       i = 0, j = 0;
//     }

//     int get_val() {
//       if (i < cont.size() && j < cont[i].size()) {
//         return cont[i][j];
//       }
//       return -1;
//     }

//     void next() {
//       j++;
//       while( i < cont.size() && j >= cont[i].size()) {
//         i++, j = 0;
//       }
//     }

// private:
//   vector<vector<int>> cont;
//   int i, j;

// };

// // this need to be tested.... more.
// class TwoDIterWithIter{
//   public:
//   TwoDIterWithIter(vector<vector<int>> input) : cont (input) {
//     l1 = cont.begin();
//     l2 = cont.begin()->begin();
//   }

//   int get_val() {
//     if (l1 != cont.end() && l2 != (*l1).end()) return *l2;
//     else return -1;
//   }

//   void next() {
//     if (l2++ != (*l1).end()) return;
//     else {
//       while(l1++ != cont.end() && (*l1).size() > 0 && l2 != (*l1).end()) {
//       }
//     }
//   }

//   private:
//   vector<vector<int>> cont;
//   vector<vector<int>>::iterator l1;
//   vector<int>::iterator l2;
// };

class Vector2D {
public:
  Vector2D(vector<vector<int>>& vec2d) {
    begin = vec2d.begin();
    end = vec2d.end();
    pos = 0;
  }

  int next() {
    hasNext();
    return (*begin)[pos++];
  }

  bool hasNext() {
    while(begin != end && pos == (*begin).size()) {
      begin++, pos = 0;
    }
    return begin != end;
  }
private:
  vector<vector<int>>::iterator begin, end;
  int pos;
};

class TwoD {
public:
    TwoD(vector<vector<int>>& input) {
        
        first = input.begin();
        last = input.end();
        idx = 0;
    }
    
    bool hasNext() {
        while(first != last && idx >= (*first).size()) {
            first++; idx = 0;
        }
        return first != last;
    }
    
    int next() {
        if (hasNext()) {
            return (*first)[idx++];
        }
    }
    
    void remove() {
        (*first).erase((*first).begin() + idx);
    }
private:
    vector<vector<int>>::iterator first, last;
    int idx;
};

int main() {
  vector<vector<int>> input = {{1,2}, {}, {3}, {}, {}};
  // _2DIterator ite(input);
  TwoD ite(input);
  while(ite.hasNext()) {
    cout << ite.next() << endl;
  }

  // for (int i= 0;i < 10; i++) {
  //   cout << ite.get_val() << endl;
  //   ite.next();
  // }

  return 0;
}