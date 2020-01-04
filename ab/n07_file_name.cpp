#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

typedef void (*funt) (void);

class callBack {
public:
    void call(int x) {
        cout << " I am in a call back function " << x << endl;
    }
};

struct node{
    string name;
    int val;
    callBack* funt;
    map<string, node*> children;
} trieNode;

class FileSystem {
public:
    FileSystem(){ root = new node();}
    
    bool create(string path, int value){
        vector<string> tokens = split(path, '/');
        auto tmp = root;
        for (int i = 0;i < tokens.size(); i++) {
            string p = tokens[i];
            if (tmp->children.count(p)) {
                tmp = tmp->children[p];
            } else {
                if (i != tokens.size()-1) {
                    return false;
                } else {
                    node* newnode = new node();
                    tmp->children[p] = newnode;
                    tmp = newnode;
                }
            }
        }
        tmp->val = value;
        return true;
    }
    
    int get(string path) {
        vector<string> tokens = split(path, '/');
        auto tmp = root;
        for (string p : tokens) {
            if (tmp && tmp->children.count(p)) {
                tmp = tmp->children[p];
            } else {
                return -1;
            }
        }
        return tmp->val;
    }
    
    bool set(string path, int value) {
        vector<string> tokens = split(path, '/');
        auto tmp = root;
        for (string p : tokens) {
            if (tmp && tmp->children.count(p)) {
                tmp = tmp->children[p];
            } else {
                return false;
            }
        }
        tmp->val = value;
        if (tmp->funt) tmp->funt->call(tmp->val);
        return true;
    }
    
    bool watch(string path, callBack cb) {
        create(path, 0);
        vector<string> tokens = split(path, '/');
        auto tmp = root;
        for (string p : tokens) {
            if (tmp && tmp->children.at(p)) {
                tmp = tmp->children[p];
            }
        }
        tmp->funt = &cb;
        return true;;
    }
    
private:
    vector<string> split(string s, char delimiter) {
        vector<string> tokens;
        string tmp;
        istringstream tokenStream(s);
        while(getline(tokenStream, tmp, delimiter)) {
            if (tmp == "") continue;
            tokens.push_back(tmp);
        }
        return tokens;
    }
    node *root;
    map<string, funt> mp;
};

int main() {
    callBack cb1;
    callBack cb2;
    
    FileSystem fs;
    fs.create("/AB", 1);
    fs.create("/AB/CD", 2);
    cout << fs.get("/AB") << endl;
    cout << fs.get("/AB/CD") << endl;
    fs.watch("/AB/CD", cb1);
    fs.set("/AB/CD", 5);
    
    return 0;
}
