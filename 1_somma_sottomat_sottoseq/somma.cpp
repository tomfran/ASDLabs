#include <fstream>

using namespace std;

int main(){
  ifstream in("input.txt");
  int n,m;
  ofstream out("output.txt");
  in >> n >> m;
  out << n+m;
  return 0;
}
