#include <iostream>
#include <vector>

using namespace std;

class Solution_198 {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        for (int v : nums) {
            int x = max(a, b);
            int y = b + v;
            b = x; a = y;
        }
        return max(a, b);      
    }
};

class Solution {
public:
  int rob(vector<int>& nums) {
    // pay attention to the sizer = 0, 1. 
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    int a = 0, b = 0;
    for (int i = 0; i < nums.size() -1; i++) {
        int x = max(a, b);
        int y = b + nums[i];
        a = y; b = x;
    }
    int res = max(a, b);
    
    a = 0; b = 0;
    for (int i = 1;i < nums.size(); i++) {
        int x = max(a,b);
        int y = b + nums[i];
        a = y; b = x;
    }
    return max(res, max(a, b));
    }
};


//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
#define x first
#define y second
typedef pair<int, int> pii;

class Solution_337 {
public:
    int rob(TreeNode* root) {
        pii res = dfs(root);
        return max(res.x, res.y);
    }
    
    pii dfs(TreeNode* root) {
        if (!root) return {0,0};
        pii l = dfs(root->left);
        pii r = dfs(root->right);
        
        return {max(l.x, l.y) +max(r.x, r.y),
                root->val + l.x + r.x};
    }
};

int main() {
  // see leetcode check in code.
  return 0;
}