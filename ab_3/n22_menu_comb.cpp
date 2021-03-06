#include <iostream>
#include <vector>

using namespace std;

vector<double> prices;
vector<vector<double>> res;
double target;

void dfs(double sum, vector<double> cur, int idx) {
    if (abs(sum-target) < 0.0001) {
        res.push_back(cur);
        return;
    }
    if (sum > target) return;
    if (idx >= prices.size()) return;

    dfs(sum, cur, idx+1);
    
    cur.push_back(prices[idx]);
    dfs(sum + prices[idx], cur, idx+1);
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, 0, target, vector<int>(), candidates);
        return res;
    }
    
    
    void dfs(int idx, int sum, int total, vector<int> cur, vector<int>& a) {
        if (sum > total) return;
        if (abs(sum - total) < 1) {
            
            res.push_back(cur);
            return;
        }
        if (idx == a.size()) return;
        for (int i = idx; i < a.size(); i++) {
            cur.push_back(a[i]);
            dfs(i, sum+a[i], total, cur, a);
            cur.pop_back();
        }
    } 
private:
    vector<vector<int>> res;
};

int main() {
  prices = {10.02, 1.11, 2.22, 3.01, 4.02, 2.00, 5.03};
//   prices = {2.00, 5.03};
  target = 7.03;

  res.clear();
  vector<double> tmp;
  dfs(0.0, tmp, 0);

  for (vector<double> x : res) {
      for (double d : x) {
          cout << d << " ";
      }
      cout << endl;
  }
  return 0;
}
