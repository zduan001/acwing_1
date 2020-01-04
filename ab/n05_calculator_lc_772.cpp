#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<string, int> psi;

stack<psi> ops;
stack<int> nums;

class Solution {
public:
  int calculate(string s) {
    vector<string> tokens = getokens(s);
    bool last_is_digit = false;
    int level = 0;
    for (string t : tokens) {
      if (t == "") continue;
      if (is_op(t)) {
        if (!last_is_digit && t == "-") nums.push(0);
        if (t == "(") {level+=10; continue;}
        if (t == ")") {level-=10; continue;}

        int cur_lev = level;
        if (t == "+" || t == "-") cur_lev = level+2;
        if (t == "*" || t == "/") cur_lev = level+4;

        while(ops.size() && ops.top().second >= cur_lev) {
          eval();
        }
        ops.push({t, cur_lev});        
      } else {
        last_is_digit = true;
        nums.push(stoi(t));
      }
    }

    while(ops.size()) {eval();}
    return nums.top();
  }

  void eval() {
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();

    string op = ops.top().first; ops.pop();
    if (op == "*") nums.push(a*b);
    if (op == "/") nums.push(a/b);
    if (op == "+") nums.push(a+b);
    if (op == "-") nums.push(a-b);
  }

  bool is_op(string s) {
    return s == "+" || s == "-" || s == "/" || s == "*" || s == "(" || s == ")";
  }

  vector<string> getokens(string s) {
    vector<int> tmpidx;
    for (int i = 0;i < s.length(); i++) {
      if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '(' || s[i] == ')') {
        tmpidx.push_back(i);
      }
    }

    vector<string> tokens;
    int l = 0;
    for (int i = 0;i < tmpidx.size(); i++) {
      int r = tmpidx[i];
      tokens.push_back(trim(s.substr(l, r - l)));
      tokens.push_back(s.substr(r, 1));
      l = r+1;
    }
    if (l < s.length()) 
      tokens.push_back(s.substr(l, s.length()-l));

    return tokens;
  }

  string trim(string s) {
    string res = "";
    for (int i = 0;i < s.length(); i++) {
      char c = s[i];
      if (c == ' ') 
        continue;
      res += c;
    }
    return res;
  }
};

int main() {
  Solution sol;
  string s = " 6-4 / 2 ";
  cout << sol.calculate(s) << endl;
  return 0;
}