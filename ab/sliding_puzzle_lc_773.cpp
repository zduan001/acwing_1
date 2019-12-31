#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map<string, int> mp;
    int slidingPuzzle(vector<vector<int>>& board) {
      string s = "";
      for (int i = 0;i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
          s += to_string(board[i][j]);
        }
      }

      queue<string> q;
      vector<vector<int>> idx = {{1,3}, {0,2,4}, {1, 5}, {0, 4}, {3,1,5}, {2,4}};

      mp[s] = 0;
      q.push(s);
      while(q.size()) {
        string u = q.front(); q.pop();
        if (u == "123450") return mp[u];
        int i = u.find('0');
        for (int j : idx[i]) {
          string v = u;
          swap(v[i], v[j]);
          if (!mp.count(v))  {
            mp[v] = mp[u]+1;
            q.push(v);
          }
        } 
      }
      return -1;
    }
};


int main() {
  return 0;
}