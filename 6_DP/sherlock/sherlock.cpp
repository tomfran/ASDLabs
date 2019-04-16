#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
vector<int> parser(string a);
int sherlock(vector<vector<int>>& DP, vector<vector<int>>& DPAUX, vector<vector<int>>& nights, int k, int i);
int scherlockAux(vector<int>& s, int k, int i,vector<vector<int>>& DPAUX);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n,m,t;
  in >> n >> m >> t;
  vector<vector<int>> nights(n);
  for (int i = 0; i < n; i++) {
    string tmp;
    in >> tmp;
    nights[i] = parser(tmp);
  }

  vector<vector<int>> DP(t+1,vector<int> (n,-1));
  vector<vector<int>> DPAUX(t+1,vector<int> (n,-1));
  for (int i = 0; i < DP[0].size(); i++)
    DP[0][i] = DPAUX[0][i] = 0;

  out << sherlock(DP,DPAUX,nights,t,0);

  return 0;
}

int sherlock(vector<vector<int>>& DP, vector<vector<int>>& DPAUX, vector<vector<int>>& nights, int k, int i){
  if(i>=nights.size())
    return 0;
  if(DP[k][i]==-1){
    int s = 0;
    for (int r = 0; r <= k; r++)
      if((k-r)<=nights[i].size())
        s = max(s,scherlockAux(nights[i],k-r,i,DPAUX)+sherlock(DP,DPAUX,nights,r,i+1));
    DP[k][i] = s;
  }
  return DP[k][i];
}

int scherlockAux(vector<int>& s, int k, int i,vector<vector<int>>& DPAUX){
  if (DPAUX[k][i]==-1){
    //s[0] perchè il primo può solo scegliere se stesso
    vector<vector<int>> DP(2,vector<int> (s.size(),s[0]));
    //k = 0 somma alternata
    for (int i = 0; i < 2 && i<DP[0].size(); i++)
      DP[0][i] = s[i];
    for (int i = 2; i < DP[0].size(); i++)
      DP[0][i] = s[i] + DP[0][i-2];
    //la condizione max sul secondo restituirà sempre quel caso, per gli altri calcolo quello che mi conviene
    for (int t = 1; t < k; t++) {
      DP[1][1] = DP[0][0]+s[1];
      for (int i = 2; i < DP[0].size(); i++)
        DP[1][i] = max(DP[0][i-1]+s[i],max(DP[1][i-1],DP[1][i-2]+s[i]));
      DP[0] = DP[1];
    }
    // max si trova nell'ultima posizione
    if(k>1)
      DPAUX[k][i] = DP[1][s.size()-1];
    else
      DPAUX[k][i] = max(DP[0][s.size()-1],DP[0][s.size()-2]);
  }
  return DPAUX[k][i];
}

vector<int> parser(string a){
  vector<int> v(1,0);
  char prev = a[0];
  int pos = 0;
  for (int i = 0; i < a.size(); i++) {
    if(a[i] == prev){
      v[pos]++;
    }
    else{
      v.push_back(1);
      pos++;
      prev = a[i];
    }
  }
  return v;
}
