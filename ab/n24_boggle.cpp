#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>

using namespace std;

#define N 105

// lint code 132, https://www.lintcode.com/problem/word-search-ii/description
// 得用prefix来剪枝。
class Solution {
public:
  vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
    for (string s : words){
      dict.insert(s);
      for (int i = 1; i <= s.length(); i++) {
        prefix.insert(s.substr(0, i));
      }
    } 
    n = board.size();
    m = board[0].size();

    for (int i = 0;i < n; i++) {
      for (int j = 0; j < m; j++) {
        memset(st, false, sizeof st);
        dfs(board, "", i, j);
      }
    }
    vector<string> ans;
    for (string str : res) {ans.push_back(str);}
    return ans;
  }

  void dfs(vector<vector<char>>& board, string tmp, int x, int y) {
    if (st[x][y]) return;
    tmp += board[x][y];
    if (!prefix.count(tmp))return;
    st[x][y] = true;
    if (dict.count(tmp)) res.insert(tmp);

    for (int i = 0;i < 4; i ++) {
      int a = x+ dx[i], b = y + dy[i];
      if (a < 0 || a >= n || b < 0 || b >= m) continue;
      if (st[a][b]) continue;
      dfs(board, tmp, a, b);
    }
    st[x][y] = false;
  }

private:
  unordered_set<string> dict;
  unordered_set<string> res;
  unordered_set<string> prefix;
  bool st[N][N];
  int dx[4] = {0, 0, -1 , 1};
  int dy[4] = {-1, 1, 0, 0};
  int n, m;
};

int main() {
  Solution sol;
  // vector<vector<char>> board = {{'d','o','a','f'},{'a','g','a','i'},{'d','c','a','n'}};
  // vector<string> words = {"dog","dad","dgdg","can","again"};

  vector<vector<char>> board = {{'a','b','c','e'},{'s','f','e','s'},{'a','d','e','e'}};
  vector<string> words = {"abceseeefs","abceseedasfe"};
  vector<string> res = sol.wordSearchII(board, words);
  for (string str : res) {
    cout << str << " ";
  }
  cout << endl;
  return 0;
}