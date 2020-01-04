#include <iostream>
#include <map>

using namespace std;

#define N 4

class Solution{
public:
  Solution(string x) :target(x) {}

  string guess() {
    map<char, int> mp;
    for (char c = '1'; c <= '6'; c++) {
      string s = "";
      s.append(4, c);
      int cnt = guessServer(s);
      mp[c] = cnt;
    }

    string scrum = "";
    for(int c = '1'; c <= '6'; c++) {
      scrum.append(mp[c], c);
    }

    memset(st, false, sizeof st);
    dfs(scrum, "");
    return res;
  }

  bool dfs(string origin, string x) {
    
    if (origin.length() ==  guessServer(x)) {
      res = x;
      return true;
    }

    for (int i = 0; i < origin.length(); i++) {
      if (st[i]) continue;
      st[i] = true;
      if (dfs(origin, x + origin[i])) return true;
      st[i] = false;
    }
    return false;
  }

  string get_result() {return res;}

private:
  string target;
  string res;
  bool st[N];

  int guessServer(string x) {
    int res = 0;
    for (int i = 0; i < x.length(); i++) {
      res += x[i] == target[i];
    }
    return res;
  }
};

int main() {
  Solution sol("2545");
  cout << sol.guess() << endl;

  return 0;
}
