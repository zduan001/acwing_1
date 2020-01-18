#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

pii dirt[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

vector<string> doesCircleExist(vector<string> commands) {
    int n = commands.size();
    vector<string> res;
    for (int i = 0; i < n; i++) {
        int d = 0;
        int x = 0, y = 0;
        set<piii> st;
        st.insert({{0,0},0});
        bool has_circle = false;
        
        string str = commands[i];
        str += str;
        str += str;
        piii slow = {{0,0},0};
        piii fast = {{0,0},0};
        for (int i = 0;i < str.length(); i ++) {
            char c = str[i];
            if (c == 'G') {
                x += dirt[d].first;
                y += dirt[d].second;
            } else if (c == 'L') {
                d--; 
                if (d == -1) d = 3;

            } else {
                d++;
                if (d == 4) d = 0;
            }
            cout << x << " " << y << " " << d << endl;

            piii next = {{x, y}, d};
            if (st.count(next)) {
                has_circle = true;
                break;
            } else {
                st.insert({{x,y}, d});
            }
        }
        if (has_circle) res.push_back("YES");
        else res.push_back("NO");
    }
    return res;
}

int main() {
    vector<string> com = {"RGL"};
    
    vector<string> res = doesCircleExist(com);

    for (string str : res) cout << str << endl;
    
    return 0;
}