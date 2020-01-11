#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N cars are going to the same destination along a one lane road.  
// The destination is target miles away.

// Each car i has a constant speed speed[i] (in miles per hour), and 
// initial position position[i] miles towards the target along the road.

// A car can never pass another car ahead of it, but it can catch up to it, 
// and drive bumper to bumper at the same speed.

// The distance between these two cars is ignored - they are assumed to have 
// the same position.

// A car fleet is some non-empty set of cars driving at the same position 
// and same speed.  Note that a single car is also a car fleet.

// If a car catches up to a car fleet right at the destination point, 
// it will still be considered as one car fleet.
// https://leetcode.com/problems/car-fleet/


// How many car fleets will arrive at the destination?
typedef pair<int, int> pii;

class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    if (n <= 1) return n;  
    pii pv[n];
    for (int i = 0;i < n; i++) {
      pv[i] = {position[i], speed[i]};
    }
    sort (pv, pv+n);
    reverse (pv, pv+n);

    double cur_t = 0;
    int cnt = 0;
    for (auto item : pv) {
      int pos = item.first, sp = item.second;
      double time = (double)(target-pos)/sp;
      if (time >= cur_t) {
        cur_t = time;
        cnt++;
      }
    }
    return cnt;
  }
};

int main() {

}