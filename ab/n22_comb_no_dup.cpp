#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// leet code 40. combination sum 2, 
// can not have dup. 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        menu= candidates;
        sort(menu.begin(), menu.end(), greater<int>());
        for (int x : menu) cout << x << " ";
        cout << endl;
        vector<int> tmp;
        dfs(tmp, 0, 0, target);
        return res;
    }
    
    void dfs(vector<int> com, int sum, int idx, int target) {
        if (sum > target) return;
        
        if (sum == target) {
            res.push_back(com);
            return;
        }

        while(idx < menu.size() && sum+menu[idx] > target) idx++;
        
        for(int i = idx; i < menu.size(); i++) {
            if (i > idx && menu[i] == menu[i-1]) continue;
            com.push_back(menu[i]);
            dfs(com, sum+menu[i], i+1, target);
            com.pop_back();
        }
    }
    
private:
    vector<int> menu;
    vector<vector<int>> res;
};

int main() {
    Solution sol;
    vector<int> input = {10,1,2,7,6,1,5};
    // vector<int> input = {2,1,5};
    vector<vector<int>> res = sol.combinationSum2(input, 8);

    for (vector<int> selection : res) {
        for (int price : selection) {
            cout << price << " ";
        }
        cout << endl;
    }
    return 0;
}
