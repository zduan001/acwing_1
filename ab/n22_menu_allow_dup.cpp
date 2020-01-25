#include <iostream>
#include <vector>

using namespace std;

// leetcode 39 https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        menu = candidates;
        total = target;
        vector<int> tmp;
        dfs(tmp,0 ,0);
        return res;
    }
    
    void dfs(vector<int> com, int idx, int sum) {
        // cout << idx << " " << sum << " " << total << endl;
        if (sum == total) {
            vector<int> tmp(com);
            res.push_back(tmp);
            return;
        } else if (sum > total) {
            return;
        } else  if (idx >= menu.size()) {
            return;
        } else {
            for (int i = idx; i < menu.size(); i++) {
                com.push_back(menu[i]);
                dfs(com, i, sum + menu[i]);
                com.pop_back();
            }
            // com.push_back(menu[idx]);
            // dfs(com, idx, sum+menu[idx]);
            // com.pop_back();
            // dfs(com, idx+1, sum);
            // com.push_back(menu[idx]);
            // dfs(com, idx+1, sum+menu[idx]);
            // com.pop_back();
        }
    }
private:
    vector<int> menu;
    int total;
    vector<vector<int>> res;

};

int main() {
    Solution sol;
    vector<int> input = { 2,3,6,7};
    int target = 7;
    vector<vector<int>> res = sol.combinationSum(input, target);

    for (auto combination : res) {
        for (int price : combination) cout << price << "  ";
        cout << endl;
    }
    return 0;
}
