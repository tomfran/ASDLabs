#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int sottocres(vector<int> v, int lim, int i, int n, map<pair<int,int>,int>& DP);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n;
  in >> n;

  vector<int> v(n);
  for (size_t i = 0; i < n; i++)
    in >> v[i];

  map<pair<int,int>,int> DP;
  out << sottocres(v,0,0,n,DP);
  return 0;
}

int sottocres(vector<int> v, int lim, int i, int n, map<pair<int,int>,int>& DP){
  if(i>=n)
    return 0;
  else if (v[i]<lim)
    return sottocres(v,lim,i+1,n,DP);
  else if(DP.find({i,lim})==DP.end()){
    int taken = v[i] + sottocres(v,v[i],i+1,n,DP);
    int nottaken = sottocres(v,lim,i+1,n,DP);
    DP[{i,lim}] = max(taken,nottaken);
  }
  return DP[{i,lim}];
}
