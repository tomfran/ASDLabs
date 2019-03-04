#include <vector>
#include <fstream>
#include <queue>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct arco{
  int dest; //destinazione arco
  int cost; //tempo di percorrenza
  int shutdown; //tempo di primo spegnimento
  int sTime; //tempo spegnimento
  int rTime; //tempo accensione

  arco(int d,int c,int s,int st,int rt){
    this->dest = d;
    this->cost = c;
    this->shutdown = s;
    this->sTime = st;
    this->rTime = rt;
  }
};

void laser(vector<vector<arco>> g,vector<int>& minCosts, vector<int>& minParent);
int timeCost(int time, arco a);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n, m;
  in >> n >> m;
  vector<vector<arco>> grafo(n);
  for (int i = 0; i < m; i++) {
      int start,d,c,s,sT,rT;
      in >> start >> d >> c >> s >> sT >> rT;
      if(c<=sT){
        arco a1(d,c,s,sT,rT);
        grafo[start].push_back(a1);
        arco a2(start,c,s,sT,rT);
        grafo[d].push_back(a2);
      }
  }

  vector<int> minCosts(grafo.size(),INT_MAX);
  vector<int> minParent(grafo.size(),-1);


  laser(grafo,minCosts,minParent);

  vector<int> path;

  if (minCosts[grafo.size()-1]!=INT_MAX) {
    out << minCosts[grafo.size()-1] << endl;
    int temp = grafo.size()-1;

    while(temp>=0){
      path.push_back(temp);
      temp = minParent[temp];
    }
    for (int i = path.size()-1; i >= 0; i--)
      out << path[i] << endl;
  } else
    out << -1 << endl;

  return 0;
}

void laser(vector<vector<arco>> g, vector<int>& minCosts, vector<int>& minParent){
  minCosts[0] = 0;
  int currentNode = 0;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int currentNode = q.front();
    q.pop();
    for (int i = 0; i < g[currentNode].size(); i++) {
      int currentCost = timeCost(minCosts[currentNode],g[currentNode][i]);
      if(currentCost < minCosts[g[currentNode][i].dest]){
          minCosts[g[currentNode][i].dest] = currentCost;
          minParent[g[currentNode][i].dest] = currentNode;
          q.push(g[currentNode][i].dest);
      }
    }
  }
}


int timeCost(int time, arco a){
  int total = time;
  if(time<a.shutdown){
    total += (a.shutdown-time);
  } else{
    int cond = (time-a.shutdown)%(a.sTime+a.rTime);
    if((a.sTime-cond) < a.cost)
      total += a.sTime-cond + a.rTime;
  }
  total += a.cost;
  return total;
}
