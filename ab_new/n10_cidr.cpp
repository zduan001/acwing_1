//leetcode 751
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long LL;

unordered_map<int, int> mp;

LL ipToLong(string ip) {
    vector<int> seg;
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] == '.') continue;
        int j = i;
        while(j < ip.size() && isdigit(ip[j])) j++;
        seg.push_back(stoi(ip.substr(i, j-i)));
        i = j;
    }

    if (seg.size() > 4) return -1;
    LL res = 0;
    for(auto x : seg) {
        res = (res << 8) + x;
    }
    return res;
}

string get_cidr(LL x, int n) {
    string res = "";
    for (int i = 3; i >=0; i--) {
        res += to_string(x >> (8 * i) & 255);
        res+= ".";
    }
    res.pop_back();
    res += ("/" + to_string(32 - mp[n]));
    return res;
}

vector<string> ipToCIDR(string ip, int n) {
    for (int i = 0; i < 32; i++) mp[1<<i] = i;
    vector<string> res;
    LL x= ipToLong(ip);
    while(n) {
        int lowbit = x & -x;
        while(lowbit > n) lowbit >>=1;
        res.push_back(get_cidr(x, lowbit));
        x += lowbit;
        n -= lowbit;
    }
    return res;
}


int main() {
    vector<string> tmp =  ipToCIDR("255.0.0.7", 10);
    for (auto& x : tmp) cout << x << endl;
    return 0; 
}
