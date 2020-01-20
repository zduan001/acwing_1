#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define N 100

vector<int> g[N];

vector<int> findpreferencelsit(vector<vector<int>> input) {
  map<int, int> din;
  map<int, int> dout;

  for(vector<int> person : input) {
    for(int i = 0;i < person.size(); i++) {
      if (i > 0) {
        g[person[i-1]].push_back(person[i]);
      }
      din[person[i]]++;
    }
    din[person[0]]--;
  }

  queue<int> q;

  for (auto item : din) {
    if (item.second == 0) q.push(item.first);
  }

  vector<int> res;
  while(q.size()) {
    int u = q.front(); q.pop();
    res.push_back(u);
    for (auto v : g[u]){
      din[v]--;
      if (din[v] == 0) q.push(v);
    }
  }
  return res;
}

int main() {
  vector<vector<int>> input = {{3, 5, 7, 9}, {2,3,8}, {5,8}};
  vector<int> res = findpreferencelsit(input);
  for (int x : res) cout << x << endl;
  return 0;
}
