#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
int quadBinario(vector<vector<bool>>);

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n;
  in >> n;
  vector<vector<bool>> mat(n, vector<bool>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      int tmp;
      in >> tmp;
      mat[i][j] = (tmp == 1);
    }
  }
  out << quadBinario(mat);
  return 0;
}

int quadBinario(vector<vector<bool>> mat){
  vector<vector<int>> DP(mat.size(), vector<int>(mat[1].size(),-1));
  int quad = 0;
  for (int i = 0; i < DP.size(); i++){
    DP[0][i] = DP[i][0] = mat[0][i];
    quad = max(quad,max(DP[0][i],DP[i][0]));
  }
  for (int i = 1; i < DP.size(); i++)
    for (int j = 1; j < DP[0].size(); j++){
      DP[i][j] = (mat[i][j])? 1 + min(min(DP[i-1][j],DP[i][j-1]),DP[i-1][j-1]) : 0;
      quad = max(quad,DP[i][j]);
    }
  return quad;
}
