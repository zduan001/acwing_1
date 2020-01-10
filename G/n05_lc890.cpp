#include <iostream>
#include <vector>
#include <map>

using namespace std;


typedef long long LL;
class Solution {
public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> res;
    LL target = build(pattern);
    for (string str : words) {
      if (build(str) == target) res.push_back(str);
    }
    return res;
  }

  LL build(string pattern) {
    map<char, int> mp;
    int idx = 0;
    LL res = 0;
    for (char c : pattern) {
      if (!mp.count(c)) mp[c] = ++idx;
      res = (LL)res * 10 + (LL)mp[c];
      res %= (LL)1e9+7;
    }
    return res;
  }
};

int main() {

}