#include <fstream>
#include <vector>

using namespace std;

int zaino(int c, int n, vector<vector<int>> values);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n,c;
  in >> c >> n;

  vector<vector<int>> values(n, vector<int>(2));

  for (int i = 0; i < n; i++)
    in >> values[i][0] >> values[i][1];

  out << zaino(c,n,values);
  return 0;
}

int zaino(int c, int n, vector<vector<int>> values){
  vector<int> pred(c+1,0);
  vector<int> pred2(c+1,0);
  for (int i = 1; i < n+1; i++) {
    for (int j = 1; j < pred.size(); j++) {
      if(values[i-1][0]<=j){
        pred[j] = max(pred2[j-values[i-1][0]] + values[i-1][1],
                       pred2[j]);
      }else
        pred[j] = pred2[j];
    }
    pred2 = pred;
  }
  return pred[c];
}
