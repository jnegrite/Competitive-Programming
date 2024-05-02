#include<iostream>
#include<vector>

using namespace std;

int main(){
    int nRoutes;
    cin >> nRoutes;
    for(int tc=1;tc<=nRoutes;tc++){
        int nStops {};
        int bestStart {};
        int bestEnd {};
        int currStart {};
        int currEnd {};
        int bestSum {};
        int currSum {};

        cin >> nStops;
        vector<long> niceness {};
        niceness.assign(nStops,0); 
        for(long stop=1;stop<nStops;++stop){
            cin >> niceness[stop];
        }
        bool inSequence {false};
        for(int stop=1;stop<nStops;stop++){
            
            if(!inSequence && niceness[stop] > 0){
                inSequence = true;
                currStart = stop;
            }

            currSum += niceness[stop];


            if(currSum > bestSum ||
                (currSum == bestSum && (stop-currStart > bestEnd-bestStart))){
                bestSum = currSum;
                bestStart = currStart;
                bestEnd = stop;
            }

            if(currSum < 0){
                currSum = 0;
                inSequence = false;
            }
        }

        if(bestSum==0){
            cout << "Route " << tc << " has no nice parts\n";
        } else {
            cout << "The nicest part of route " << tc << " is between stops " << bestStart << " and " << bestEnd+1 << '\n';
        }
    }
}