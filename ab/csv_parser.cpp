#include <iostream>

using namespace std;

// input string input = "aa, bb, \"aa\",\"aa,bb\", \"aa\"\"a,a\"\"\"";

int main() {
  string input = "aa, bb, \"aa\",\"aa,bb\", \"aa\"\"a,a\"\"\"";
  string res = "";
  int used = -1;
  bool inside = false;
  for (int i = 0; i < input.size(); i ++) {
    char c = input[i];
    if (c == ' ') continue;
    if (c == ',') {
      if (inside) res += c;
      else res += '|';
      continue;
    }
    if (c == '"') {
      if (i > 0 && input[i-1] == '"' && used != i-1) {res += c; used = i;}
      else inside = !inside;
      continue;
    }
    res += c;
  }
  cout << res << endl;
}


