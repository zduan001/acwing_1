#include <iostream>

using namespace std;

#define N 100005

typedef long long LL;

int n, m;
int a[N];

struct Node {
  int l, r;
  LL sum, add;
} tr[4 * N];

void pushup(int u) {
  tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u, int l, int r) {
  if (l == r) {
    tr[u] = {l, r, a[r], 0};
    return;
  }
  tr[u] = {l, r};
  int mid = l+r >> 1;
  build(u<<1, l, mid); build(u <<1|1 , mid+1, r);
  pushup(u);
}

void pushdown(int u) {
  auto &root = tr[u], &left = tr[u<<1], &right = tr[u<<1|1];
  if (root.add) {
    left.add += root.add; left.sum += (LL)(left.r-left.l+1)*root.add;
    right.add += root.add; right.sum += (LL)(right.r-right.l+1)*root.add;
    root.add = 0;
  }
}

void modify(int u, int l, int r, int add) {
  if (tr[u].l >= l && tr[u].r <= r) {
    tr[u].sum += (LL)(tr[u].r-tr[u].l+1)*add;
    tr[u].add += add;
  } else {
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u<<1, l, r, add);
    if (r > mid) modify(u<<1|1, l, r, add);
    pushup(u);
  }
}

LL query(int u, int l, int r) {
  // cout << u << " " << tr[u].l << " " << tr[u].r << " " << tr[u].sum << " " <<tr[u].add << " " << l << " " << r << endl;
  if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
  else {
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL sum = 0;
    if (l <= mid) sum += query(u<<1, l, r);
    if (r > mid) sum += query(u<<1|1, l, r);
    return sum;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  // for (int i = 1;i <= n; i++) cout << tr[i].sum << endl;

  while(m--) {
    char c;
    int l, r, w;
    cin >> c >> l >> r;
    if (c =='Q') {
      cout << query(1, l, r) << endl;
    } else {
      cin >> w;
      modify(1, l, r, w);
    }
  }
  return 0;
}

/*
输入样例：
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
输出样例：
4
55
9
15
*/
