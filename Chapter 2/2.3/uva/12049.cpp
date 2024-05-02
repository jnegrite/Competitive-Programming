#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    int numCases;
    long nA, nB, curr;
    cin >> numCases;

    while(numCases--){
        cin >> nA >> nB;
        unordered_multiset<long> valuesA {};
        unordered_multiset<long> valuesB {};
        long numMoves {};

        //place A
        for(long i=0;i<nA;i++){
            cin >> curr;
            valuesA.emplace(curr);
        }

        for(long i=0;i<nB;i++){
            cin >> curr;
            auto au = valuesA.find(curr);
            if(au != valuesA.end()){
                valuesA.erase(au);
            } else {
                numMoves++;
            }
        }
        numMoves += valuesA.size();
        cout << numMoves << '\n';
    }
}