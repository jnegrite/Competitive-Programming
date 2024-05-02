#include<iostream>
#include<set>
using namespace std;

int values[12] {};
bool inIsland {};

int main(){
    int nCases;
    int tc;
    cin >> nCases;
    while(nCases--){
        cin >> tc;
        int nIslands {};
        int islandFrom {-1};
        bool islandMap[12][12] {};

        set<int> seenValues {};

        for(int i=0;i<12;i++){
            cin >> values[i];
            if(values[i] != 0){
                seenValues.emplace(values[i]);
            }
        }
        auto it {seenValues.begin()};
        do {
            //count islands
            inIsland = false;
            for(int i=0;i<12;i++){
                if(islandFrom == -1 && values[i] > 0){
                    islandFrom  = i;
                } else if (islandFrom != -1 && values[i] == 0){
                    islandMap[islandFrom][i-1] = true;
                    islandFrom = -1;
                }

                //remove if lowest
                if(values[i] == *it){
                    values[i] = 0;
                }
            }

            it++;
        } while(it!=seenValues.end());

        nIslands = 0;
        for(int i=0;i<12;i++){
            for(int j=i;j<12;j++){
                if(islandMap[i][j]){
                    ++nIslands;
                }
            }
        }
        cout << tc << ' ' << nIslands << '\n';
    }
}