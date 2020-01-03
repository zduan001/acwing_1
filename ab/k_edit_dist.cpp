#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define N 1005

struct Node{
    Node* children[26];
    bool end;
    string word;
};

class Solution {
public:
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        memset(dp, 0, sizeof dp);
        int n = (int)target.size();
        for (int j = 1; j <= n ; j++) dp[0][j] = j;
        for (int i = 1; i < N; i++) dp[i][0] = i;
        Node* root = buildtrie(words);
        if (target == "" && root->end) res.push_back(root->word);
        dp_run(root, 1, target, k);
        return res;
    }
    
    void dp_run(Node* root, int dep, string target, int k) {
        for (int i = 0; i < 26; i++) {
            if (!root->children[i]) continue;
            
            for (int j = 1; j <= target.length(); j++ ) {
                char c = target[j-1];
                if (c-'a' == i) {
                    dp[dep][j] = dp[dep-1][j-1];
                } else {
                    dp[dep][j] = 1 + min(dp[dep-1][j-1], min(dp[dep-1][j], dp[dep][j-1]));
                }
            }
            if (root->children[i]->end && dp[dep][target.length()] <= k) {
                res.push_back(root->children[i]->word);
            }
            dp_run(root->children[i], dep+1, target, k);
        }
    }
    
    Node* buildtrie(vector<string>& words) {
        Node* root = new Node();
        for(auto str : words) {
            add(root, str, 0);
        }
        return root;
    }
    
    void add(Node* root, string str, int idx) {
        if (idx == str.length()) {
            root->end = true;
            root->word = str;
            return;
        }
        int char_idx = str[idx] - 'a';
        if (!root->children[char_idx]) root->children[char_idx] = new Node();
        add(root->children[char_idx], str, idx+1);
    }
    
private:
    int dp[N][N];
    vector<string> res;
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
