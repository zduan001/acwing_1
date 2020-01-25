#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];
        pair<bool, bool> dp_d[n][m];
        memset(dp, 0, sizeof dp);
        
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
            dp_d[i][0] = {true, false};
        }
        for (int j = 1; j <m; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
            dp_d[0][j] = {false, true};
        } 

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (dp[i-1][j] < dp[i][j-1]) dp_d[i][j] = {true, false};
                if (dp[i-1][j] > dp[i][j-1]) dp_d[i][j] = {false, true};
                if (dp[i-1][j] == dp[i][j-1]) dp_d[i][j] = {true, true};
                
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        for (int i = 0;i <n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[n-1][m-1];
        
    }

    void dfs() {
        
    }
};

int main() {

}