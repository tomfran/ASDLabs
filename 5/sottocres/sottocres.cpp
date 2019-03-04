#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int sottocres();

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  out << sottocres();
  return 0;
