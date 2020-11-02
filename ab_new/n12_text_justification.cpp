#include <iostream>
#include <vector>

using namespace std;

vector<string> fulljustify(vector<string> s, int maxWidth) {
    vector<string> res;
    for (int i = 0; i < s.size(); i++){
        int j = i+1;
        int len = s[i].size();
        while(j < s.size() && len + 1 + s[j].size() <= maxWidth) {
            len = len + 1 + s[j++].size();
        }
        string tmp = "";
        if (j == s.size() || j == i + 1) { // 最后一行，或者只有一个词， 左对齐
            tmp = s[i];
            for (int k = i+1; k < j; k++) {
                tmp += ' ' + s[k];
            }
            while(tmp.size() < maxWidth) tmp += ' ';
        } else { //中间行，需要两边对齐
            int cnt = j - i - 1, remain = maxWidth - len + cnt;
            tmp = s[i];
            int k = 0;
            while(k < remain % cnt) 
                tmp += string(remain/cnt + 1 , ' ') + s[i+k+1], k++;
            while(k < cnt) 
                tmp+= string(remain/cnt, ' ') + s[i+k+1], k++;
        }
        res.push_back(tmp);
        i = j-1;
    }
    return res;
}

int main() {
    vector<string> s = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> res = fulljustify(s, 16);
    for (auto& x : res) cout << x << '|' <<endl;
    return 0;
}

