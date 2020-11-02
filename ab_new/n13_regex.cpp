#include <iostream>
#include <vector>
using namespace std;

bool match(char a, char b) {
    return b == '.' || a == b;
}
bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;
    for(int j = 2; j <= m; j+=2) dp[0][j] = p[j-1] == '*' && dp[0][j-2];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(p[j-1] =='*') {
                dp[i][j] = (match(s[i-1], p[j-2]) && dp[i-1][j]) || dp[i][j-2];
            } else {
                dp[i][j] = match(s[i-1], p[j-1]) && dp[i-1][j-1];
            } 
        }
    }
    return dp[n][m];
}


int main() {
    cout << isMatch("abc", "a.*c") << endl;
    return 0;
}
