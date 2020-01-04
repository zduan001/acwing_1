#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
      vector<double> diff;
      int sum = 0, count = 0;
      for(int i = 0; i < prices.size(); i++) {
        double val = stod(prices[i]);
        sum += (int) val;
        if (val == (int)val * 1.0) continue;
        diff.push_back(val - (int) val);
        count++;
      }

      if (target < sum || target > sum+count) return "-1";

      int n = count - (target- sum);
      nth_element(diff.begin(), diff.begin() + 5, diff.end());

      double res = 0.0;
      for (int i = 0; i < diff.size(); i++) {
        if (i < n) res += diff[i];
        else res += (1.0-diff[i]);
      }

      string s = to_string(res);
      s = s.substr(0, s.find('.')+4);
      return s;
    }
};

int main() {
    //   vector<string> input = {"1.500","2.500","3.500"};
    // Solution sol;
    // cout << sol.minimizeError(input, 10) << endl;
    // return 0;
    vector<string> input = {"1.2","2.3","3.4"};
    Solution sol;
    cout << sol.minimizeError(input, 7) << endl; // expect 1.100
    return 0;
}
