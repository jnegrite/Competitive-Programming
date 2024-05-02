#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector<pair<long,long>> alignmentPoints {};


long nPrograms {};
long nAlignments {};
long bestOrder[8] {};
long progLengths[8] {};
long minMiss[6] {};
bool missUsed[6] {};
long currEnd {};
long totalLength {};

bool isBetter(long *bestVal, const long *newVal) {
    for(long i=1;i<=5;i++){
        if(!missUsed[i]){
            continue;
        }
        if(i==4 || (*(bestVal+i) != *(newVal+i))){
            return (*(bestVal+i) > *(newVal+i));
        }
    }
    return false;
}

int main(){
    long time, prio;

    long tc{};
    while(cin >> nPrograms,nPrograms != 0){
        totalLength = 0;

        //get programs
        for(long i=0;i<nPrograms;i++){
            cin >> progLengths[i];
            totalLength += progLengths[i];
        }

        //reset alignments
        alignmentPoints.clear();
        for(long i=0;i<=5;i++){
            minMiss[i] = 1000000000;
            missUsed[i] = false;
        }
        
        //get alignment points
        cin >> nAlignments;
        for(long i=0;i<nAlignments;i++){
            cin >> prio >> time;
            missUsed[prio] = true;
            alignmentPoints.push_back(pair<long,long>{prio,time});
        }


        sort(progLengths,progLengths+nPrograms);
        do {
            set<long> breakPoints {0};
            //initialize the breakpoints
            long currEnd {0};
            for(long i=0;i<nPrograms;i++){
                currEnd += progLengths[i];
                breakPoints.emplace(currEnd);
            }

            //compute for each alignment Point
            long currMiss[6] {};

            for(auto pr:alignmentPoints){
                long missPoint {totalLength};
                auto it {breakPoints.lower_bound(pr.second)};

                if(it!=breakPoints.end()){
                    missPoint = min(missPoint,abs(*it - pr.second));
                }

                if(it!=breakPoints.begin()){
                    --it;
                    missPoint = min(missPoint,abs(*it - pr.second));
                }

                currMiss[pr.first] += missPoint;
            }

            if(isBetter(minMiss,currMiss)){
                copy(currMiss,currMiss+6,minMiss);
                copy(progLengths,progLengths+nPrograms,bestOrder);
            }
        } while(next_permutation(progLengths,progLengths+nPrograms));

        long totalMiss {};
        for(long i=1;i<=5;i++){
            if(missUsed[i]){
                totalMiss+=minMiss[i];
            }
        }

        cout << "Data set " << ++tc << endl;
        cout << "  Order:";
        for(long i=0;i<nPrograms;i++){
            cout << ' ' << bestOrder[i];
        }
        cout << endl;

        cout << "  Error: " << totalMiss << endl;
    }   
}