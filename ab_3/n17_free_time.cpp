#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<pii> employeeFreeTime(vector<vector<pii>>& schedule) {
    auto comp = [] (list<pii> a, list<pii> b) {return a.front().first > b.front().first;};
    priority_queue<list<pii>, vector<list<pii>>, decltype(comp)> pq(comp);

    for (auto item : schedule) {
        list<pii> lt;
        for (pii p : item) {
            lt.push_back(p);
        }
        pq.push(lt);
    }

    vector<pii> res; 
    int has_cur = false;
    pii cur;
    while(pq.size()) {
        list<pii> tmp = pq.top(); pq.pop();
        pii next = tmp.front(); tmp.pop_front();
        if (tmp.size()) pq.push(tmp);
        if (!has_cur) {
            cur = next;
            has_cur = true;
        } else {
            if (cur.second >= next.first) {    
                cur.second = max(cur.second, next.second);
            } else {
                res.push_back(cur);
                cur = next;
            }
        }
    }
    res.push_back(cur);

    int l = 0;
    vector<pii> ans;
    for(auto item : res) {
        if (l < item.first) {
            ans.push_back({l, item.first});
            l = item.second;
        }
    }
    ans.push_back({res[res.size()-1].second, INT_MAX});
    return ans;
}

int main() {
    vector<vector<pii>> input = {{{1, 3}, {6, 7}}, {{2, 4}},{{2, 3}, {9, 12}}};
    vector<pii> res = employeeFreeTime(input);
    for (auto item : res) {
        cout << item.first << " " << item.second << endl;
    }
    return 0;
}