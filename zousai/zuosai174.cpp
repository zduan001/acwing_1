#include <bits/stdc++.h>

using namespace std;


#define N 1005
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        
        stack<int> h;
        for (int i = 0;i < arr.size(); i++) {
            int tmp = -1;
            while(h.size() && arr[h.top()] < arr[i]) {
                if ((tmp < 0 || arr[h.top()] > arr[tmp]) && i - tmp <= d) tmp = h.top();
                h.pop();
            }
            left_arr[i] = tmp;
            h.push(i);
        }
        
        while(h.size()) h.pop();
        for (int i = arr.size()-1; i>= 0; i--) {
            int tmp = -1;
            while(h.size() && arr[h.top()] < arr[i]) {
                if ((tmp < 0 || arr[h.top()] > arr[tmp]) && tmp-i <=d) tmp = h.top();
                h.pop();
            }
            right_arr[i] = tmp;
            h.push(i);
        }
        
        memset(jump_l, -1, sizeof jump_l);
        memset(jump_r, -1, sizeof jump_r);
        
        int res = 0;
        for (int i = 0;i < n; i++) {
            res = max(res, dfs(i));
        }
        return res;
    }
    
    int dfs(int idx) {
        if (jump_l[idx] > 0 && jump_r[idx] > 0) return max(jump_l[idx] ,jump_r[idx]);
        int left, right;
        if (left_arr[idx] < 0) left = 0;
        else (left = dfs(left_arr[idx]) +1);
        
        if (right_arr[idx] < 0 ) right = 0;
        else right = dfs(right_arr[idx] + 1);
        
        jump_l[idx] = left;
        jump_r[idx] = right;
        return max(left, right);
    }
    
    
private:
    int res = 0;
    int jump_l[N];
    int jump_r[N];
    int left_arr[N];
    int right_arr[N];
};

int main() {
  vector<int> input = {6,4,14,6,8,13,9,7,10,6,12};
  Solution sol;
  cout << sol.maxJumps(input, 2);

  return 0;
}
