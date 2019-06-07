#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int lcs(string s, string t);

int main(int argc, char const *argv[]) {
    if(argc>=3)
        std::cout << "Longest common subsequence btw " << argv[1] << " and " << argv[2] << ": " << lcs(argv[1], argv[2]) << endl;
    else
        std::cout << "Need two strigns\n ";
    return 0;
}

int lcs(string s, string t){
    string ret = "";
    vector<vector<int>> DP (s.size()+1,vector<int> (t.size()+1,0));
    for(int i = 1; i<DP.size(); i++){
        for (int j = 1; j < DP[0].size(); j++) {
            if(s[i-1] == t[j-1]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }
    return DP[s.size()-1][t.size()-1];
}
