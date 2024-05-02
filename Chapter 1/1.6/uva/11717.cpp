#include<iostream>

using namespace std;

using NumType = long long int;

int main(){
    int numCases {};
    cin >> numCases;

    for(int tc=1;tc<=numCases;tc++){
        int n;
        NumType ix, k;
        
        int numIdle {}, numIgnored {};
        cin >> n >> ix >> k;

        NumType nxtIdle{ix}, nxtActive{-1};
        NumType curr;
        for(int i=0;i<n;i++){
            cin >> curr;
            
            if(nxtActive <= curr){
                //not on activation period
                if(curr < nxtIdle){
                    //ok path. sent while active
                    nxtIdle = curr + ix;
                } else {
                    //next instruction is after idle period
                    numIdle++;
                    nxtActive = curr + k;
                    nxtIdle = nxtActive + ix;
                }
            } else {
                numIgnored++;
            }
        }

        cout << "Case " << tc << ": " << numIdle << ' ' << numIgnored << '\n';
    }
}