#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> down;
priority_queue<int, vector<int>, greater<int>> up;


void add (int x) {
    if (down.size() == 0 || x < down.top()) {
        down.push(x);
        if (down.size() > up.size()+1) {
            up.push(down.top());
            down.pop();
        }
    } else {
        up.push(x);
        if (up.size() > down.size()) {
            down.push(up.top());
            up.pop();
        }
    }
}

double getMedian() {
    if((up.size()+ down.size()) %2) return down.top();
    else return ((up.top() + down.top()) / 2.0);
}


int main() {
    add(1);
    add(2);
    cout << getMedian() << endl;
    add(3);
    cout << getMedian() << endl;
    return 0;
}
