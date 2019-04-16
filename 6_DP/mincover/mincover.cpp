#include <vector>
#include <fstream>

using namespace std;

int minCover(vector<vector<int>>& t, int n, int pSig, vector<vector<int>>& DP);

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

  vector<vector<int>> DP(n,vector<int>(2,-1));
  out << minCover(tree,0,true,DP);
  return 0;
}

int minCover(vector<vector<int>>& t, int n, int pSig, vector<vector<int>>& DP){
  if(DP[n][pSig] == -1){
    int sig = 1;
    if(pSig){
      int unSig = 0;
      for (int i = 0; i < t[n].size(); i++){
        sig += minCover(t,t[n][i],true,DP);
        unSig += minCover(t,t[n][i],false,DP);
      }
      DP[n][pSig] = min(sig,unSig);
    }else{
      for (int i = 0; i < t[n].size(); i++)
        sig += minCover(t,t[n][i],true,DP);
      DP[n][pSig] = sig;
    }
  }
  return DP[n][pSig];
}
