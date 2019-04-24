#include <vector>
#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

struct edge{
  int d;
  int w;
  int l;
  edge(int dest, int weight, int longest){
    this->d = dest;
    this->w = weight;
    this->l = longest;
  }
};

vector<int> maxDistance(vector<vector<edge>>& g);
int distance(vector<vector<edge>>& g, int s, int f);
void dfsWrapper(vector<vector<edge>>& g, int s, vector<int>& L, vector<int>& longestPath, vector<int>& results);
void dfs(vector<vector<edge>>& g, int s, int a, int f, vector<int>& L, int i, vector<int>& longestPath, vector<int>& results);


int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n, m;
  in >> n;

  vector<vector<edge>> g(n);

  for (int i = 0; i < n-1; i++) {
    int start, end, weight;
    in >> start >> end >> weight;
    edge e1(end,weight,-1);
    edge e2(start,weight,-1);
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

  vector<int> actualresults(L.size());
  for (int i = 0; i<g.size();i++){
    for (int i = 0; i < actualresults.size(); i++) {
      actualresults[i] = 0;
    }
    dfsWrapper(g,i,L,longestPath,actualresults);
    for (int i = 0; i < results.size(); i++)
      results[i] = max(results[i],actualresults[i]);
  }
  for(int r : results)
    out << r << "\n";

  return 0;
}

vector<int> maxDistance(vector<vector<edge>>& g){
  vector<int> ret(g.size(),-1);
  for(int n = 0; n < g.size();n++){
    ret[n] = distance(g,n,n);
  }
  return ret;
}

int distance(vector<vector<edge>>& g, int s, int f){
  int ret = 0;
  for(edge e : g[s]){
    if(e.d!=f){
      if(e.l == -1)
        e.l = e.w+distance(g,e.d,s);
      ret = max(ret, e.l);
    }
  }
  return ret;
}

void dfsWrapper(vector<vector<edge>>& g, int s, vector<int>& L, vector<int>& longestPath, vector<int>& results){
  dfs(g,s,s,s,L,0,longestPath,results);
  for (int i = 1; i < results.size(); i++)
    results[i] += results[i-1];
}

void dfs(vector<vector<edge>>& g, int s, int a, int f, vector<int>& L, int i, vector<int>& longestPath, vector<int>& results){
  if(i<L.size()){
    if(longestPath[a] <= longestPath[s] && longestPath[a] >= longestPath[s]-L[i]){
      results[i]++;
      for(edge e : g[a])
        if(e.d != f)
          dfs(g,s,e.d,a,L,i,longestPath,results);
    }else
      dfs(g,s,a,f,L,i+1,longestPath,results);
  }
}
