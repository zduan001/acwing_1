#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define N 105



class Solution {
public:  
  vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
    b = board;
    for(string x : words) {
      for (int i = 1; i <= x.length(); i++) {
        prefix.insert(x.substr(0, i));
      }
      dict.insert(x);
    }

    n = board.size();
    m = board[0].size();
    
    for (int i = 0;i < n; i++) {
      for (int j = 0; j < m; j++) {
        memset(st, false, sizeof st);
        dfs(i, j, "");
      }
    }
    vector<string> ans(res.begin(), res.end());
    return ans;
  }

  void dfs(int i, int j, string str) { 
    if (st[i][j]) return;
    str += b[i][j];
    if (!prefix.count(str)) return;
    if (dict.count(str)) res.insert(str);
    st[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int x = i+dx[k], y = j+dy[k];
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      dfs(x, y, str);
    }
    st[i][j] = false;
  }

private:
  vector<vector<char>> b;
  unordered_set<string> prefix;
  unordered_set<string> dict;
  unordered_set<string> res;
  int n, m;
  int dx[4] = {0,0,-1,1};
  int dy[4] = {-1,1,0,0};
  bool st[N][N];
};

int main() {
  vector<vector<char>> input = {{'a', 'b', 'c', 'e'},{'s','f','e', 's'},{'a','d', 'e', 'e'}};
  vector<string> words = {"abceseeefs","abceseedasfe"};
  Solution sol;

  vector<string> res = sol.wordSearchII(input, words);
  for (string str : res) {
    cout << str << endl;
  }
  return 0;
}