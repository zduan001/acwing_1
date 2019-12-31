#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 两个注意点
// 1. K是stop， 所以 循环次数 i<=K
// 2. 本题不同于bellford. 每次比较dist[v]的时候要用上一次的dist[u].
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int dist[n], tmp[n];
        memset(dist, 0x3f, sizeof dist);
        dist[src] = 0;
        
        for (int i = 0; i <= K; i++) {
            memcpy(tmp, dist, sizeof dist);
            for (int j = 0; j < flights.size(); j++) {
                int u = flights[j][0];
                int v = flights[j][1];
                int w = flights[j][2];
                if (dist[v] > tmp[u]+w) {
                    dist[v] = tmp[u]+w;
                }
            }
        }
        
        int res = -1;
        if (dist[dst] != 0x3f3f3f3f) res = dist[dst];
        return res;
    }
};

int main() {
  return 0;
}