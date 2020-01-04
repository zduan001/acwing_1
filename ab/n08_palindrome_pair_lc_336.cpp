#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
      set<pii> res;
      unordered_map<string, int> mp;

      for (int i = 0;i < words.size(); i++) {
        string tmp = words[i];
        reverse(tmp.begin(), tmp.end());
        mp[tmp] = i;
      }

      for (int i = 0; i < words.size(); i++) {
        string s = words[i];
        for (int len = 0; len <= s.length(); len++) {
          string prefix = s.substr(0, len);
          string suffix = s.substr(s.length()-len, len);
          if (is_palindrome(prefix) && mp.count(s.substr(len)))
           res.insert({mp[s.substr(len)], i});
          if (is_palindrome(suffix) && mp.count(s.substr(0, s.length()-len)))
           res.insert({i, mp[s.substr(0, s.length()-len)]});
        }
      }
      vector<vector<int>> ans;
      for (auto p : res) {
        if (p.first == p.second) continue;
        ans.push_back({p.first, p.second});
      }
      return ans;
    }

    bool is_palindrome(string s) {
      int l = 0, r = s.length()-1;
      while(l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
      }
      return true;
    }
};

int main() {
  Solution sol;
  // vector<string> input = {"abcd","dcba","lls","s","sssll"};
  vector<string> input = {"a", ""};
  vector<vector<int>> res = sol.palindromePairs(input);
  for (auto p : res) {
    cout << p[0] << " " << p[1] << endl;
  }
  return 0;
}
