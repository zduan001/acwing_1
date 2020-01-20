#include <iostream>
#include <vector>
#include <map>

using namespace std;
// discuss the rule of the flow first. 
class Solution {
public:
    vector<int> pourWater(vector<int> &heights, int V, int K) {
        int n = heights.size();
        vector<int> tmp = heights;
        for (int i = 0;i < V; i++) {
          int l = K, r = K;
          while(l > 0 && tmp[l-1] <= tmp[l]) l--;
          while(l < K && tmp[l] == tmp[l+1]) l++;
          while(r < n-1 && tmp[r+1] <= tmp[r]) r++;
          while(r > K  && tmp[r-1] == tmp[r]) r--;
          if (l < K) tmp[l]++;
          else tmp[r]++;
        }
        return tmp;
    }

    vector<string> print(vector<int> water, vector<int> origin) {
      vector<string> res;
      int maxv = 0;
      for (int x : water) maxv = max(maxv, x);

      map<int, vector<int>> wm, om;
      for (int i = 0; i < water.size(); i++) {
        wm[water[i]].push_back(i);
        om[origin[i]]. push_back(i);
      }
      string str= "";
      str.append(water.size(), ' ');
      for (int i = maxv; i > 0; i--) {
        for (int idx : wm[i]) str[idx] = 'W';
        for (int idx : om[i]) str[idx] = '#';
        res.push_back(str);
      }
      return res;
    }
};

int main() {
  Solution sol;
  vector<int> x = {2,1,1,2,1,2,2};
  vector<int> res = sol.pourWater(x, 4, 3);
  for (auto x : res) cout << x << endl;

  vector<string> profile = sol.print(res, x);
  for (string str : profile)  cout << str << endl;

  return 0;
}