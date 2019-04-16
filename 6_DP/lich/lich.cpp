/*

Dijkstra da ogni nodo per capire i momenti di arrivo
isolare nodi vicini e dentro il limite L

O(N^2 * logN)


*/


#include <vector>

#include <fstream>
#include <stack>
#include <iostream>

using namespace std;

int lich(vector<vector<int>>& g);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n, m;
  in >> n >> m;

  vector<vector<int>> g(n);

  for (int i = 0; i < m; i++) {
    int start, end;
    in >> start >> end;
    gstart].push_back(end);
  }

  vector<int> distances = maxDistance(grafo);


  return 0;
}

vector<int> maxDistance(vector<vector<int>> g){
  vector<int> ret(g.size(),-1);
  for(int n:g.size())
    ret[n] = erdosNumber(g,n);
  return ret;
}


vector<int> erdosNumber(vector<vector<int>> g, int s){
  queue<int> q;
  q.push(s);
  vector<int> erdos(g.size(),-1);
  int ret = 0;
  erdos[s] = 0;
  while(!q.empty()){
    int e = q.front();
    q.pop();
    for(int i: g[e]){
      if(erdos[i] == -1){
        erdos[i] = erdos[e] + 1;
        ret = max(ret,erdos[i]);
        q.push(i);
      }
    }
  }
  return ret;
}
