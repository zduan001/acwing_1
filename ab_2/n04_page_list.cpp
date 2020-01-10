#include <iostream>
#include <unordered_set>
#include <cstring>
#include <vector>

using namespace std;

int main() {
  int n = 5, m = 13;
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

  int tot = 0;
  bool st[m]; memset(st, false, sizeof st);
  vector<string> curpage;
  unordered_set<string> ids;
  vector<vector<string>> res;

  while(tot < m) {
    for(int i = 0; i < m; i++) {
      if (curpage.size() >= n) break;
      string id = x[i].substr(0, x[i].find(','));
      if (!st[i] && !ids.count(id)) {
        curpage.push_back(x[i]);
        st[i] = true;
        ids.insert(id);
        tot++;
      }
    }
    ids.clear();
    if (curpage.size() == n || tot == m) {
      vector<string> tmp = curpage;
      curpage.clear();
      res.push_back(tmp);
    }
  }

  for (auto page : res) {
    for (string str : page) {
      cout << str << endl;
    }
    cout << "=================" << endl;
  }
  return 0;
}