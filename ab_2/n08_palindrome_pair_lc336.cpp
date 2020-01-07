#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string, int> mp;
    set<pii> sp;

    for(int i = 0;i < words.size(); i++) {
      string tmp = words[i];
      int n = tmp.length();
      reverse(tmp.begin(), tmp.end());
      mp[tmp] = i;
    }

    for (int i = 0; i < words.size(); i ++) {
      string tmp = words[i];
      int n = tmp.length();
      
      for (int j = 0; j <= n; j++) { // 一定要 j<= n, 否则“”就通不过。
        string prefix = tmp.substr(0, j);
        string suffix = tmp.substr(n-j, j);
        if (is_palindrome(prefix) && mp.count(tmp.substr(j, n-j))) sp.insert({mp[tmp.substr(j, n-j)], i});
        if (is_palindrome(suffix) && mp.count(tmp.substr(0, n-j))) sp.insert({i, mp[tmp.substr(0, n-j)]});
      }
    }

    vector<vector<int>> res;
    for (auto p : sp) 
      if (p.first != p.second) // 要unique.
        res.push_back({p.first, p.second});
    return res;
  }

  bool is_palindrome(string s) {
    int l = 0, r = s.length()-1;
    while(l < r) {
      if (s[l] != s[r]) return false;
      l++, r--;
    }
    return true;
  }
};

int main() {
  return 0;
}