#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
      unordered_map<string, int> mp;
      set<pair<int, int>> res;
      for (int i = 0; i < words.size();i ++) {
        string tmp = words[i];
        reverse(tmp.begin(), tmp.end());
        mp[tmp] = i;
      }

      for (int i = 0; i < words.size(); i++) {
        string str = words[i];
        int n = str.length();
        for (int len = 0; len <= n; len++) {
          string prefix = str.substr(0, len);
          string suffix = str.substr(n-len, len);
          if (is_pal(prefix) && mp.count(str.substr(len, n-len))) res.insert({mp[str.substr(len, n-len)], i});
          if (is_pal(suffix) && mp.count(str.substr(0, n-len))) res.insert({i, mp[str.substr(0,n-len)]});
        }
      }
      vector<vector<int>> x;
      for (auto item : res) {
        if (item.first == item.second) continue;
        x.push_back({item.first, item.second});
      }
      return x;
    }

    bool is_pal(string s) {
      if (s.length() == 0) return true;
      int l = 0, r = s.length()-1;
      while(l<r) {
        if (s[l]!=s[r]) return false;
        l++, r--;
      }
      return true;
    }
};

int main() {
  Solution sol;
  vector<vector<int>> res;
  vector<string> input = {"abcd","dcba","lls","s","sssll"};
  res = sol.palindromePairs(input);

  for (auto item : res) {
    cout << item[0] << " " << item[1] << endl;
  }
  return 0;
}