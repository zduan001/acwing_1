#include <iostream>
#include <deque>
#include <vector>
#define k 10
using namespace std;

int f_idx, l_idx;
int siz;

deque<vector<int>> dq;

void push(int x) {
    if (l_idx == k || dq.size() ==0) {
        l_idx = 0;
        vector<int> tmp(10);
        dq.push_back(tmp);
    }
    auto& tmp = dq.back();
    tmp[l_idx %k] = x;
    l_idx++,  siz++;
}

int pop() {
    if (siz == 0) return -1;
    if(f_idx == k) {
        f_idx = 0;
        dq.pop_front();
    }
    auto& tmp = dq.front();
    int res = tmp[f_idx%k];
    f_idx++;
    siz--;
    return res;
}

int main() {
    siz = 0, f_idx = 0, l_idx = 0;
    for (int i = 0;i < 15; i ++) {
        push(i);
    }
    for (int i = 0; i < 17; i++) {
        cout << pop() << endl;
    }
    return 0;
}

