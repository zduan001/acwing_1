#include <iostream>
#include <unordered_map>
using namespace std;

typedef struct item{
    string name;
    int val;
    unordered_map<string, item*> children;

    item(string a, int b) {
        name = a; val = b;
    }
} node;

node* root;

void create(string s, int val) {
    node* cur = root;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') continue;
        int j = i;
        while(j < s.size() && s[j] != '/') j++;
        string tmp = s.substr(i, j-i);
        if (j == s.size()) {
            if (cur->children.count(tmp)) {
                cur = cur->children[tmp];
                cur->val = val;
            } else {
                node* new_node = new node({tmp, val});
                cur->children[tmp] = new_node;
            }
            return; // success
        }
        if (cur->children.count(tmp)) {
            cur = cur->children[tmp];
            i = j-1;
        } else {
            return; // failed
        }
    }
}


int get(string s) {
    node* cur = root;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') continue;
        int j = i;
        while(j <s.size() && s[j] != '/') j++;
        string tmp = s.substr(i, j-i);
        if (!cur->children.count(tmp)) return -1;
        cur = cur->children[tmp];
        //if (cur->callback.size() > 0) {
        //    for (auto& callback : callbacks) call them;
        //}
    }
    return cur->val;
}

int main() {
    root = new node({"root", -1});
    create("/a", 1);
    cout << get("/a") << endl;
    create("/a/b", 2);
    cout << get("/a/b") << endl;
    create("/c/d", 1);
    cout << get("/c") << endl;
    return 0;
}
