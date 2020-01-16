#include <iostream>

using namespace std;

void dfs(string origin, string str, int idx) {
    if (idx == origin.length()) {
        cout << str<< endl;
        return;
    }
    string tmp = str;
    dfs(origin, tmp.append(1, tolower(origin[idx])), idx+1);
    tmp = str;
    dfs(origin, tmp.append(1, toupper(origin[idx])), idx+1);
}

int main() {
    string str = "ab";
    dfs(str, "", 0);
    return 0;
}
