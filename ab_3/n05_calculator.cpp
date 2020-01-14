#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<string, int> psi;

class Solution {
public:
    int calculate(string str) {
      vector<string> tokens = token(str);
      bool last_is_digit = false;
      int level = 0;
      for (string t : tokens) {
        if (t.length() == 0) continue;
        if (t == "(") {level+=10; continue;}
        if (t == ")") {level-=10; continue;}
        int cur_lev = level;
        if (t.length() == 1 && isop(t[0])) {
          if(!last_is_digit) nums.push(0);
          if (t[0] == '+' || t[0] == '-') cur_lev = level + 2;
          if (t[0] == '*' || t[0] == '/') cur_lev = level + 4;
          while (ops.size()>0&& cur_lev <= ops.top().second) {
            eval();
          }
          ops.push({t, cur_lev});

        } else {
          int val = get_val(t);
          if (val < 0) continue;
          nums.push(val);
          last_is_digit = true;
        }
      }
      while(ops.size()) eval();
      return nums.top();
    }

    void eval(){
      int b = nums.top(); nums.pop();
      int a = nums.top(); nums.pop();
      string op = ops.top().first; ops.pop();

      if (op == "+") nums.push(a+b);
      if (op == "-") nums.push(a-b);
      if (op == "*") nums.push(a*b);
      if (op == "/") nums.push(a/b);
    }

    int get_val(string s) {
      string str = "";
      for (char c : s) {
        if (c!= ' ') str+=c;
      }
      if (str.length == 0) return -1;
      return stoi(str);
    }

    vector<string> token(string s) {
      vector<string> token;
      for (int i = 0;i < s.length(); i++) {
        int j = i;
        while(j < s.length() && !isop(s[j])) j++;
        token.push_back(s.substr(i, j-i));
        if (j < s.length()) token.push_back(s.substr(j, 1));
        i = j;
      }
      return token;
    }

    bool isop(char c) {
      return c == '+'||c=='-'||c=='*'||c=='/'||c=='('||c==')';
    }
private:
  stack<psi> ops;
  stack<int> nums;
};

int main() {

  Solution sol;
  string s = "3+2*2";
  cout << sol.calculate(s) << endl;
  return 0;
}