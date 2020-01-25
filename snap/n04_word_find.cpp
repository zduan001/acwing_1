// https://leetcode.com/discuss/interview-question/125011/Snapchat-or-Word-Finder
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// answer should include "son" too. need to change the code. 
// this is only a phone interview question????
int main() {
    vector<string> input = {
     "chat", "ever", "snapchat", "snap", "salesperson",
     "per", "person", "sales", "son", "whatsoever",
     "what", "so"};

    //      std::array<int, 10> vec = { 1,2,3,4,5,6,7,8,9 };
    // std::sort(std::begin(vec ), std::end(vec ), [](int a, int b) {return a > b; });
    // for (auto item : vec)
    //   std::cout << item << " ";

    // return 0;

     sort(input.begin(), input.end(), 
        [](string a, string b)
            {return a.length() < b.length();}
     );

     int n = input.size();
     int din[n];
     memset(din, 0, sizeof din);

     for(int i = 0;i < n; i++) {
         for(int j = 0; j < n; j++) {
             if (i == j) continue;
             if (input[i].find(input[j]) != string::npos) din[i]++;
         }
     }

     vector<string> res;
     for (int  i = 0;i < n; i++) {
         if (din[i] == 0) res.push_back(input[i]);
     }

     for (string x : res) {
         cout << x << endl;
     }
     return 0;
}
