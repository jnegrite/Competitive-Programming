#include<iostream>
#include<string>
#include<bitset>

using namespace std;

int main(){
    int nCases;
    cin >> nCases >> ws;
    while(nCases--){
        string s;
        int nTrees {0};
        bitset<26> hasEdge {};
        int nAcorns {0};
        while(getline(cin,s),s.at(0) != '*'){
            for(int i=1;i<=3;i+=2){
                int pos = s.at(i) - 'A';
                hasEdge.set(pos);
            }
            nTrees--;
        }
        getline(cin,s);
        for(int i=0;i<s.length();i+=2){
            if(!hasEdge.test(s.at(i)-'A')){
                nAcorns++;
            }
        }
        nTrees += (s.length()+1)/2;
        cout << "There are " << nTrees - nAcorns << " tree(s) and " << nAcorns << " acorn(s).\n";
    }
}