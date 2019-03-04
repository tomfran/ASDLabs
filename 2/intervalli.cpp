#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void mergeSort(int* a, int s, int e);
void insertionSort(int* a, int n);
void merge(int* a, int s, int e, int m, int* b);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int n;
  in >> n;

  int* start = new int[n];
  int* end = new int[n];

  for(int i=0; i<n; i++){
    in >> start[i];
    in >> end[i];
  }

  mergeSort(start,0,n);
  mergeSort(end,0,n);
  
  int max,temp,startMax,endMax;
  max = temp = startMax = endMax = 0;
  
  for(int i=1;i<n;i++){
    if(start[i]>end[i-1]){
      temp = start[i]-end[i-1];
      if(temp>max){
	max = temp;
	startMax = end[i-1];
	endMax = start[i];
      }
    }
  }
  if(max>0)
    out << startMax << " " << endMax;
  else
    out << startMax;
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
  j = e-1;
  for(int h = m-1; h>=i; h--){
    a[j] = a[h];
    j--;
  }
  for(int j = s; j<k; j++){
    a[j] = b[j];
  } 
}
