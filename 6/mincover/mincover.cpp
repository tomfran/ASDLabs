#include <vector>
#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

int minCover(vector<vector<int>> t, int n, int pSig, vector<vector<int>>& DP);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int n;
  in >> n;
  vector<vector<int>> tree(n);
  for (int i = 0; i < n-1; i++) {
      int parent, child;
      in >> parent >> child;
      tree[parent].push_back(child);
  }

  vector<vector<int>> DP(2,vector<int>(n,-1));
  out << minCover(tree,0,true,DP);
  return 0;
}

int minCover(vector<vector<int>> t, int n, int pSig, vector<vector<int>>& DP){
  if(DP[pSig][n] == -1){
    int sig = 1;
    if(pSig){
      int unSig = 0;
      for (int i = 0; i < t[n].size(); i++){
        sig += minCover(t,t[n][i],true,DP);
        unSig += minCover(t,t[n][i],false,DP);
      }
      DP[pSig][n] = min(sig,unSig);
    }else{
      for (int i = 0; i < t[n].size(); i++)
        sig += minCover(t,t[n][i],true,DP);
      DP[pSig][n] = sig;
    }
  }
  return DP[pSig][n];
}
