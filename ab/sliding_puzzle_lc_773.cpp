#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef pair<int, string> pis;

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

    int a_start(vector<vector<int>>& board) {
      mp.clear();
      n = (int)board.size(); m = (int)board[0].size();
      string s = "";
      for (int i = 0; i < board.size(); i ++) {
        for (int j = 0; j < board[0].size(); j++) {
          s += to_string(board[i][j]);
        }
      }
      vector<vector<int>> idx = {{1,3}, {0,2,4}, {1, 5}, {0, 4}, {3,1,5}, {2,4}};
      mp[s] = 0;
      priority_queue<pis, vector<pis>, greater<pis>> pq;
      
      pq.push({dist(s), s});

      while(pq.size()) {
        pis front = pq.top(); pq.pop();
        string u = front.second;
        if (u == "123450") return mp[u];
          
        int i = (int)u.find('0');
        for (int j : idx[i]) {
          string v = u;
          swap(v[j], v[i]);
          if (!mp.count(v) || mp[v] > mp[u]+1) {
            mp[v] = mp[u]+1;
            pq.push({dist(v)+ mp[v], v});
          }
        }
      }
      return -1;
    }

    int dist(string str) {
      int res = 0;
      for (int i = 0;i < str.length(); i++) {
          int t = str[i] - '1';
          if (t != '0') {
              res += (abs(i/3 - t/3) + abs(i%3 - t%3));
          }
      }
      return res;
    }
private:
  int n, m;
};

int main() {
  vector<vector<int>> input = {{4,1,2},{5,0,3}};
  Solution sol;
  cout << sol.a_start(input) << endl;
  return 0;
}