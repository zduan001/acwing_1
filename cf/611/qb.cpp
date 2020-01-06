#include <iostream>

using namespace std;

int n, k;
int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    int r = n%k;
    if (r <= k/2) cout << n << endl;
    else cout << n - (r-k/2) << endl;
  }
}
