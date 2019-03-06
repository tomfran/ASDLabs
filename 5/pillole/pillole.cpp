
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long pillole(vector<vector<long long>>& DP, int n);
int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int n;
  in >> n;
  vector<vector<long long>> DP(n+1,vector<long long>(n+1));
  out << pillole(DP,n);
  for (int i = 0; i < DP.size(); i++) {
    for (size_t j = 0; j < DP.size(); j++) {
      std::cout << DP[i][j] << ' ';
    }std::cout <<'\n';
  }
  return 0;
}


long long pillole(vector<vector<long long>>& DP, int n){
  for (int m = 0; m < DP.size(); m++)
    DP[0][m] = 1;
  for (int i = 1; i < DP.size(); i++) {
    DP[i][0] = DP[i-1][1];
    for (int m = 1; m < DP.size()-i; m++)
      DP[i][m] = DP[i][m-1] + DP[i-1][m+1];
  }
  return DP[n][0];
}
