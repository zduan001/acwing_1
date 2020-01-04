#include <iostream>

using namespace std;


void dfs(string original, string tmp, int idx) {
  if (idx == original.length()) {
    cout << tmp << endl;
    return ;
  }

  int c = tolower(original[idx])-'a';
  string tmp1 = tmp;
  string tmp2 = tmp;
  dfs(original, tmp1.append(1, 'a'+c), idx+1);
  dfs(original, tmp2.append(1, 'A'+c), idx+1);
}

int main() {

  string str = "AbC";

  dfs(str, "", 0);
  return 0;
}