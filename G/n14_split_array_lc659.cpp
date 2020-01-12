#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, int> end;
        for (int val : nums) mp[val]++;
        
        for (int val : nums) {
            if (!mp[val]) continue;
            if (end[val-1]) {
                mp[val]--;
                end[val-1]--;
                end[val]++;
            } else if(mp[val+1] && mp[val+2]) {
                mp[val]--;
                mp[val+1]--;
                mp[val+2]--;
                end[val+2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> input = {1,2,3,3,4,4,5,5};
    // {1,2,3,4,4,5}; // {1,2,3,3,4,4,5,5};// {1,2,3,3,4,5};
    Solution sol;
    cout << sol.isPossible(input) << endl;

    return 0;
}