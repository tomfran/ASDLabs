#include <vector>
#include <fstream>

using namespace std;

int minCoverPesato(vector<vector<int>>& t, int n, int pSig, vector<vector<int>>& DP, vector<int>& w);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n;
  in >> n;

  vector<int> w(n);
  for (int i = 0; i < n; i++)
    in >> w[i];

  vector<vector<int>> tree(n);
  for (int i = 0; i < n-1; i++) {
      int parent, child;
      in >> parent >> child;
      tree[parent].push_back(child);
  }

  vector<vector<int>> DP(n,vector<int>(2,-1));
  out << minCoverPesato(tree,0,true,DP,w);
  return 0;
}

int minCoverPesato(vector<vector<int>>& t, int n, int pSig, vector<vector<int>>& DP, vector<int>& w){
  if(DP[n][pSig] == -1){
    int sig = w[n];
    if(pSig){
      int unSig = 0;
      for (int i = 0; i < t[n].size(); i++){
        sig += minCoverPesato(t,t[n][i],true,DP,w);
        unSig += minCoverPesato(t,t[n][i],false,DP,w);
      }
      DP[n][pSig] = min(sig,unSig);
    }else{
      for (int i = 0; i < t[n].size(); i++)
        sig += minCoverPesato(t,t[n][i],true,DP,w);
      DP[n][pSig] = sig;
    }
  }
  return DP[n][pSig];
}
