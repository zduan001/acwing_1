#include <iostream>
#include <vector>
#include <cstring>
#include <time.h>

using namespace std;

// google really like to ask this random number question. 
// what is good about it???

class Solution {
public:
  Solution(vector<int>& w) {
      int n = w.size();
      pref.push_back(w[0]);

      for (int i = 1; i < n; i++) {
        pref.push_back(pref[i-1]+w[i]);
      }
      maxv = pref[n-1];
      srand(time(NULL));
  }
  
  int pickIndex() {
    
    int x = rand()%maxv;
    // cout << x << endl;

    int l = 0, r = pref.size()-1;
    while (l < r) {
      int mid = l+r >> 1;
      if (pref[mid] > x) r = mid;
      else l = mid+1;
    }
    return r;
  }
private:
  vector<int> pref;
  int maxv;
};

int main() {
  vector<int> input = {3, 14, 1, 7};
  Solution sol(input);
  for (int i = 0; i < 1000; i++)
  cout << sol.pickIndex() << endl;
  return 0;
}