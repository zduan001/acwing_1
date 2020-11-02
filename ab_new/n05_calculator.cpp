// leetcode 224
// leetcode 227

#include <iostream>
#include <stack>
using namespace std;

stack<int> nums;
stack<pair<char,int>> op;


void eval() {
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();
    char c = op.top().first; op.pop();
    if (c == '+') nums.push(a+b);
    if (c == '-') nums.push(a-b);
    if (c == '*') nums.push(a*b);
    if (c == '/') nums.push(a/b);
    cout << nums.top() << endl;
}

int cal(string s) {
    int level = 0;
    for (int i = 0;i < s.size(); i++) {
        if (s[i] == ' ') continue;
        if (isdigit(s[i])) {
            int x = 0, j = i;
            while(isdigit(s[j])) 
                x = x * 10 + (s[j] - '0'), j++;
            i = j-1;
            nums.push(x);
        } else if (s[i] == '(') level+=10;
        else if (s[i] == ')') level-=10;
        else {
            int cur = 0;
            if (s[i] == '+' || s[i] == '-') cur = level+1;
            if (s[i] == '*' || s[i] == '/') cur = level+2;

            while(op.size() && op.top().second >= cur) eval();
            op.push({s[i], cur});
        }
    }
    while(op.size()) eval();
    return nums.top();
}


int main() {
    string s = "3 + 8 * (2+4/2)";
    cout << cal(s) << endl;
    return 0;
}
