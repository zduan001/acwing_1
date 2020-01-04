#include <iostream> 

using namespace std;

int xy2d(int tier, int x, int y) {
  if (tier == 0) return 1;
  int len = 1 << (tier -1);
  int num = 1 << (2*(tier-1));

  if (x < len && y >= len) {
    return num + xy2d(tier-1, x, y-len);
  } else if ( x >= len && y >= len) {
    return 2*num + xy2d(tier-1, x-len, y - len);
  } else if (x <len && y < len) {
    return xy2d(tier-1, y, x);
  } else {
    return 3 * num + xy2d(tier-1, len-1-y, 2*len-1-x);
  }
}

int main() {
    
    cout<< xy2d(2, 3, 1) << endl;
    cout<< xy2d(2, 2, 1) << endl;
    cout<< xy2d(2, 2, 0) << endl;
    cout<< xy2d(2, 3, 0) << endl;
    cout<< xy2d(2, 2, 2) << endl;
    cout<< xy2d(2, 0, 2) << endl;
    return 0;
}
// expect result.
// 13
// 14
// 15
// 16
// 9
// 5