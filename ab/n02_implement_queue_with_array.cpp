#include <iostream> 
#include <array>
#include <list>

using namespace std;

#define N 10

class Solution{
public:
  Solution(){}

  void push(int x) {
    if (tt == -1) {
      array<int, N> tmp;
      lt.push_back(tmp);
    }
    lt.back()[++tt] = x;
    if (tt == N-1) tt = -1;
    size++;
  }

  int front() {
    if (size == 0) return -1;
    return lt.front()[hh];
  }

  void pop() {
    if (size == 0) return;
    hh++;
    size--;
    if (hh == N) {
      hh = 0;
      lt.pop_front();
    }
  }
private:
  list<array<int, N>> lt;
  int hh = 0, tt = -1; // 
  int size = 0;
};

int main() {
  Solution sol;
  for (int i = 1;i < 15; i++) {
    sol.push(i);
  }
  for (int i = 0; i < 20; i++) {
    cout << sol.front() << endl;
    sol.pop();
  }
}