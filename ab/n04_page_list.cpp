#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>

using namespace std;

typedef pair<int, string> pis;

int n, m;


int main() {
//    cin >> n >> m;
    int n = 5, m = 13;
    string x[] = {
        "1,28,310.6,SF",
        "4,5,204.1,SF",
        "20,7,203.2,Oakland",
        "6,8,202.2,SF",
        "6,10,199.1,SF",
        "1,16,190.4,SF",
        "6,29,185.2,SF",
        "7,20,180.1,SF",
        "6,21,162.1,SF",
        "2,18,161.2,SF",
        "2,30,149.1,SF",
        "3,76,146.2,SF",
        "2,14,141.1,SanJose"
    };
    
    bool st[m];
    memset(st, false, sizeof st);
    
    vector<vector<string>> res;
    vector<string> tmp;
    int processed = 0;
    unordered_set<int> contained;
    
    while(processed < m) {
        for (int i = 0; i < m; i++) {
            int hostid = stoi(x[i].substr(0, x[i].find(",")));
            if (st[i]) continue;
            if (contained.count(hostid)) continue;
            tmp.push_back(x[i]);
            processed++; contained.insert(hostid); st[i] = true;
            if (tmp.size() == n) {
                res.push_back(tmp);
                tmp.clear();
                contained.clear();
                break;
            }
        }
        contained.clear();
        if (processed == m) {
            res.push_back(tmp);
            break;
        }
    }
    
    for (auto page : res) {
        for (string s : page) {
            cout << s << endl;
        }
        cout << "----------------" << endl;
    }
    
    return 0;
}
