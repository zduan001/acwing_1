#include <iostream>
#include <vector>

using namespace std;

#define INT_MAX 0x3f3f3f3f

vector<int> a;

int findkthelement(int l, int r, int k) {
  if (l>=r) return l;
  int res = 0;
  int mid = l+r>>1;
  int cnt= 0;
  for (int i = 0;i < a.size(); i++) {
    if (a[i] < mid) {
      cnt++;
      res = max(res, a[i]);
    }
  }
  if (cnt < k) {
    return findkthelement(res+1, r, k);
  } else {
    return findkthelement(l, res, k);
  }
}

int main() {

  a =  {2,4,1,5,3,6};
  // n = 5;
  // q[0] = 2, q[1] = 4, q[2] = 1, q[3] = 5, q[4] = 3;
  int n = a.size();
  if (n%2) {
    int val = findkthelement(0, INT_MAX, n/2);
    cout << val << endl;
  } else {
    int val1 = findkthelement(0, INT_MAX, n/2);
    int val2 = findkthelement(0, INT_MAX, (n/2)+1);
    cout << (double)(val1+val2)/2 << endl;
  }
  return 0;
}

