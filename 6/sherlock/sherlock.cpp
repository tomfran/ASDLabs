#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int n,m,t;
  in >> n >> m >> t;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    in >> v[i];
  }
  

  return 0;
}
