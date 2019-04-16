#include <vector>
#include <fstream>
#include <string>

using namespace std;

int lcs(string a, string b);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  string a,b;
  in >> a >> b;
  out << lcs(a,b);
  return 0;
}

int lcs(string a, string b){
  vector<vector<int>> DP(a.size()+1,vector<int> (b.size()+1,0));
  for (int i = 1; i < DP.size(); i++)
    for (int j = 1; j < DP[i].size(); j++)
      if (a[i-1]==b[j-1])
        DP[i][j] = DP[i-1][j-1]+1;
      else
        DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
  return DP[a.size()][b.size()];
}
