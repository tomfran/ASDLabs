#include <vector>
#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

int visita(vector<vector<int>> g, int s);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n, m, s;
  in >> n >> m >> s;

  vector<vector<int>> grafo(n);

  for (int i = 0; i < m; i++) {
      int start, end;
      in >> start >> end;
      grafo[start].push_back(end);
  }

  out << visita(grafo,s);

  return 0;
}

int visita(vector<vector<int>> g, int s){
  int visitCount = 1;
  queue<int> q;
  q.push(s);
  vector<bool> visitato(g.size(),false);
  visitato[s] = true;
  while(!q.empty()){
    int e = q.front();
    q.pop();
    for (int i = 0; i < g[e].size(); i++) {
      if(!visitato[g[e][i]]){
        visitCount++;
        visitato[g[e][i]] = true;
        q.push(g[e][i]);
      }
    }
  }
  return visitCount;
}
