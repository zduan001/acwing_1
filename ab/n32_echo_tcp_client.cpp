#include <iostream>
#include <cmath>

using namespace std;

typedef pair<double, double> pdd;

class Server{
public:
  void throttle(double x) {
    pressure = x;
  }

  pdd status() {
    return {pressure, pressure/3};
  }

private: 
  double pressure;
  double speed;

};

bool check(double target, double mid, Server sev) {
  sev.throttle(mid);
  pdd res = sev.status();
  return (res.second > target) || (abs(res.second - target) < 0.001);
}

double search(double target, Server sev) {
  double l = 0, r = 100;
  while(abs(l-r) > 0.001) {
    double mid = (l+r)/2.0;
    if (check(target, mid, sev)) r = mid;
    else l = mid;
  }
  return l;
}

int main() {

  Server sev;
  cout << search(29.0, sev) << endl;
  return 0;

}