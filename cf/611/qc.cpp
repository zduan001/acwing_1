#include <iostream>

using namespace std;

#define N 200005

int n;
int a[N];
int din[N];

int main() {
  cin >> n; 
  int miss = 0;
  for (int i = 1;i <= n; i++) {
     cin >> a[i];
     din[a[i]]++;
     if (!a[i]) miss++;
  }

  int l = 1, r = 1;
  while(miss) {
    if (l > n || r > n) {l = r = 1;}  
    while(l <= n && a[l]) l++;
    while(r <= n && din[r]) r++;
    cout << l << " " << r << endl;
    if (l!= r) {
      a[l] = r;
      din[r] = l;
      miss--;
    } 
    l++, r++;
    for (int i = 1; i <=n; i++) cout << a[i] << " ";
  }

  for (int i = 1; i <=n; i++) cout << a[i] << " ";
  cout << endl;
}
