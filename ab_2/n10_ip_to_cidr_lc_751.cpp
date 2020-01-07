#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;

class Solution {
public:
  vector<string> ipToCIDR(string ip, int n) {
    vector<string> res;
    for (int i = 0; i < 32; i++) mp[1<<i] = i;
    LL x = 0;
    for (int i = 0;i < ip.length(); i++) {
      int j = i+1;
      while(j < ip.length() && ip[j] != '.') j++;
      string tmp = ip.substr(i, j-i);
      cout << tmp << endl;
      x = 256*x + stoi(tmp);
      i = j;
    }

    while(n) {
      int lowbit = x & -x;
      while(lowbit > n) lowbit /= 2;
      res.push_back(create_cidr(x, lowbit));
      x+=lowbit;
      n-=lowbit;
    }
    return res;
  }

  string create_cidr(LL ip, int lowbit) {
    string str = "";
    str += to_string(ip >> 24 & 255) + ".";
    str += to_string(ip >> 16 & 255) + ".";
    str += to_string(ip >> 8 & 255) + ".";
    str += to_string(ip & 255);

    int i = mp[lowbit];
    str += "/" + to_string(32-i);
    return str;
  }
private:
  unordered_map<int, int> mp;
};

int main() {
  Solution sol;
  string ip = "255.0.0.7";
  int  n = 10;
  vector<string> res = sol.ipToCIDR(ip, n);
  for (string s : res) cout << s << endl;
  return 0;
}