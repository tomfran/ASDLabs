
#include <vector>
#include <fstream>
#include <stack>
#include <iostream>

using namespace std;

int camminoLungo(vector<vector<int>>& g);
void camminoLungoAux(vector<vector<int>>& g, int nodoCorrente, stack<int>& s, vector<int>& maxCam);
int max(vector<int> v);

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

  out << camminoLungo(grafo);

  return 0;
}

int camminoLungo(vector<vector<int>>& g){
  stack<int> s;
  vector<int> maxCam(g.size(), -1);

  for (int i = 0; i < g.size(); i++) {
    if (maxCam[i] == -1)
      camminoLungoAux(g,i,s,maxCam);
  }
  return max(maxCam);
}

void camminoLungoAux(vector<vector<int>>& g, int nodoCorrente, stack<int>& s, vector<int>& maxCam){
  maxCam[nodoCorrente] ++;
  int max = 0;
  for (int i = 0; i < g[nodoCorrente].size(); i++) {
    if (maxCam[g[nodoCorrente][i]] == -1)
      camminoLungoAux(g, g[nodoCorrente][i],s,maxCam);
    if (maxCam[g[nodoCorrente][i]]>max) {
      max = maxCam[g[nodoCorrente][i]];
    }
  }
  maxCam[nodoCorrente] += max + ((g[nodoCorrente].size()>=1)? 1:0);
  s.push(nodoCorrente);
}

int max(vector<int> v){
  int max = v[0];
  for(int e:v){
    if(e>max)
      max = e;
  }
  return max;
}
