#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <cstring>
#include <time.h>

using namespace std;


class Master{
public:
  Master(string str) : s(str){}
  int guess(string word) {
        unordered_set<char> s;
    for (char c : s) s.insert(c);
    int res = 0;
    for (char c : word) {
      if (s.count(c)) res++;
    }
    return res;
  
  }
private:
  string s;
};

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
  void findSecretWord(vector<string>& wordlist, Master& master) {
    int n = wordlist.size();
    bool st[n];
    memset(st, false, sizeof st);

    map<int, vector<int>> g[n];
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int dist = check(wordlist[i], wordlist[j]);
        g[i][dist].push_back(j);
        g[j][dist].push_back(i);
      }
    }
    
    srand (time(NULL));
    int s = rand() %n;
    queue<int> q;
    q.push(s);
    
    while(q.size()) {
      int u = q.front(); q.pop();
      cout << wordlist[u] << endl;
      if (st[u]) continue;
      st[u] = true;
      int dist = master.guess(wordlist[u]);
      for (int v : g[u][dist]) {
        q.push(v);
      }
      if (!q.size()) {
        for (int i = 0 ; i < n; i++) {
          if (!st[i]) {q.push(i); break;}
        }
      }
    }
  }

  int check(string s1, string s2) {
    unordered_set<char> s;
    for (char c : s1) s.insert(c);
    int res = 0;
    for (char c : s2) {
      if (s.count(c)) res++;
    }
    return res;
  }
};

int main() {
//   "acckzz"
// ["acckzz","ccbazz","eiowzz","abcczz"]
// 10
  Solution sol;
  Master master("eiowzz");
  vector<string> input = {"acckzz","ccbazz","eiowzz","abcczz"};
  sol.findSecretWord(input, master);
  return 0;
}