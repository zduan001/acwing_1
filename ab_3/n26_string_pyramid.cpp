#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/pyramid-transition-matrix/

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
      for (auto str : allowed) {
        mp[str.substr(0,2)].push_back(str.substr(2,1));
      }
      return dfs(bottom, 0, "");
    }

    bool dfs(string base, int idx, string top) {
      if (base.length() == 1) return true;
      if(idx == base.length()-1) return dfs(top, 0, "");

      string str = base.substr(idx, 2);
      if (!mp.count(str)) return false;
      for (string s : mp[str]) {
        if (dfs(base, idx+1, top+s)) return true;
      }
      return false;
    }
private:
  map<string, vector<string>> mp;
};

int main() {

}