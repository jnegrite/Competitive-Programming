#include <iostream>

using namespace std;

int main(){
    int testCases;
    cin >> testCases;

    int D, M, di;
    int currTotal{};

    while(testCases--){
        cin >> D >> M;
        
        int numAns {};
        currTotal = 0;

        for(int i=0;i<M;i++){
            cin >> di;
            if(di >= 13 && currTotal%7==0){
                numAns++;
            }
            currTotal+=di;
        }
        cout << numAns << '\n';
    }
}