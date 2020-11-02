#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isp(string s) {
    int l = 0, r = s.size()-1;
    while(l < r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

vector<vector<int>> palindromePair(vector<string>& words) {
    unordered_map<string, int> mp;
    for (int i = 0; i < words.size(); i++) {
        string w = words[i];
        reverse(w.begin(), w.end());
        mp[w] = i;
    }

    vector<vector<int>> res;
    for (int i = 0; i < words.size(); i++) {
        string w = words[i];
        for (int j = 0; j <= w.size(); j++) {
            string l = w.substr(0, j);
            string r = w.substr(j);
            if (mp.count(l) && isp(r) && i != mp[l]) 
                res.push_back({i, mp[l]});
            if (mp.count(r) && isp(l) && 
                    i != mp[r] && 
                    w.size() != words[mp[r]].size()) {
                res.push_back({mp[r], i});
            }
        }
    }
    return res;
}


int main() {
    vector<string> list = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<vector<int>> res = palindromePair(list);

    for (auto& x : res) {
        cout << x[0] << " " << x[1] << endl;
    }
    return 0;

}
