#include <vector>
#include <fstream>
#include <iostream>
#include "tsp.h"

using namespace std;

struct edge{
  int d;
  int w;
  edge(int dest, int weight){
    this->d = dest;
    this->w = weight;
  }
};

struct tsp{
  int n;
  vector<vector<edge>> Graph;
  vector<int> visOrder;
  vector<bool> visited;
  ofstream out;

  tsp(int n){
    this->n = n;
    Graph.resize(n);
    out.open("output.txt");
    //visOrder.resize(n);
    visited.resize(n,false);
  }

  void addEdge(int start, int end, int weight){
    Graph[start].push_back(edge(end,weight));
    Graph[end].push_back(edge(start,weight));
  }

  void printSol(){
    for (int i = 0; i < n-1; i++)
      out << visOrder[i] << " ";
    out << visOrder[n-1] << "#\n";
  }


  void dfs(int node){
    printf("\nNode: %d\n", node);
    visited[node] = true;
    visOrder.push_back(node);
    if(visOrder.size() == n){
      printSol();
      visOrder.pop_back();
      visited[node] = false;
    } else{
      for (int i = 0; i < n; i++) {
        printf("Dest: %d, i: %d\n", Graph[node][i].d, i);
        if (!visited[Graph[node][i].d]) {
          dfs(Graph[node][i].d);
        }
      }
    }
  }

};


int main() {
  ifstream in("input.txt");
  //ofstream out("output.txt");

  int n;
  in >> n;
  int w;
  tsp t(n);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      in >> w;
      t.addEdge(i,j,w);
    }
  }
  t.dfs(0);
  return 0;
}
