#include <iostream>
#include <vector>
#include <array>
#include <list>

using namespace std;

#define N 10

class Queue{
public:
  Queue(){}

  void push(int x) {
    if (tt == -1) {
      array<int,10> tmp;
      lt.push_back(tmp);
      tt = 0;
    }

    lt.back()[tt++] = x;
    size++;
    if (tt == N) tt = -1;
  }

  int top() {
    if (!size) return -1; // or throw exception
    return lt.front()[hh];
  }

  void pop() {
    if (!size) return;
    size--;
    hh++;
    if (hh == N) {
      hh = 0;
      lt.pop_front();
    }
  }

private:
  list<array<int, 10>> lt;
  int hh = 0, tt = -1;
  int size = 0;
};


int main() {
  Queue sol;
  for (int i = 0; i < 15; i++) {
    sol.push(i);
  }

  for (int i = 0; i < 5; i ++) {
    cout << sol.top() << endl;
    sol.pop();
  }

  for (int i = 0; i < 15; i++) {
    sol.push(i);
  }


  for (int i = 0; i < 35; i ++) {
    cout << sol.top() << endl;
    sol.pop();
  }


  return 0;
}
