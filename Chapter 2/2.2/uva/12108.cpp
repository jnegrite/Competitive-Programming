#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int tc{0};
    int numStudents;
    int a, b, c;
    while(cin>>numStudents, numStudents > 0){
        int specs[10][3] {};
        long currTime{1};
        vector<queue<long>> awakeTimes;
        int numAsleep {numStudents};
        bool isAwake[10] {};
        vector<vector<int>> historical {};

        //get data
        for(int i=0;i<numStudents;i++){
            cin >> specs[i][0] >> specs[i][1] >> specs[i][2];
            queue<long> temp{};
            int from = 2 - specs[i][2];
            if(specs[i][2] > specs[i][0]){
                from += (specs[i][0] + specs[i][1]);
            }


            for(int j=0;j<specs[i][0];j++){
                if(from+j>0){
                    temp.emplace(from+j);
                    if(from + j==1){
                        isAwake[i] = true;
                        numAsleep--;
                    }
                }
            }
            awakeTimes.push_back(temp);
        }

        //simulation
        bool didRepeat{false};
        currTime = awakeTimes[0].front();
        for(int i=1;i<numStudents;i++){
            currTime = min(currTime,awakeTimes[i].front());
        }
        queue<int> keepAwake{};
        queue<int> goToSleep{};
        while(true){
            for(int i=0;i<numStudents;i++){
                if(currTime==awakeTimes[i].front()){
                    //make awake if sleeping
                    if(!isAwake[i]){
                        numAsleep--;
                        isAwake[i] = true;
                    }
                }
            }

            //evaluate if everyone is awake
            if(numAsleep==0){
                break;
            }

            //record tracking for repeating
            if(awakeTimes[0].size() == 1 && currTime == awakeTimes[0].front()){
                for(auto v: historical){
                    bool didMatch {true};
                    for(int i=0;didMatch && i<numStudents;i++){
                        if(v[i] != awakeTimes[i].front()-currTime){
                            didMatch = false;
                            break;
                        }
                    }

                    if(didMatch){
                        didRepeat = true;
                        break;
                    }
                }

                if(didRepeat){
                    break;
                } else {
                     vector<int> temp {};
                    for(int i=0;i<numStudents;i++){
                        temp.push_back(awakeTimes[i].front()-currTime);
                    }
                    historical.push_back(temp);
                }
            }

           

            //decision making for all that are due to sleep
            bool keepAwake {numStudents - numAsleep >= numAsleep};
            long nextCurr;
            for(int i=0;i<numStudents;i++){
                if(currTime==awakeTimes[i].front()){
                    awakeTimes[i].pop();
                    if(awakeTimes[i].empty()){
                        for(int j=1;j<=specs[i][0];j++){
                            awakeTimes[i].emplace(currTime + (keepAwake?0:specs[i][1]) + j);
                        }
                        if(!keepAwake){
                            numAsleep++;
                            isAwake[i] = false;
                        }
                    }
                }

                if(i==0){
                    nextCurr = awakeTimes[i].front();
                } else {
                    nextCurr = min(nextCurr,awakeTimes[i].front());
                }
            }
            currTime = nextCurr;
        }

        cout << "Case " << ++tc << ": ";
        if(didRepeat){
            cout << "-1\n";
        } else {
            cout << currTime << '\n';
        }
    }
}