#include <bits/stdc++.h>

using namespace std;

int findkth(vector<int> input, int k) {
    int l = 0, r = INT_MAX;
    while(l < r) {
        int mid = l + (r-l)/2;
        int cnt = 0;
        int res = 0;
        for (int i = 0;i < input.size(); i++) {
            if (input[i] <= mid) {
                cnt++; 
                res = max(res, input[i]);
            }
        }
        if (cnt < k) l = max(res+1, mid);
        else r = res;
    }
    return l;
}

double findmedian(vector<int> input) {
    int n = input.size();
    if (n %2) {
        return findkth(input, n/2+1);
    } else {
        int left = findkth(input, n/2);
        int right = findkth(input, (n)/2+1);
        cout << left << " " << right << endl;
        return ((double)left+right)/2;
    }
}

int main() {
    vector<int> input = {2,4,1,5,3,6,7};
    cout << findmedian(input) << endl;
    return 0;
}