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
            int tmp = (int) val;
            sum += (int)tmp;
            if (val == (double)tmp *1.0) continue;
            diff.push_back(val - 1.0 * tmp);
            n++;
        }

        if (target < sum || target > (sum+n)) return "-1";
        int nfloor = n - (target -sum);
        nth_element(diff.begin(), diff.begin()+nfloor, diff.end());

        double res = 0.0;
        for (int i = 0; i < diff.size();i++) {
            if (i < n) res += diff[i];
            else res += 1.0 - diff[i];
        }
        
        string s = to_string(res);
        s.substr(0, s.find('.')+4);
        return s;
    }
};

int main() {

}