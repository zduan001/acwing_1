#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// leetcode 1058

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int sum = 0, n = 0;
        vector<double> diff;
        for (string x : prices) {
            double val = stod(x);
            sum += (int)val;
            if (val == (int)val * 1.0) continue;
            diff.push_back(val - 1.0 * (int)val);
            n++;
        }

        if (target < sum || target > (sum+n)) return "-1";
        int nfloor = n - (target - sum);
        nth_element(diff.begin(), diff.begin()+nfloor, diff.end());

        double res = 0.0;
        for (int i = 0; i < diff.size();i++) {
            if (i < nfloor) res += diff[i];
            else res += (1.0 - diff[i]);
        }
        
        string s = to_string(res);
        return s.substr(0, s.find('.')+4);
    }
};

int main() {
    vector<string> input = {"1.2","2.3","3.4"};
    Solution sol;
    cout << sol.minimizeError(input, 7) << endl; // expect 1.100
    return 0;
}
