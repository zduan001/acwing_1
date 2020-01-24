#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
      for(int i = 0; i < 32; i++) log[1<<i] = i;
      vector<string> res;
      LL val = convert(ip);
      while(n) {
        int step = val & -val;
        while(step > n) step /=2;
        string str = to_cidr(val, step);
        res.push_back(str);
        val+= step;
        n-=step;
      }
      return res;
    }

    string to_cidr(LL ip, int step) {
      string res = "";
      res += to_string(ip >> 24 & 255) + ".";
      res += to_string(ip >> 16 & 255) + ".";
      res += to_string(ip >> 8 & 255) + ".";
      res += to_string(ip & 255);
      res += "/" + to_string(32-log[step]);
      return res;
    }

    LL convert(string ip) {
      LL res = 0;
      int l = 0;
      for (int i = 0;i < ip.length(); i++) {
        while(i < ip.length() && ip[i]!= '.') i++;
        string tmp = ip.substr(l, i-l);
        res = res * 256 + stoi(tmp);
        l = i+1;
      }
      return res;
    }
private:
  map<int, int> log;
};

int main() {
  Solution sol;
  vector<string> res = sol.ipToCIDR("255.0.0.7", 10);
  for (string x : res) cout << x << endl;
  
  return 0;
}