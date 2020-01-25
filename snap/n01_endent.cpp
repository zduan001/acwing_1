#include <iostream>
#include <vector>

using namespace std;
// https://leetcode.com/discuss/interview-question/409902/Snap-or-phone-or-print-indentation-correctly
bool isNullOrEmpty(string x) {
    if (x.length() == 0) return true;
    for (int i = 0;i < x.length(); i++) {
        if (x[i] != ' ') return false;
    }
    return true;
}

vector<string> print (string input) {
    int len = 0;
    vector<string> str;
    string tmp = "";
    for(int i = 0;i < input.length(); i++) {
        if (input[i] == '('){
            if (!isNullOrEmpty(tmp)) str.push_back(tmp);
            tmp = "";
            tmp.append(len, ' ');
            tmp += "(";
            str.push_back(tmp);    
            len += 4;
            tmp = "";
            tmp.append(len, ' ');
        } else if (input [i] == ')') {
            if (!isNullOrEmpty(tmp)) str.push_back(tmp); 
            len -= 4;
            tmp = "";
            tmp.append(len, ' ');
            tmp += ")";
            str.push_back(tmp);
            tmp = "";
            tmp.append(len, ' ');
        } else {
            if (input[i] == ' ') {
                str.push_back(tmp);
                tmp = "";
                tmp.append(len, ' ');
            }else {
                tmp += input[i];
            }
        }
    }
    return str;
}

int main() {
    string input = "(hello word (bye bye))";
    vector<string> res = print(input);
    for (string x : res) {
        cout << x << endl;
    }
    return 0;

}
