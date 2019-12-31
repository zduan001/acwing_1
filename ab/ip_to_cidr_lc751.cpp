#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

using namespace std;

typedef long long LL;

class Solution {
public:
    map<int, int> mp;
    vector<string> ipToCIDR(string ip, int n) {
      
      for (int i = 0; i < 32; i++) mp[1<<i] = i;
      vector<string> res;
      LL x = get_ip(ip);
      while(n) {
        int lowbit = x&-x;
        while(lowbit > n) {lowbit>>=1;}
        res.push_back(get_cidr(x, lowbit));
        x+=lowbit;
        n-=lowbit;
      }
      return res;
    }

    string get_cidr(int x, int n) {
      string txt = "";
      txt = to_string(x >> 24 & 255) + "." +
            to_string(x >> 16 & 255) + "." +
            to_string(x >> 8 & 255) + "." +
            to_string (x & 255);
      txt = txt +  "/" + to_string(32 - mp[n]);
      return txt;
    }

    LL get_ip(string ip) {
      LL x = 0;
      
      // vector<string> parts;
      // vector<int> dots;
      // for (int i = 0;i < ip.length(); i++) {
      //   if (ip[i] == '.') dots.push_back(i);
      // }

      // int l = 0; 
      // for (int i : dots) {
      //   parts.push_back(ip.substr(l, i - l));
      //   l = i+1;
      // }
      // parts.push_back(ip.substr(l, ip.length()-l));
      // for (string part : parts) {
      //   x = 256*x + stoi(part);
      // }

      istringstream is(ip);
      string st;
      while(getline(is, st, '.')) {
        x = 256 * x + stoi(st);
      }
      return x;
    }
};

int main() {

  Solution sol;
  string ip = "255.0.0.7";
  int n = 10;
  vector<string> res = sol.ipToCIDR(ip, n);

  for (auto s : res) {
    cout << s << endl;
  }
  return 0;
}
