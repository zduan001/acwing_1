#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {      
      for (int x : to_delete) st.insert(x);
      dfs(root);
      if(!st.count(root->val)) res.push_back(root);
      return res;
    }

    void dfs(TreeNode* root) {
      if (!root) return;
      if (st.count(root->val)) { 
        if (root->left && !st.count(root->left->val)) res.push_back(root->left);
        if (root->right && !st.count(root->right->val)) res.push_back(root->right);
      }
      dfs(root->left);
      dfs(root->right);
      if (root->left && st.count(root->left->val)) root->left = NULL;
      if (root->right && st.count(root->right->val)) root->right = NULL;

    }
private: 
  vector<TreeNode*> res;
  unordered_set<int> st;
};

int main() {

}
