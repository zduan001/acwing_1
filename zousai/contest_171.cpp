#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;


class Solution_1 {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int j = n -i;
            if(to_string(i).find('0') == string::npos && to_string(j).find('0')  == string::npos) return {i, j};
        }
        return {0,0};
        
    }
};

class Solution_2 {
public:
    int minFlips(int a, int b, int c) {
      int tmp = a| b;
      int diff = tmp^c;
      int res = 0;
      for (int i = 0; i < 32 ; i++) {
        if(diff >> i & 1) {
          if (c >> i & 1) res++;
          else {
            if (a >> i & 1) res++;
            if (b>> i & 1) res++;
          }
        }
      }
      return res;
    }
};

class Solution_3 {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      int cnt = connections.size();
      if (cnt < n-1) return -1;
      int p[n];
      for (int i = 0;i < n; i++) p[i] = i;

      for (auto edge : connections) {
        int u = edge[0], v = edge[1];
        int a = find(u,p), b= find(v,p);
        if (a!=b) p[a] = b;
      }

      set<int> x;
      for (int i = 0;i < n; i++) {
        x.insert(find(i, p));
      }
      if (x.size()==1) return 0;
      else return x.size() -1;
    }

    int find(int x, int p[]) {
      if (x != p[x]) p[x] = find(p[x], p);
      return p[x];
    }
};

#define N 305
class Solution_4 {
public:
  int minimumDistance(string word) {
    str = word;
    int n = str.length();
    memset(dp, 0, sizeof dp);
    dfs(0, 0, 0);
    return dp[0][0][0];
  }

  int dfs(int pos, int left, int right) {
    if (pos >= str.length()) return 0;
    if (dp[pos][left][right] == 0) {
      char to = str[pos]+1 -'A';

      dp[pos][left][right] = min(
        cost(to, left) + dfs(pos+1, to, right),
        cost(to, right) + dfs(pos+1, left, to)
      );
    }
    return dp[pos][left][right];
  }

  int cost(char a, char b) {
    if (b == 0) return 0;
    a -=1, b-=1;

    int x1 = a / 6;
    int y1 = a % 6;
    int x2 = b / 6;
    int y2 = b % 6;
    int res = abs(x1-x2) + abs(y1-y2);
    return res;
  }

private:
  string str;
  int dp[N][27][27];
};

int main() {
  Solution_4 sol;
  cout << sol.minimumDistance("HAPPY") << endl;

  return 0;
}