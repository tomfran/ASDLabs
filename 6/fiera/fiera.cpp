#include <vector>
#include <fstream>

using namespace std;

struct arco{
  int d;
  int t;
  arco(int d,int c){
    this->d = d;
    this->t = c;
  }
};

int fiera(vector<vector<int>>& t, int n, int pSig, vector<vector<int>>& DP);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int n,k;
  in >> n >> k;
  vector<vector<arco>> tree(n);
  vector<int> barili(n);
  for (int i = 0; i < n; i++)
    in >> barili[i];
  for (int i = 0; i < n; i++) {
      int s, d, t;
      in >> s >> d >> t;
      arco a(d,t);
      tree[s].push_back(a);
  }

  vector<vector<int>> DP(n-1,vector<int>(2,-1));
  return 0;
}

int fiera()

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
