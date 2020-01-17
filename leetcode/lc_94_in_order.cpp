#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    stack<pair<TreeNode*, int>> stk;
    vector<int> res;
    stk.push({root, 0});
    while(stk.size()) {
      auto item = stk.top(); stk.pop();
      TreeNode* root = item.first;
      int state = item.second;
      if (!root) continue;
      if (state == 0) {
        stk.push({root, 1});
        stk.push({root->left, 0});
      } else if (state == 1) {
        res.push_back(root->val);
        stk.push({root->right,0});
      }
    }
    return res;
  }
};

int main() {

}