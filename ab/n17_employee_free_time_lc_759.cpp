#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;

class Solution {
public:
    vector<pii> employeeFreeTime(vector<vector<pii>>& schedule) {
      vector<pii> ends;
      for (auto items : schedule) {
        for (auto item : items) {
          ends.push_back({item.x, 1});
          ends.push_back({item.y, -1});
        }
      }

      sort(ends.begin(), ends.end());

      int l = INT_MIN, count = 0;
      vector<pii> res;
      for (auto item : ends) {
        count += item.y;
        if (!count) l = item.first;
        if (count && l > INT_MIN) {
          if (l != item.x) res.push_back({l, item.x});
          l = INT_MIN;
        }
      }
      return res;
    }
};

int main() {
  Solution sol;
  vector<vector<pii>> input = {{{1,3},{5,7}},{{2,4}},{{2,5},{9,12}}};
  auto res = sol.employeeFreeTime(input);
  for (auto item : res) {
    cout << item.x << " " << item.y << endl;
  }
  return 0;
}
