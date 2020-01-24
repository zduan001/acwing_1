#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<double>> res;
vector<double> prices;

void dfs(vector<double> order, int idx, double target, double sum) {
  if (abs(sum - target) < 0.0001) {
    vector<double> tmp = order;
    res.push_back(tmp);
    return;
  }
  if (sum > target) return;
  if (idx >= prices.size()) return;

  dfs(order, idx+1, target, sum);
  order.push_back(prices[idx]);
  dfs(order, idx+1, target, sum+prices[idx]);
}

int main() {
  prices = {10.02, 1.11, 2.22, 3.01, 4.02, 2.00, 5.03};
  vector<double> tmp;
  double target = 7.03;
  dfs(tmp, 0, target, 0);

  for (vector<double> order : res) {
    for (double price : order) {
      cout << price << " ";
    }
    cout << endl;
    cout << "--------------------";
    cout << endl;
  }
}
