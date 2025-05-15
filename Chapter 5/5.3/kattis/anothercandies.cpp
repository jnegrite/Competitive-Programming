#include<iostream>

using namespace std;

using llu = long long unsigned;

int main(){
    llu curr {};

    int nCases;
    cin >> nCases;

    while(nCases--){
        llu nChildren {};
        llu currTotal {};

        cin >> nChildren;

        for(llu i=0; i<nChildren; ++i){
            cin >> curr;
            curr %= nChildren;
            
            currTotal += curr;
            currTotal %= nChildren;
        }

        cout << (currTotal == 0 ? "YES" : "NO") << '\n';
    }
}