//https://leetcode.com/discuss/interview-question/124721/Snapchat-or-Parse-CPU-log-file
#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;

typedef pair<string, int> psi;

int main() {
    string thr, start, time;
    stack<psi> stk;
    map<string, vector<pair<int, int>>> res;
    int n; 
    cin >> n;
    while(n--) {
        cin >> thr >>  start >> time;
        bool istart = start == "true";
        int timestamp = stoi(time);

        if (istart) {
            if(stk.empty()) {
                stk.push({thr, timestamp});
            } else {
                res[stk.top().first].push_back({stk.top().second, timestamp});
                stk.push({thr, timestamp});
            }
        } else {
            res[stk.top().first].push_back({stk.top().second, timestamp});
            stk.pop();
            if (!stk.empty()) {
                string thr2 = stk.top().first;
                stk.pop();
                stk.push({thr2, timestamp});
            }
        }
    }

    for(auto item : res) {
        cout << item.first << endl;

        vector<pair<int,int>> list = item.second;
        vector<pair<int, int>> compressed;
        pair<int, int> cur = list[0];
        for(int i = 1;i < list.size(); i++) {
            if (cur.second >= list[i].first) {
                cur.second = max(cur.second, list[i].second);
            } else {
                compressed.push_back(cur);
                cur = list[i];
            }
        }
        compressed.push_back(cur);

        for (auto span : compressed) {
            cout << "{" << span.first << ", " << span.second << "} ";
        }
        
        cout << endl;
    }
    return 0;
}