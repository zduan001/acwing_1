#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int dist[n], tmp[n];
        memset(dist, 0x3f, sizeof dist);
        memcpy(tmp, dist, sizeof dist);
        dist[src] = 0;

        for (int i = 0;i <=K=1; i++) {
          for (auto flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            if (dist[v] > tmp[u] + w) {
              dist[v] = tmp[u]+w;
            }
          }
          memcpy(tmp, dist, sizeof dist);
        }
        if (dist[dst] == 0x3f3f3f3f) return -1;
        else return dist[dst];
    }
};


int main() {

}