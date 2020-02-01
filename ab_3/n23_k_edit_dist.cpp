#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define N 1005

struct node {
    bool end;
    string word;
    node* children[26];
};

// 这题还行， 就是一个树上的DP。 DP table 在那搁着， 一层trie， 一个x坐标
// target是 Y, 
//https://www.lintcode.com/problem/k-edit-distance/description
class Solution {
public:
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        this->k = k;
        this->target = target;
        node* root = new node();
        for (int i = 0; i < words.size(); i++) {
            build(words[i], 0, root);
        }
        memset(dp, 0, sizeof dp);
        for (int i = 1; i < N; i++) {
            dp[0][i] = i;
            dp[i][0] = i;
        }
        if (target=="" && root->end) res.push_back(root->word);
        dfs(root, 1);
        return res;
    }

    void dfs(node* root, int dep) {
        for (int i = 0; i < 26; i++) {
            if (!root->children[i]) continue;

            for (int j = 1; j <= target.length(); j++) {
                if (target[j-1] - 'a' == i) {
                    dp[dep][j] = dp[dep-1][j-1];
                } else {
                    dp[dep][j] = 1+ min(min(dp[dep-1][j], dp[dep][j-1]), dp[dep-1][j-1]);
                }
            }
            if (root->children[i]->end && dp[dep][target.length()] <= k) {
                res.push_back(root->children[i]->word);
            }
            dfs(root->children[i], dep+1);
        }
    }

    void build(string str, int idx,  node* root) {
        if (idx == str.length()) {
            root->end = true;
            root->word = str;
            return;
        } 
        int i = str[idx]- 'a';
        if (!root->children[i]) root->children[i] = new node();
        build (str, idx+1, root->children[i]);
    }

private:
    int dp[N][N];
    vector<string> res;
    string target;
    int k;
};

int main() {
    vector<string> input = {"abc","abd","abcd","adc"};
    string target = "ac";
    Solution sol;
    vector<string> res = sol.kDistance(input, target, 1);
    for (string str : res) {
        cout << str <<"|"<< endl;
    }
    return 0;
}
