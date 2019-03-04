#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int zaino(int c, int n, vector<vector<int>> values);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n,c;
  in >> c >> n;

  vector<vector<int>> values(n, vector<int>(2));

  for (int i = 0; i < n; i++)
    in >> values[i][0] >> values[i][1];

  out << zaino(c,n,values);
  return 0;
}

int zaino(int c, int n, int i, vector<vector<int>>& values, map<pair<int,int>,int>& DP){
  if(i==n)
    return 0;

  if(DP.find({n,c}) == DP.end())
    if(values[i][0]<=c)
      DP[{n,c}] = max(values[i][1] + zaino(c-values[i][0],n,i+1,values,DP),
                    zaino(c,n,i+1,values,DP));
    else
      DP[{n,c}] = zaino(c,n,i+1,values,DP);

}

/*
int zaino(int c, int n, vector<vector<int>> values){
  vector<vector<int>> DP(n+1, vector<int>(c+1));
  for (int i = 1; i < DP.size(); i++) {
    for (int j = 1; j < DP[i].size(); j++) {
      if(values[i-1][0]<=j){
        DP[i][j] = max(DP[i-1][j-values[i-1][0]] + values[i-1][1],
                       DP[i-1][j]);
      }else
        DP[i][j] = DP[i-1][j];
    }
  }
  return DP[n][c];
}
*/
