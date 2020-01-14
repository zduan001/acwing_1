#include <iostream>
#include <vector>
#include <unordered_set> 
#include <cstring>

using namespace std;

int main() {
  int n = 13, m = 5;
  string x[] = {
    "1,28,310.6,SF",
    "4,5,204.1,SF",
    "20,7,203.2,Oakland",
    "6,8,202.2,SF",
    "6,10,199.1,SF",
    "1,16,190.4,SF",
    "6,29,185.2,SF",
    "7,20,180.1,SF",
    "6,21,162.1,SF",
    "2,18,161.2,SF",
    "2,30,149.1,SF",
    "3,76,146.2,SF",
    "2,14,141.1,SanJose"
  };

  int cnt = 0;
  vector<vector<string>> res;
  vector<string> page;
  bool st[n];
  memset(st, false, sizeof st);

  while(cnt < n) {
    unordered_set<string> included;
    for (int i = 0;i < n; i++) {
      if (st[i]) continue;
      string id = x[i].substr(0, x[i].find(','));
      if (included.count(id)) continue;
      page.push_back(x[i]);
      st[i] = true;
      included.insert(id);
      cnt++;
      if (page.size() >= m) break;
    }

    if (page.size() >= m || cnt == n) {
      res.push_back(page);
      page.clear();
    }
    if (cnt == n) {break;}
  }

  for (vector<string> page : res) {
    for (string str : page) {
      cout << str << endl;
    }
    cout << " ----------------- " << endl;
  }
  return 0;
}
  