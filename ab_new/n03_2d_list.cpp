// Leetcode 251
// Leetcode 341
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> buffer;
int last_i, last_j;
int i, j;

bool hasNext() {
    int n = buffer.size();
    if (i >= n) return false;
    while(true) {
        if (i < n && j < buffer[i].size()) return true;
        if (j < buffer[i].size()) j++;
        else i++, j = 0;
    }
    return false;
}

int next(){
    if (!hasNext()) return -1;
    int res = buffer[i][j];
    last_i = i, last_j = j;
    j++;
    return res;
}

void remove(){
    if (last_i < 0 || last_j < 0) return;
    buffer[last_i].erase(buffer[last_i].begin() + last_j);
    if(hasNext() && i == last_i) j--;
    last_i = -1, last_j = -1;
}

int main() {
    i = 0, j = 0, last_i = -1, last_j = -1;
    buffer.push_back({1,2});
    buffer.push_back({3});
    buffer.push_back({4,5,6});

    for (int k = 0;k < 6; k ++) {
        if (hasNext()) {
            cout << next() << endl;
        }
        if (k ==3) {
            remove();
        }
    }
    i = 0, j = 0;
    for (int k = 0; k < 6; k++) {
        if (hasNext()) {
            cout << next() << endl;
        }
    }
}
