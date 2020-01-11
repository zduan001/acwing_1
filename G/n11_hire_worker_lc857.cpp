#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;

class Solution {
public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    vector<pair<double, int>> p;
    for (int i = 0;i < quality.size(); i++) {
      p.push_back({((double)wage[i]/quality[i]), quality[i]});
    }
    sort(p.begin(), p.end());
    priority_queue<int> resq;
    double ratio = 0;
    int total = 0;
    double result = 0x3f3f3f3f3f;
    for (int i = 0; i < p.size(); i++) {
      double r = p[i].x;
      int qua = p[i].y;

      resq.push(qua);
      total += qua;

      if (resq.size() > K) {
        total -= resq.top();
        resq.pop();
      }

      if (resq.size() == K) {
        result = min (total * r, result);
      }
    }
    
    return result;
  }
};

int main() {
  vector<int> qua = {10,20,5};
  vector<int> wage = {70,50,30};

  Solution sol;
  cout << sol.mincostToHireWorkers(qua, wage, 2) << endl;
  return 0;
}
