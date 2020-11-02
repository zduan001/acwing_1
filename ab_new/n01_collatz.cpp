#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
unordered_map<int, int> mp;

int findsteps(int x) {
    if (x == 1) return 0;
    if (mp.count(x)) return mp[x];
    if (x % 2) return mp[x] = 1 + findsteps(3 * x + 1);
    else return mp[x] = 1 + findsteps(x/2);
}

int main() {
    cin >> n;
    //n = 8;
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        res = max(res, findsteps(i));
    }
    cout << res << endl;
    return 0;
}
