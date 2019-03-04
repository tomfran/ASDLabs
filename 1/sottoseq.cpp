#include <fstream>

using namespace std;

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int size, n, maxSum, currentSum;
  in >> size;
  maxSum = currentSum = 0;
  for(int i = 0; i < size; i++){
    in >> n;
    currentSum += n;
    if(currentSum > maxSum)
      maxSum = currentSum;
    if(currentSum <= 0)
      currentSum = 0;
  }
  out << maxSum;
  return 0;
}
