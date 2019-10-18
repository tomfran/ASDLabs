#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LP(string &s);
int LPrec(string &s, vector<vector<vector<int>>> &DP, int i, int j, bool found);

int main(int argc, char const *argv[]) {
    string s = "))()()((())()";
    cout << LP(s) << endl;
    return 0;
}

int LP(string &s){
    vector<vector<vector<int>>> DP(s.size(), vector<vector<int>>(s.size(), vector<int>(2,-1)));
    for(auto &r : DP){
        for(auto &e : r){
            for(auto &w : e)
                w = -1;
        }
    }
    LPrec(s,DP,0,s.size()-1, false);
    for(auto r : DP){
        for(auto e : r){
            printf("%2d ", e);
        }
        printf("\n");
    }
    return 0;
}


int LPrec(string &s, vector<vector<vector<int>>> &DP, int i, int j, bool found){
    if(i>=j)
        return 0;
    if(DP[i][j][found] < 0){
        if(!found && s[i] == '(' && s[j] == ')')
            DP[i][j][found] = 2 + max(LPrec(s,DP,i+1,j-1, true), LPrec(s,DP,i+1,j-1, false));
        else if (found && s[i] == ')' && s[j] == '(')
            DP[i][j][found] = 2 + LPrec(s,DP,i+1,j-1, false);
        else
            DP[i][j][found] = max(LPrec(s,DP,i+1,j, found), LPrec(s,DP,i,j-1, found));
    }
    return DP[i][j][found];
}
