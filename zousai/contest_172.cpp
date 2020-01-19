#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     vector<string> printVertically(string s) {
//         vector<string> token;
//         int i = 0;
//         int maxl = 0;
//         while(i < s.length()) {
//             while(s[i] == ' ') i++;
//             int j = i+1;
//             while(j < s.length() && s[j] != ' ') j++;
//             token.push_back(s.substr(i, j-i));
//             i = j+1;
//         }
        
//         for (string str: token) {
//           maxl = max(maxl, (int)str.length());
//         }
//         // cout << maxl << endl;
//         vector<string> res ;
//         for (int i = 0;i < maxl; i++) {
//           string tmp = "";
//           for (int j = 0; j < token.size(); j ++) {
//             if(i >= token[j].length()) tmp += " ";
//             else tmp += token[j][i];
//           }
//           while(tmp[tmp.length()-1] == ' ') tmp = tmp.substr(0, tmp.length()-1);

//           res.push_back(tmp);
          
//         }
//         return res;

//     }
// };


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
// class Solution {
// public:
//     TreeNode* removeLeafNodes(TreeNode* root, int target) {

//       del(root, target);
//       if (!root->left && !root->right && root->val == target) root = NULL;
//       return root;
        
//     }

//     bool del(TreeNode* root, int target) {
//       if (!root) return true;
//       if (del(root->left, target)) 
//         root->left = NULL;
//       if (del(root->right, target)) {
//         cout << "dele right" << endl;
//         root->right = NULL;
//     }

//       cout << root->val << " " << (root->left == NULL) <<  " " << (root->right == NULL) << endl;

//       if (root->left == NULL &&
//           root->right == NULL && 
//           root->val == target) {
//           cout << "true" << endl;
//         return true;
//           }
//       else return 
//         false;
//     }
// };

class Solution {
public:
  int minTaps(int n, vector<int>& ranges) {
    vector<pair<int, int>> x;
    for(int i = 0;i < ranges.size(); i ++) {
      x.push_back({max(0, i-ranges[i]), min(n, i+ranges[i])});
    }

    sort(x.begin(), x.end());

    int res = 0;
    for (int i = 0, st = 0, end = 0; st < n; st= end, ++res) {
      
    }
    
  }  
};

int main() {

  Solution sol;
  vector<int> input = { 1,2,1,0,2,1,0,1};
  cout << sol.minTaps(7, input) << endl;
    return 0;
}