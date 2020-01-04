#include <iostream>

using namespace std;

int get_step(int x) {
  int res = 0;
  while(x!=1) {
    if (x%2) x = 3*x+1;
    else x/=2;
    res++;
  }
  return res; // return step not # of numbers.
}

int main() {
  int l,r;
  cin >> l >> r;

  // cout << get_step(7) << endl;

  int res = 0;
  for (int i = l; i <=r; i ++) {
    res = max(res, get_step(l));
  }
  cout << res << endl;
}
