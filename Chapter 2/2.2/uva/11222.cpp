#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int numCases;

    cin >> numCases;
    for(int tc=1;tc<=numCases;tc++){
        long solved[3][1000] {};
        long unique[3][1000] {};
        bool hasDuplicates[3][1000] {};
        long numSolved[3] {};
        long numUnique[3] {};
        long maxUnique {0};
        vector<set<long>> uniqueVals {};

        //get data first
        for(int i=0;i<3;i++){
            cin >> numSolved[i];
            for(long j=0;j<numSolved[i];j++){
                cin >> solved[i][j];
            }
            set<long> temp {};
            uniqueVals.push_back(temp);
        }

        //check duplicates
        for(int p1=0;p1<3;p1++){
            for(int p2=p1+1;p2<3;p2++){
                for(long v1=0;v1<numSolved[p1];v1++){
                    for(long v2=0;v2<numSolved[p2];v2++){
                        if(solved[p1][v1] == solved[p2][v2]){
                            hasDuplicates[p1][v1] = true;
                            hasDuplicates[p2][v2] = true;
                            break;
                        }
                    }
                }
            }
        }

        //compute unique
        for(int p=0;p<3;p++){
            for(long v=0;v<numSolved[p];v++){
                if(!hasDuplicates[p][v]){
                    uniqueVals[p].emplace(solved[p][v]);
                }
            }
            numUnique[p] = uniqueVals[p].size();
            if(numUnique[p] > maxUnique){
                maxUnique = numUnique[p];
            }
        }

        cout << "Case #" << tc << ":\n";
        for(int p=0;p<3;p++){
            if(numUnique[p] == maxUnique){
                cout << p+1 << ' ' << numUnique[p];
                for(long v: uniqueVals[p]){
                    cout << ' ' << v;
                }
                cout << '\n';
            }
        }
    }
}