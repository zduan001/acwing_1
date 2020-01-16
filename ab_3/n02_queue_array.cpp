#include <iostream>
#include <list>
#include <array>

using namespace std;

#define N 10

class MyQueue{
  public:
  void push(int x) {
    if (tt == -1) {
      array<int, N> tmp;
      lt.push_back(tmp);
      tt = 0;
    }
    lt.back()[tt++] = x;
    if (tt == N) tt = -1;
    size++;
  }

  int front() {
    int res = -1;
    if(size > 0) {
      res = lt.front()[hh];
    }
    return res;
  }

  void pop() {
    if (size > 0) {
      hh++;
      if (hh == N) {
        hh = 0;
        lt.pop_front();
      }
      size--;
    }
  }

private:
  list<array<int,N>> lt;
  int hh = 0, tt = -1;
  int size = 0;
};


int main() {
  MyQueue que;
  for (int i = 1;i < 15; i++) {
    que.push(i);
  }

  for (int i = 1;i <= 7;i++) {
    cout << que.front() << endl;
    que.pop();
  }

  cout << " ---------------- ";

  for (int i = 1;i < 15; i++) {
    que.push(i);
  }

  for (int i = 1;i <= 30;i++) {
    cout << que.front() << endl;
    que.pop();
  }
}
