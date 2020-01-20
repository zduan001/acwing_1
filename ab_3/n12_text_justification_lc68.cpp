#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int k) {
      int n = words.size();
      vector<string> res;
      int i = 0;
      while(i < n) {
        int len = 0, j = i;
        while(j < n && len + words[j].size() + j - i <= k) {
          len += words[j].length();
          j++;
        }

        int blank = k - len;
        int space = (j-i-1) ? blank/(j-i-1) : blank;
        int extra = (j-i-1) ? blank%(j-i-1) : 0;

        string str = "";
        for (int k = i; k < j; k++) {
          str += words[k];
          int tmp = 0;
          if (blank>0) { //mistake: forget this line.
            if (j == n) {
              if (k == n-1) tmp = blank;
              else tmp = 1;
            } else {
              tmp = space;
              if (extra) {
                tmp++;extra--;
              }
            }
          }
          str.append(tmp, ' ');
          blank -= tmp;
        }
        res.push_back(str);
        i = j;
      }
      return res;
    }
};

int main() {
  Solution sol;
  vector<string> input = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
  vector<string> res = sol.fullJustify(input, 20);

  for (string str : res) cout << str << endl;
  return 0;
}

// ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
// 20