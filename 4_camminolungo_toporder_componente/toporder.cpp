#include <vector>
#include <fstream>
#include <stack>
#include <iostream>

using namespace std;

void topOrder(vector<vector<int>>& g, stack<int>& s);
void topOrderAux(vector<vector<int>>& g, int node, vector<bool>& visitato, stack<int>& s);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n, m;
  in >> n >> m;

  vector<vector<int>> grafo(n);

  for (int i = 0; i < m; i++) {
      int start, end;
      in >> start >> end;
      grafo[start].push_back(end);
}


  stack<int> s;

  topOrder(grafo,s);

  while (!s.empty()) {
    out << s.top() << " ";
    s.pop();
  }
  return 0;
}

void topOrder(vector<vector<int>>& g, stack<int>& s){
  vector<bool> visitato(g.size(), false);
  for (int i = 0; i < g.size(); i++) {
    if (!visitato[i])
      topOrderAux(g,i,visitato,s);
  }
}

void topOrderAux(vector<vector<int>>& g, int node, vector<bool>& visitato, stack<int>& s){
  visitato[node] = true;
  for (int i = 0; i < g[node].size(); i++) {
    if (!visitato[g[node][i]])
      topOrderAux(g,g[node][i],visitato,s);
  }
  s.push(node);
}
