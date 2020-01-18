#include <iostream>
#include <cmath>

using namespace std;

int consecutive(long num) {
    int n = sqrt(num);
    int res = 0;
    for (int i = 3; i < num; i += 2) {
        if (num % i == 0) {
            res ++;
        }
    }
    if (num%2) res++;
    return res;

}

int main() {
    cout << consecutive(10) << endl;
    return 0;

}