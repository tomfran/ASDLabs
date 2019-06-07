#include <string>
#include <iostream>

using namespace std;

void printPar(int n);
void printParRec(string s, int i, int open, int close, int &counter);

int main(int argc, char const *argv[]) {
    int n = 20;
    printPar(n);
    return 0;
}

void printPar(int n){
    string s = "";
    s.resize(2*n);
    int counter = 0;
    printParRec(s,0,n,0,counter);
}

void printParRec(string s, int i, int open, int close, int &counter){
    if(open+close == 0){
        printf("%5d. %s\n", counter, s.c_str());
        counter++;
    }
    else{
        if(open > 0){
            s[i] = '(';
            printParRec(s,i+1,open-1,close+1, counter);
        }
        if(close > 0){
            s[i] = ')';
            printParRec(s,i+1,open,close-1, counter);
        }
    }
}
