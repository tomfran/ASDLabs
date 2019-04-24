#include <vector>
#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

struct edge{
  int d;
  int w;
  edge(int dest, int weight){
    this->d = dest;
    this->w = weight;
  }
};
vector<int> maxDistance(vector<vector<edge>>& g);
int distance(vector<vector<edge>>& g, int s);
int adj(vector<vector<edge>>& g, int s, int l, vector<int>& longestPath);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n, m;
  in >> n;

  vector<vector<edge>> g(n);

  for (int i = 0; i < n-1; i++) {
    int start, end, weight;
    in >> start >> end >> weight;
    edge e1(end,weight);
    edge e2(start,weight);
    g[start].push_back(e1);
    g[end].push_back(e2);
  }
  int k;
  in >> k;
  vector<int> L(k);
  for (int i = 0; i < k; i++)
    in >> L[i];

  vector<int> longestPath = maxDistance(g);

  vector<int> results(L.size(),-1);

  for (int i = 0; i < L.size(); i++)
    for (int j = 0; j < g.size(); j++)
        results[i] = max(results[i],adj(g,j,L[i],longestPath));

  for(int r : results)
    out << r << "\n";

  return 0;
}

vector<int> maxDistance(vector<vector<edge>>& g){
  vector<int> ret(g.size(),-1);
  for(int n = 0; n < g.size();n++)
    ret[n] = distance(g,n);
  return ret;
}

int distance(vector<vector<edge>>& g, int s){
  queue<int> q;
  q.push(s);
  vector<int> dist(g.size(),-1);
  int ret = 0;
  dist[s] = 0;
  while(!q.empty()){
    int e = q.front();
    q.pop();
    for(edge a : g[e])
      if(dist[a.d] == -1){
        dist[a.d] = dist[e] + a.w;
        ret = max(ret,dist[a.d]);
        q.push(a.d);
      }
  }
  return ret;
}

int adj(vector<vector<edge>>& g, int s, int l, vector<int>& longestPath){
  queue<int> q;
  q.push(s);
  vector<bool> visited(g.size(),false);
  visited[s] = true;
  int ret = 1;
  while(!q.empty()){
    int e = q.front();
    q.pop();
    visited[e] = true;
    for(edge a : g[e])
      if(!visited[a.d]){
        if(longestPath[a.d] <= longestPath[s] && longestPath[a.d] >= longestPath[s]-l){
          ret++;
          q.push(a.d);
        }
      }
  }
  return ret;
}
