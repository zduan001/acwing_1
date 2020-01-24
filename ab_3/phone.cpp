#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <locale>         // std::locale, std::tolower

using namespace std;

string tolower(string x) {
  string res = "";
  for (int i = 0;i < x.length(); i++) {
    res += tolower(x[i]);
  }
  return res;
}

string transform(string input, unordered_map<string ,string> mp) {
    map<int, string> loc;
    string lower_case_input = tolower(input);
    
    for(auto item : mp) {
        string key = tolower(item.first);
        int idx = 0;
        while(idx != string::npos) {
            idx = lower_case_input.find(key, idx+1);
            if (idx == string::npos) break;
            loc[idx] = item.first;
        }
    }
    
    string output_str = "";
    int l = 0;
    for (auto item : loc) {
        int idx = item.first;
        string key = item.second;
        output_str += input.substr(l, idx-l);
        output_str += "[";
        output_str += mp[key];
        output_str += "]";
        output_str += "{";
        output_str += input.substr(idx, key.length());
        output_str += "}";
        l = idx + key.length();
    }
    
    output_str += input.substr(l, input.length() - l);
    
    return output_str;
}

int main() {
    string input = "I like Airbnb the san francisco, and Airbnb is a san francisco bussiness";
    unordered_map<string, string> mp;
    mp["san francisco"] = "city";
    mp["airbnb"] = "business";

    string res = transform(input, mp);
    cout << res << endl;
    
}