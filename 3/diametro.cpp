#include <vector>
#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

vector<int> erdosNumber(vector<vector<int>> g, int s);
int max(vector<int> v);
void stampa(vector<int> v);


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
      grafo[end].push_back(start);
  }

  int maxErdos = 0;
  for (int i = 0; i < grafo.size(); i++) {
    vector<int> erdos = erdosNumber(grafo,i);
    int temp = max(erdos);
    //stampa(erdos);
    if (temp>maxErdos)
      maxErdos = temp;
  }
  out << maxErdos;
  return 0;
}

vector<int> erdosNumber(vector<vector<int>> g, int s){
  queue<int> q;
  q.push(s);
  vector<int> erdos(g.size(),-1);
  erdos[s] = 0;
  while(!q.empty()){
    int e = q.front();
    q.pop();
    for (int i = 0; i < g[e].size(); i++) {
      if(erdos[g[e][i]]==-1){
        erdos[g[e][i]] = erdos[e] + 1;
        q.push(g[e][i]);
      }
    }
  }
  return erdos;
}

void stampa(vector<int> v){
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}


int max(vector<int> v){
  int max = v[0];
  for (int i = 0; i < v.size(); i++) {
    if(v[i]>max)
      max = v[i];
  }
  return max;
}
