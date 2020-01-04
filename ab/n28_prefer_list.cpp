#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, vector<int>> g;
map<int, int> din;
map<int, int> weight;

typedef pair<int, int> pii;

int main() {
    vector<vector<int>> input = {{3,5,7,9}, {2,3,8},{5,8}};
    
    for (int i = 0;i < input.size(); i++) {
        for (int j = 0; j < input[i].size()-1; j++) {
            int u = input[i][j], v = input[i][j+1];
            g[u].push_back(v);
            din[v]++;
            din[u] += 0;
            weight[u] = weight[v] = 10;
        }
    }
    
    for (int i = 0; i< input[0].size(); i++) {
        weight[input[0][i]] = 0;
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (auto item: din) {
        if(item.second == 0) {
            q.push({weight[item.first], item.first});
        }
    }
    
    vector<int> res;
    while(q.size()) {
        int u = q.top().second; q.pop();
        res.push_back(u);
        for (auto v : g[u]) {
            din[v]--;
            if (!din[v]) q.push({weight[v], v});
        }
    }
    
    for (auto u : res) {
        cout << u << " ";
    }
    cout << endl;
    
}
