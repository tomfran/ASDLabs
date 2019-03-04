#include <fstream>
#include <iostream>

using namespace std;

int maxSeq(int* v, int d);
void sumVett(int* a, int* b, int d);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int maxSum, currentSum, rows, cols;
  in >> rows;
  in >> cols;

  currentSum = maxSum = 0;

  int** matrix = new int*[rows];
  for(int i=0; i<rows;i++){
    matrix[i] = new int[cols];
    for(int j=0; j<cols;j++){
      in >> matrix[i][j];
      }
  }

  int* temp = new int[cols];
  for(int i=0; i<rows; i++){
    for(int k=0; k<cols; k++)
      temp[k] = matrix[i][k];

    currentSum = maxSeq(temp,cols);
    maxSum = (currentSum>maxSum)? currentSum : maxSum;
    for(int j=i+1; j<rows; j++){
      sumVett(temp,matrix[j],cols);
      currentSum = maxSeq(temp,cols);
      maxSum = (currentSum>maxSum)? currentSum : maxSum;
    }
  }
  
  out << maxSum;
  return 0;
}

int maxSeq(int* v, int d){
  int maxSum, currentSum;
  maxSum = currentSum = 0;
  for(int i=0; i<d; i++){
    currentSum += v[i];
    if(currentSum > maxSum)
      maxSum = currentSum;
    if(currentSum <= 0)
      currentSum = 0;
  }
  return maxSum;
}

void sumVett(int* a, int* b, int d){
  for(int i=0;i<d;i++){
    a[i] += b[i];
  }
}
