#include <iostream> 
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<int> pourWater(vector<int>& heights, int v, int k) {
    int n = heights.size();
    for (int i = 0; i < v; i++) {
      int l = k, r = k;
      while(l > 0 && heights[l-1] <= heights[l]) l--;
      while(l < k && heights[l+1] == heights[l]) l++;
      while(r < n-1 && heights[r+1] <= heights[r]) r++;
      while(r > k && heights[r-1] == heights[r]) r--;
      if (l < k) heights[l]++;
      else heights[r]++;
    }
    return heights;
  }

  void print(vector<int>& final, vector<int>& origin) {
    map<int, vector<int>> water;
    map<int, vector<int>> land;
    int maxv = 0;
    for (int i = 0; i < final.size(); i++) {
      water[final[i]].push_back(i);
      land[origin[i]].push_back(i);
      maxv = max(maxv, final[i]);
    }
    int n = final.size();
    string str = ""; str.append(n, ' ');
    vector<string> res;
    for (int i = maxv; i > 0; i--) {
      for (int j : water[i]) str[j] = 'W';
      for (int j : land[i]) str[j] = '#';
      res.push_back(str);
    }

    for (string str : res) cout << str << endl;


  }
};

int main() {
  Solution sol;
  vector<int> input = {2,1,1,2,1,2,2};
  vector<int> origin = input;
  vector<int> res = sol.pourWater(input, 4, 3);
  for (int i : res) cout << i << " ";
  cout << endl;

  sol.print(res, origin);
  return 0;
}

