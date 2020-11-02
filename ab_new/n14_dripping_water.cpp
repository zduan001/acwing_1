#include <iostream>
#include <vector>

using namespace std;

void dripWater(vector<int>& land, int idx, int k) {
    int n = land.size();
    for (int t = 0; t < k; t++) {
        int l = idx, r = idx;
        while(l > 0 && land[l-1] <= land[l]) l--;
        while(l < n-1 && land[l+1] == land[l]) l++;
        while(r < n-1 && land[r+1] <= land[r]) r++;
        while(r > 0 && land[r-1] == land[r]) r--;
        if (l < idx) land[l]++;
        else land[r]++;
    }
}

vector<string> print(vector<int>& before, vector<int>after) {
    int maxv = 0, n = before.size();
    for (int i = 0; i < n; i++) {
        maxv = max(maxv, before[i]);
        maxv = max(maxv, after[i]);
    }

    vector<string> res;
    while(maxv) {
        string tmp = "";
        for (int i = 0; i < n; i++) {
            if (maxv > after[i]) tmp+= ' ';
            else if (maxv >before[i]) tmp += 'W';
            else tmp += '+';
        }
        res.push_back(tmp);
        maxv--;
    }
    string tmp = "";
    for (int i = 0;i < n; i++) tmp += '+';
    res.push_back(tmp);
    return res;
}

int main() {
    vector<int> land = {5,4,2,1,2,3,2,1,0,1,2,4};
    vector<int> after = land;
    dripWater(after, 5, 8);
    cout << "here" << endl;
    vector<string> res = print(land, after);
    for (auto x : res) cout << x << endl;
    return 0;
}
