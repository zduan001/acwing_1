#include <iostream>

using namespace std;

int colltz(int x) {
  int res = 0;
  while(x != 1) {
    res++;
    if (x&1) x = 3*x+1;
    else x /= 2;
  }
  return res;
}

int main() {
  int i, j;
  cin >> i >> j;

  int res = 0;
  for (int a = i; a <= j; a++) {
    res = max(res, colltz(a));
  }
  cout << res << endl;
  return 0;
}