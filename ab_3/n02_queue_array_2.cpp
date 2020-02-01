#include <bits/stdc++.h>

using namespace std;

class Queue_2 {
public:
    // Queue() {}
    
    void push(int x) {
        if (tt == -1) {
            array<int, n> tmp;
            tt = 0;
            lt.push_back(tmp);
        }
        lt.back()[tt] = x;
        size++;
        tt++;
        if (tt == n) tt = -1;
    }
    
    int front() {
        if (size <= 0) return -1;
        return lt.front()[hh];
        
    }
    
    void pop() {
        if (size <= 0) return;
        size--;
        hh++;
        if (hh == n) {
            lt.pop_front();
            hh = 0;
        }
        return ;
    }
    
private:
    const static int n = 10;
    list<array<int, n>> lt;
    int size = 0;
    int hh = 0, tt = -1;
};

int main() {
    Queue_2 que;
    for (int i = 0; i < 15; i++) {
        que.push(i);
    }
    
    for (int i = 0; i < 20; i++) {
        cout << que.front() << endl;
        que.pop();
    }
    return 0;
}