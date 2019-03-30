#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
vector<int> parser(string a);
int scherlockAux(vector<int>& s, int k);
int sherlock(vector<vector<int>>& DP, vector<vector<int>>& nights, int k, int i);

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
  out << sherlock(DP,nights,t,0);


  return 0;
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

int scherlockAux(vector<int>& s, int k){
  if (k == 0)
    return 0;
  else{
    //s[0] perchè il primo può solo scegliere se stesso
    vector<vector<int>> DP(k,vector<int> (s.size(),s[0]));

    //k = 0 somma alternata
    for (int i = 0; i < 2 && i<DP[0].size(); i++)
      DP[0][i] = s[i];
    for (int i = 2; i < DP[0].size(); i++)
      DP[0][i] = s[i] + DP[0][i-2];

    //la condizione max sul secondo restituirà sempre quel caso,
    //per gli altri calcolo quello che mi conviene
    for (int k = 1; k < DP.size(); k++) {
      DP[k][1] = DP[k-1][0]+s[1];
      for (int i = 2; i < DP[0].size(); i++)
        DP[k][i] = max(DP[k-1][i-1]+s[i],max(DP[k][i-1],DP[k][i-2]+s[i]));
    }
    // max si trova nell'ultima posizione
    return DP[k-1][s.size()-1];
  }
}

int sherlock(vector<vector<int>>& DP, vector<vector<int>>& nights, int k, int i){
  if(i>=nights.size())
    return 0;
  if(DP[k][i]==-1){
    int s = 0;
    for (int r = 0; r <= k; r++)
      s = max(s,scherlockAux(nights[i],k-r)+sherlock(DP,nights,r,i+1));
    DP[k][i] = s;
  }
  return DP[k][i];
}
