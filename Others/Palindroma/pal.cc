#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int pal(string s);
int palrec(vector<vector<int>>& DP,string& s, int i, int j);


int main(int argc, char const *argv[]) {
  std::cout << pal("fhdjs") << '\n';
  return 0;
}

int pal(string s){
  vector<vector<int>> DP (s.size(),vector<int> (s.size(),-1));
  return palrec(DP,s,0,s.size()-1);
}

int palrec(vector<vector<int>>& DP,string& s, int i, int j){
  if (i>=j)
    return 0;
  if(DP[i][j]<0)
    if(s[i]==s[j])
      DP[i][j] = palrec(DP,s,i+1,j-1);
    else
      DP[i][j] = min(palrec(DP,s,i+1,j),palrec(DP,s,i,j-1))+1;
  return DP[i][j];
}
