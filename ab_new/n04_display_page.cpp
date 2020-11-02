#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef struct item{
    int id, list_id;
    float score;
    string city;
} entry;

int main() {
    int k = 5;
    vector<entry> list;
    list.push_back({1, 28, 2, "SF"});
    list.push_back({4, 28, 2, "SF"});
    list.push_back({20, 28, 2, "SF"});
    list.push_back({6, 28, 2, "SF"});
    list.push_back({6, 28, 2, "SF"});
    list.push_back({1, 28, 2, "SF"});
    list.push_back({6, 28, 2, "SF"});
    list.push_back({7, 28, 2, "SF"});
    list.push_back({6, 28, 2, "SF"});
    list.push_back({2, 28, 2, "SF"});
    list.push_back({2, 28, 2, "SF"});
    list.push_back({3, 28, 2, "SF"});
    list.push_back({2, 28, 2, "SF"});

    unordered_set<int> included;
    vector<vector<int>> res;
    vector<int> tmp;
    while(included.size() != list.size()) {
        unordered_set<int> counted;
        for (int i = 0; i < list.size(); i++){
            if (included.count(i)) continue;
            int idx = list[i].id;
            if (counted.count(idx)) continue;
            tmp.push_back(list[i].id);
            included.insert(i);
            counted.insert(list[i].id);
            if (tmp.size() == k) break;
        }
        if (tmp.size() ==k || included.size() == list.size()) 
            res.push_back(tmp), tmp = vector<int>();
    }
    cout << res.size() << endl;
    for (auto x : res){
        for(auto idx : x) cout << idx << endl;
        cout << " ---- " << endl;
    }
    return 0;
}
