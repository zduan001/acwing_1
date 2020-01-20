#include <iostream>
#include <cstring>

using namespace std;

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//       int n = s.length(), m = p.length();
//       if (m == 0) return n == 0;
//       if (m >1 && p[1] == '*') {
//         return (isMatch(s, p.substr(2)) || n>0 && match(s[0], p[0]) && isMatch(s.substr(1), p));
//       } else {
//         return (n>0 && match(s[0], p[0]) && isMatch(s.substr(1), p.substr(1)));
//       }
//     }
//     bool match(char a, char b) {
//       return b == '.' || a == b;
//     }
// };


class Solution {
public:
    bool isMatch(string s, string p) {
      int n = s.length(), m = p.length();
      bool dp[n+1][m+1];
      memset(dp, false, sizeof dp);
      dp[0][0] = true;
      for (int j = 2; j <=m; j++) {
        if (p[j-1] == '*') dp[0][j] = dp[0][j-2];
      }

      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (p[j-1] == '*') dp[i][j] = dp[i][j-2] || (match(s[i-1], p[j-2]) && dp[i-1][j]);
          else dp[i][j] = match(s[i-1], p[j-1]) && dp[i-1][j-1];
        }
      }
      return dp[n][m];
    }

    bool match(char a, char b) {
      return b == '.' || a == b;
    }
};

int main() {

}