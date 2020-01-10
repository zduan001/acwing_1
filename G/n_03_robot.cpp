#include <iostream>
#include <cstring>

using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  int dp[n+2][m+2];

  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;

  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + dp[i+1][j-1];      
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}
