#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    long numCases;
    string s;
    getline(cin, s);
    numCases = stol(s);

    vector<pair<char,int>> margaritaCounts {
        {'M',1},
        {'A',3},
        {'R',2},
        {'G',1},
        {'I',1},
        {'T',1}
    };

    while(numCases--){
        getline(cin,s);
        int counts[26] {};
        for(char ch:s){
            counts[ch-'A']++;
        }

        int minServe {600};
        for(auto pr:margaritaCounts){
            minServe = min(minServe,counts[pr.first - 'A']/pr.second);
        }
        cout << minServe << '\n';
    }
}