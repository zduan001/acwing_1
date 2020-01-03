#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define N 1005

typedef pair<int, int> pii;

int n;
int q[N];
int maxv;

int quick_find(int l, int r, int k) {
  if (l>=r) return q[l];
  int x = q[l], i = l-1, j = r+1;
  while(i<j) {
    while(q[++i]<x);
    while(q[--j]>x);
    if (i < j) swap(q[i], q[j]);
  }

  int sl = j -l+1;
  if (k <= sl) return quick_find(l, j, k);
  else return quick_find(j+1, r, k -sl);
}

double find_median_with_pq(){
  priority_queue<int> maxq;
  priority_queue<int, vector<int>, greater<int>> minq;

  for (int i = 0;i < n; i++) {
    if (maxq.size() == 0 || q[i] > maxq.top()) minq.push(q[i]);
    else maxq.push(q[i]);
    int n = maxq.size(), m = minq.size();
    if (n - m > 1) {
      minq.push(maxq.top()); maxq.pop();
    } else if (m -n  > 1) {
      maxq.push(minq.top()); minq.pop();
    }
  }

    if (maxq.size() == minq.size()) {
      int l = maxq.top(), r = minq.top();
      return ((double)l + (double)r) / 2.0;
    }
    if (maxq.size() > minq.size()) {
      return (double)maxq.top();
    }
    if (minq.size() > maxq.size()) {
      return (double)minq.top();
    }
}

int main() {
  cin >> n;

  for(int i = 0;i < n; i++) {
    q[i] = rand() % (2*n);
  }
  // n = 5;
  // q[0] = 2, q[1] = 4, q[2] = 1, q[3] = 5, q[4] = 3;
  
  cout << find_median_with_pq() << endl;

  if (n%2) cout << quick_find(0, n-1, n/2+1)<< endl;
  else {
    int r = quick_find(0, n-1, n/2+1);
    int l = quick_find(0, n-1, n/2);
    cout << ((double)l+r)/2.0 << endl;
  }
}
