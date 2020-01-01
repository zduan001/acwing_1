#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> travel_buddy (vector<string> myciteis, vector<vector<string>> friends) {
  unordered_set<string> cities;
  for (auto str : myciteis) cities.insert(str);

  vector<pair<double, int>> buddy;

  for (int i = 0;i < friends.size(); i++) {
    vector<string> per = friends[i];
    int n = per.size();
    if (n == 0) {buddy.push_back({0.0, i}); continue;}
    int cnt = 0;
    for (string c : per) {
      if (cities.count(c)) cnt++;
    }
    buddy.push_back({(double)cnt/n, i});
  }
  sort(buddy.begin(), buddy.end());
  reverse(buddy.begin(), buddy.end());

  vector<int> res; 
  for (auto item : buddy) {
    res.push_back(item.second);
  }
}

int main() {

}