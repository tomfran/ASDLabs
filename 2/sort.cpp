#include <fstream>
#include <iostream>

using namespace std;

void mergeSort(int* a, int s, int e);
void insertionSort(int* a, int n);
void merge(int* a, int s, int e, int m, int* b);
void print(int* a, int s, int e);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int n;
  in >> n;

  int* a = new int[n];
  
  for(int i=0; i<n;i++){
    in >> a[i];
  }
  
  mergeSort(a,0,n);

  for(int i=0; i<n;i++)
    out << a[i] << " ";
  
  return 0;
}

void insertionSort(int* a, int s, int e){
  int j;
  for(int i=s+1; i<e; i++){
    int temp = a[i];
    j = i;
    while((j>s) && (a[j-1] > temp)){
      a[j] = a[j-1];
      j--;
    }
    a[j] = temp;
  }
}

void mergeSort(int* a, int s, int e){
  if(e-s<3){
    insertionSort(a,s,e);
  }else{
    int m = (s+e)/2;
    mergeSort(a,s,m);
    mergeSort(a,m,e);
    int* b = new int[e];
    merge(a,s,e,m,b);
    delete[] b ;
  }

}

void merge(int* a, int s, int e, int m, int* b){
  int i,k,j;
  i = k = s;
  j = m;
  //cout << "A prima: ";
  //  print(a,s,e);
  
  while(i<m && j<e){
    if(a[i]<=a[j]){
      b[k] = a[i];
      i++;
    }else{
      b[k] = a[j];
      j++;
    }
    k++;
  }
  //cout << "B: ";
  //print(b,s,k);
  j = e-1;
  for(int h = m-1; h>=i; h--){
    a[j] = a[h];
    j--;
  }
  //cout << "A: ";
  //print(a,s,e);  
  for(int j = s; j<k; j++){
    a[j] = b[j];
  }
  //cout << "A: ";
  //print(a,s,e);
  
}

void print(int* a, int s, int e){
  for(int i = s;i<e;i++){
    cout << a[i] << " ";
  }
  cout << endl;
}
