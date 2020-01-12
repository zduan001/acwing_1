#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct person{
  string name;
  vector<person*> children;
  person* parent;
};

unordered_map<string, person*> mp;
person* root;

void birth(string parent, string child) {
  auto par = mp[parent];
  person* ch = new person();
  ch->name = child;
  ch->children = vector<person*>();
  ch->parent = par;
  par->children.push_back(ch);
  mp[child] = ch;
}

vector<string> get_order() {
  stack<person*> stk;
  vector<string> res;

  stk.push(root);

  while(stk.size()) {
    person* u = stk.top(); stk.pop();
    res.push_back(u->name);

    for(int i = u->children.size() -1; i >= 0; i--)
      stk.push(u->children[i]);
  }
  return res;
}

void del(string name) {
  person* u = mp[name];
  person* par = u->parent;

  if (u->children.size() == 0) {
    for (int i = 0;i < par->children.size(); i++) {
      if (u == par->children[i]) 
        par->children.erase(par->children.begin() + i);
    }
    return;
  }

  person* x = u->children[0];
  for (int i = 1; i < u->children.size(); i++) {
    x->children.push_back(u->children[i]);
  }

  u->name = x->name;
  u->children = x->children;
}

int main() {
  root = new person();
  root->name = "king";
  root->children = vector<person*>();
  mp["king"] = root;
  
  birth("king", "1");
  birth("king", "2");
  birth("king", "3");
  birth("1", "1_1");
  birth("1", "1_2");
  birth("1", "1_3");
  birth("2", "2_1");

  vector<string> res = get_order();
  for (string str : res) cout << str << endl;


  cout << "---------------" << endl;

  del("1_1");

  res = get_order();
  for (string str : res) cout << str << endl;


  return 0;
}