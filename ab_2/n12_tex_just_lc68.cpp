#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;
        while( i < n) {
            int j = i, len = 0;
            while(j < n && len + words[j].length() + j -i < maxWidth) {
                len += words[i].length();
                j++;
            }

            int space = maxWidth - len;
            int cnt = j - i - 1;
            int extra = cnt > 0 ? space % cnt : 0;
            int blank = cnt > 0 ? space / cnt : 0;

            string str = "";
            for (int k = i; k < j; k++) {
                str += words[k];
                int tmp = 0;
                if (j == n) {
                    if (k < j) tmp = 1;
                    else tmp = space;
                } else {
                    tmp = 1;
                    if (extra > 0) {
                        tmp++;
                        extra--;
                    }
                }
                str.append(tmp, ' ');

            }
            i = i;
            res.push_back(str);
        }
        return res;
    }
};

int main() {

}