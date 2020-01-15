#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//lintcode 919 https://www.lintcode.com/problem/meeting-rooms-ii/description




class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
 

class Solution {
public:
    int minMeetingRooms(vector<Interval>& input) {
      vector<pair<int, int>> ends;
      for (auto item : input) {
        ends.push_back({item.start, 1});
        ends.push_back({item.end, -1});
      }

      sort(ends.begin(), ends.end());

      int res = 0;
      int cnt = 0;
      for (auto item : ends) {
        cnt += item.second;
        res = max(res, cnt);
      }
      return res;
    }
};

int main() {
  // vector<vector<int>> input = {{{7,10},{2,4}}};
  // Solution sol;
  // cout << sol.minMeetingRooms(input) << endl;
  // cout << " done " << endl;
  return 0;
}