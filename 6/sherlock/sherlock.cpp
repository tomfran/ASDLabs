#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
vector<int> parser(string a);
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

  for (int i = 0; i < nights.size(); i++) {
    for (int j = 0; j < nights[i].size(); j++) {
      std::cout << nights[i][j] << ' ';
    }
    std::cout <<'\n';
  }

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

int scherlockAux(vector<int>& s, int k, int i){
  vector<vector<int>> DP();
}
