#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<string, int> psi;

class Solution{
public:
  int caculate(string str) {
    vector<string> tokens = tokenize(str);
    eval(tokens);
    return nums.top();
  }

  bool is_operator(char c) {
    return (c == '*' ||
            c == '+' ||
            c == '/' ||
            c == '-' ||
            c == '(' ||
            c == ')');
  }

  vector<string> tokenize(string str) {
    int n = str.length();
    vector<string> tokens;

    for (int i = 0; i < n; i++) {
      int j = i;
      while(j < n && !is_operator(str[j])) j++;
      
      if (j - i > 0) {
        string numstr = str.substr(i, j-i);
        tokens.push_back(numstr);
        // cout << i << " " << j << " " <<numstr<< endl;
      }
      if (str[j] != '\0') {
        tokens.push_back(string(1, str[j]));
      }
      i = j;
    }
    return tokens;
  }

  void eval(vector<string> tokens) {
    int level = 0;
    bool is_last_number = false;
    for (string s : tokens) {
      if (trim(s).length() == 0 ) continue;
      if (s.length() == 1 && !(s[0] >= '0' && s[0] <= '9')) {
        if (s == "(") {level += 10; continue;}
        if (s == ")") {level -= 10; continue;}

        if (!is_last_number) nums.push(0);
        is_last_number = false;
        int cur_lev = 0;
        if (s == "+" || s == "-") cur_lev = level + 2;
        if (s == "*" || s == "/") cur_lev = level + 4;

        while(ops.size() && ops.top().second >= cur_lev) {
          cal();
        }
        ops.push({s, cur_lev});

      } else {
        nums.push(stoi(s));
        is_last_number = true;
      }
    }
    while(ops.size()) cal();
  }

  void cal() {
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();

    string op = ops.top().first; ops.pop();

    if (op == "+") nums.push(a+b);
    else if (op == "-") nums.push(a-b);
    else if (op == "*") nums.push(a*b);
    else if (op == "/") nums.push(a/b);
  }
    
  string trim(string str) {
      string res;
      for(char c: str) {
          if (c != ' ') {
              res += c;
          }
      }
      return res;
  }

private:
  stack<int> nums;
  stack<psi> ops;
};

int main() {
  Solution sol;
  string s = "2*(5+5*2)/3+(6/2+8)";
  // string s = "-(-(-7))";
  // cout << sol.calculate(s) << endl;
  // vector<string> tokens = sol.tokenize(s);
  // cout << tokens.size();
  // for (string str : tokens) {cout << str << " ";}
  // cout << endl;
  cout << sol.caculate(s) << endl;
  return 0;
}

/*
"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
*/
