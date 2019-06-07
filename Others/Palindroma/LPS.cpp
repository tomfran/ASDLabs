#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LPS(string &s);
int LPCS(string &s);
int LPSrec(string &s, vector<vector<int>> &DP, int i, int j);

int main(int argc, char const *argv[]) {
    string s = "turboventilator";
    cout << "Longest palindromic subsequence in " << s << " : "
         << LPS(s) << endl;
    cout << "Longest palindromic sequence in " << s << "    : "
          << LPCS(s) << endl;
    return 0;
}

int LPS(string &s){
    vector<vector<int>> DP(s.size(), vector<int>(s.size(), -1));
    for(int i = 0; i < DP.size(); i++)
        DP[i][i] = 1;
    return LPSrec(s,DP,0,s.size()-1);
}

int LPSrec(string &s, vector<vector<int>> &DP, int i, int j){
    if(i <= j){
        if(DP[i][j] == -1){
            if(s[i] == s[j])
                DP[i][j] = 2 + LPSrec(s,DP,i+1,j-1);
            else
                DP[i][j] = max(LPSrec(s,DP,i+1,j), LPSrec(s,DP,i,j-1));
        }
        return DP[i][j];
    }
    return 0;
}

int LPCS(string &s){
    int longest = 1;
    int actual = 1;
    int start, end;
    for(int i = 0; i < s.size(); i++){
        start = i-1;
        end = i+1;
        actual = 1;
        while(start >= 0 && end < s.size()){
            if(s[start] == s[end]){
                actual += 2;
                start --;
                end ++;
                longest = max(longest, actual);
            }
            else
                start = -1;
        }
    }
    return longest;
}
