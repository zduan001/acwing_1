#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        n = board.size(), m = board[0].size();
        string str = "";
        for (int i = 0;i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j++) {
                str += to_string(board[i][j]);
            }
        }

        queue<string> que;
        unordered_map<string, int> dist;
        unordered_set<string> st;

        que.push(str);
        dist[str] = 0;
        while(que.size()){
            string u = que.front(); que.pop();
            if (u == "123450") return dist[u];
            if (st.count(u)) continue;
            st.insert(u);
            for (int i = 0; i < 4; i++) {
                string str_next = move(u, dx[i], dy[i]);
                if (str_next.length() == 0) continue;
                que.push(str_next);
                if (dist[str_next] > dist[u]+1)
                    dist[str_next] = dist[u]+1;
            }
        }
        return -1;;
    }

    string move (string str, int x, int y) {
        int idx = str.find('0');
        int a = idx / m;
        int b = idx % m;

        int c = a+x, d = b+y;
        if (c < 0 || c >= n || d < 0 || d >= m) return "";

        int new_idx = c * m +d;
        swap(str[idx], str[new_idx]);
        return str;
    }

private:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int n, m;
};

int main() {

    Solution sol;
    // vector<vector<int>> board = {{1,2,3},{4,0,5}};
    // vector<vector<int>> board = {{1,2,3},{5,4,0}};
    vector<vector<int>> board = {{4,1,2},{5,0,3}};
    cout << sol.slidingPuzzle(board) << endl;
    return 0;
}