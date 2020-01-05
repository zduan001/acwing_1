#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

//Q1
// class Solution {
// public:
//     string freqAlphabets(string s) {
//         string res = "";
//         for (int i = 0;i < s.length(); i++) {
            
//             int tmp;
//             if (i + 2 < s.length() && s[i+2] == '#') {
//                 tmp = stoi(s.substr(i, 2));
//                 i = i+2;
//             } else {
//                 tmp = s[i] - '1'+1;
//             }
            
//             res += 'a'+ tmp -1;
            
//         }
//         return res;
//     }
// };

//Q2
//class Solution {
//public:
//    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//        int n = (int)arr.size();
//        int pref[n+1];
//        pref[0] = 0;
//        pref[1] = arr[0];
//        for (int i = 2; i <=n ; i++) {
//            pref[i] = pref[i-1]^arr[i-1];
//        }
//
//        vector <int> res;
//        for (auto x : queries) {
//            int l = x[0], r = x[1];
//            res.push_back(pref[r+1]^pref[l]);
//        }
//        return res;
//
//
//    }
//};

//Q3
//class Solution {
//public:
//    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
//        vector<string> res;
//        int n = (int)watchedVideos.size();
//
//        bool st[n];
//        vector<int> g[n];
//        for (int i = 0; i < n; i++) {
//            for(int v : friends[i])
//                g[i].push_back(v);
//        }
//        memset(st, false, sizeof st);
//        queue<int> q;
//        q.push(id);
//        int step = 0;
//        while(true) {
//            if (step == level) {
//                //do smething
//                break;
//            }
//            int k = (int)q.size();
//            while(k--) {
//                int u = q.front(); q.pop();
//                for (int v : g[u]) {
//                    if (st[v]) continue;
//                    st[v] = true;
//                    q.push(v);
//                }
//            }
//            step++;
//        }
//
//        map<string, int> mp;
//
//        while(q.size()) {
//            int u = q.front(); q.pop();
//            for (string s : watchedVideos[u]) {
//                mp[s]++;
//            }
//        }
//
//        vector<pair<int, string>> tmp;
//        for (auto x : mp) {
//            tmp.push_back({x.second, x.first});
//        }
//
//        sort(tmp.begin(), tmp.end());
//
//        for (auto item : tmp) {
//            res.push_back(item.second);
//        }
//
//        return res;
//
//    }
//};

//Q4
//class Solution {
//public:
//    int minInsertions(string s) {
//    int n = s.length();
//    int dp[n][n], l, h, gap;
//    memset(dp, 0, sizeof(dp));
//
//    for (gap = 1; gap < n; ++gap)
//        for (l = 0, h = gap; h < n; ++l, ++h)
//            dp[l][h] = (s[l] == s[h])?
//                        dp[l + 1][h - 1] :  (min(dp[l][h - 1],  dp[l + 1][h]) + 1);
//    return dp[0][n - 1];
//
//    }
//};

int main() {
  Solution sol;
  cout << sol.freqAlphabets("26#11#418#5") << endl;
//    vector<int> input = {1,3,4,8};
//    vector<vector<int>> que = {{0,1}};
//    vector<int> res = sol.xorQueries(input, que);
    
//    Solution sol;
//    vector<vector<string>> watchedVideos= {{"A","B"},{"C"},{"B","C"},{"D"}};
//    vector<vector<int>> friends = {{1,2},{0,3},{0,3},{1,2}};
//    int id = 0;
//    int level = 1;
//
//    vector<string> res = sol.watchedVideosByFriends(watchedVideos, friends, id, level);
//    for (string s: res) cout << s << endl;
    
  return 0;
}
