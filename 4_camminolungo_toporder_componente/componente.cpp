#include <vector>
#include <fstream>
#include <stack>
#include <iostream>

using namespace std;
typedef vector<vector<int>> Graph;

void topOrder(Graph& g, stack<int>& s);
void topOrderAux(Graph& g, int node, vector<bool>& visitato, stack<int>& s);
void connectedComponents(Graph& g, stack<int> s, vector<int>& cc, vector<int>& maxComponents);
void connectedComponentsAux(Graph& g, vector<int>& components, int attuale, int n, vector<int>& maxComponents);
Graph trasport(Graph& g);
int maxStronglyConnectedComponents(Graph& g);
int max(vector<int> v);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n, m;
  in >> n >> m;

  Graph g(n);

  for (int i = 0; i < m; i++) {
      int start, end;
      in >> start >> end;
      g[start].push_back(end);
  }
  out << maxStronglyConnectedComponents(g);
  return 0;
}

int maxStronglyConnectedComponents(Graph& g){
  stack<int> s;
  topOrder(g,s);
  Graph g1 = trasport(g);
  vector<int> cc(g1.size());
  vector<int> maxcc(g1.size());
  connectedComponents(g1,s,cc,maxcc);
  return max(maxcc);
}

void topOrder(Graph& g, stack<int>& s){
  vector<bool> visitato(g.size(), false);
  for (int i = 0; i < g.size(); i++) {
    if (!visitato[i])
      topOrderAux(g,i,visitato,s);
  }
}

void topOrderAux(Graph& g, int node, vector<bool>& visitato, stack<int>& s){
  visitato[node] = true;
  for (int i = 0; i < g[node].size(); i++) {
    if (!visitato[g[node][i]])
      topOrderAux(g,g[node][i],visitato,s);
  }
  s.push(node);
}

Graph trasport(Graph& g){
  Graph g1(g.size());
  for (int i = 0; i < g.size(); i++) {
    for(int e = 0; e <g[i].size(); e++)
      g1[g[i][e]].push_back(i);
  }
  return g1;
}

void connectedComponents(Graph& g, stack<int> s, vector<int>& cc, vector<int>& maxComponents){
  int componente = 0;
  while (!s.empty()) {
    int e = s.top();
    s.pop();
    if(cc[e]== 0){
      componente +=1;
      maxComponents.push_back(0);
      connectedComponentsAux(g,cc,componente,e,maxComponents);
    }
  }
}

void connectedComponentsAux(Graph& g, vector<int>& components, int attuale, int n, vector<int>& maxComponents){
  components[n] = attuale;
  maxComponents[attuale-1] += 1;
  for (int i = 0; i < g[n].size(); i++) {
    if(components[g[n][i]] == 0){
      connectedComponentsAux(g,components,attuale, g[n][i], maxComponents);
    }
  }
}

int max(vector<int> v){
  int max = v[0];
  for(int e:v){
    if(e>max)
      max = e;
  }
  return max;
}
