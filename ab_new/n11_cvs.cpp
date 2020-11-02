#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s = "John,Smith,john.smith@gmail.com,Los Angeles,1 \n Jane,Roberts,janer@msn.com,\"San Francisco, CA\",0 \n  \"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1 \"\"\"Alexandra Alex\"\"";
    vector<string> res;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        if (s[i] == '\n') {
            tmp.pop_back();
            res.push_back(tmp);
            tmp = "";
        }
        if (s[i] == ',') {tmp += "|"; continue;}
        if (s[i] == '"') {
            if (i == s.size()-1 || s[i+1] == '"') {
                tmp += "\"";
                i++;
            } 
            continue;
        }
        int j = i;
        while(j < s.size() && s[j] != ',' && s[j] != '"') j++;
        tmp += s.substr(i, j-i);
        i = j-1;
    }
    res.push_back(tmp);
    
    for (auto& x : res) cout << x << endl;
    return 0;
}
