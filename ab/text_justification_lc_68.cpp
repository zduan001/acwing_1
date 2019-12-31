#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
      vector<string> res;
      int len= 0;
      int i = 0;
      while(i < words.size()) {
        int j = i, len = 0;
        while(j < words.size() && 
              len + words[j].length() + j -i <= L) {
          len += words[j].length();
          j++;
        }

        int space = L - len;
        int blank = (j-i-1) == 0 ? space : space/(j-i-1);
        int extra = (j-i-1) == 0 ? 0 : space % (j-i-1);

        string out = "";
        for (int k = i; k < j; k++) {
          out += words[k];
          int tmp = 0;
          if (space > 0) {
            if (j == words.size()) {
              if (k == words.size()-1) tmp = space;
              else tmp = 1;
            } else {
              tmp = blank;
              if (extra){tmp++; extra--;}
            }
          }
          out.append(tmp, ' ');
          space -= tmp;
        }
        res.push_back(out);
        i = j;
      }
      return res;      
    }
};

int main() {
  Solution sol;

//   ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
// 20
  vector<string> input = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
  vector<string> res = sol.fullJustify(input, 20);
  for (auto s : res) {
    cout << s << "|" << endl;
  }
  return 0;
}