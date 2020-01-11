#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct span{
  int l, r, len;
  bool left, right;

  bool operator<(const span& rhs) const {
    int mid = (rhs.l+ rhs.r)/2;
    int dist2 = min(mid - rhs.l, rhs.r-mid);
    if (!rhs.left || !rhs.right) dist2 = rhs.r- rhs.l;
    mid = l+r >> 1;

    int dist1 = min(mid-l, r-mid);
    if (!left || !right) dist1 = r-l;
    if (dist1 == dist2) return l < rhs.l;
    else return dist1 > dist2;
  }
};

typedef pair<int, span> pis;

class ExamRoom {
public:
  ExamRoom(int N) : size(N) {
    span tmp = {0, size-1, size-1, false, false};
    q.insert(tmp);
  }
  
  int seat() {
    auto u = *q.begin(); q.erase(q.begin());
    if (!u.left) {
      u.left = true; 
      q.insert(u);
      return u.l;
    } else if (!u.right) {
      u.right = true;
      q.insert(u);
      return u.r;
    } else {
      int mid = (u.l + u.r)/2;
      span s1 = {u.l, mid, mid-u.l, true, true};
      span s2 = {mid, u.r, u.r-mid, true, true};
      q.insert(s1);
      q.insert(s2);
      return mid;
    }
  }
  
  void leave(int p) {
    // priority_queue<span, vector<span>, less<span>> tmp;
    set<span> tmp;
    vector<span> holder;
    while(q.size()) {
      auto u = *q.begin(); q.erase(q.begin());
      if (u.l == p || u.r == p) {
        holder.push_back(u);
      } else {
        tmp.insert(u);
      }
    }

    q = tmp;
    if (holder.size() == 2) {
      if (holder[0].l > holder[1].l) swap(holder[0], holder[1]);

      int l = min(holder[0].l, holder[1].l);
      int r = max(holder[0].r, holder[1].r);
      span s = {l, r, r-l, holder[0].left, holder[1].right};
      q.insert(s);
    } else {
      span s;
      if (p == holder[0].l) {
        s = {p, holder[0].r, holder[0].r -p, false, holder[0].right};
      } else {
        s = {holder[0].l, p, p - holder[0].l, holder[0].left, false};
      }
      q.insert(s);
    }
  }

private:
  int size;
  int cnt;
  // priority_queue<span, vector<span>, less<span>> q;
  set<span> q;
};

int main() {
  ExamRoom room(10);
  cout << room.seat() << endl;
  cout << room.seat() << endl;
  cout << room.seat() << endl;
  // cout << room.seat() << endl;
  room.leave(0);
  room.leave(4);
  cout << room.seat() << endl;
  cout << room.seat() << endl;
  cout << room.seat() << endl;
  cout << room.seat() << endl;
  cout << room.seat() << endl;
  cout << room.seat() << endl;
  cout << room.seat() << endl;
  cout << room.seat() << endl;
  cout << room.seat() << endl;
  room.leave(0);
  room.leave(4);
  cout << room.seat() << endl;
  cout << room.seat() << endl;
}