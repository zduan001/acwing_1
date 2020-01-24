#include <iostream>

using namespace std;

class Solution {
  public:
  string check(string input) {
    string res = "";
    
    bool in_range= false;
    for (int i = 0;i < input.length(); i++) {
      if (input[i] == ',') {
        if(in_range) res+= ",";
        else res += '|';
        continue;
      }

      if (input[i] == '"') {
        if (i == input.length()-1 || input[i+1] != '"') {
          in_range = !in_range;
          continue;
        } else if (input[i+1] == '"') {
          res += '"';
          i++;
          continue;
        }
      }
      res += input[i]; 
    }
    return res;
  }
};

int main() {
  Solution sol;
  string input = "John,Smith,john.smith@gmail.com,Los Angeles,1";
  cout << sol.check(input) << endl;
  input = "Jane,Roberts,janer@msn.com,\"San Francisco, CA\",0";
  cout << sol.check(input) << endl;
  input = "\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1 \"\"\"Alexandra Alex\"\"";
  cout << sol.check(input) << endl;
  return 0;
}
