#include <iostream> 

using namespace std;

int h, m;

int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> h >> m;
    cout << 60 *(24-h) - m << endl;

  }
}