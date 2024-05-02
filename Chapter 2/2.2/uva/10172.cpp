#include<iostream>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

int main(){
    int numCases;
    int nStations;
    int capStack;
    int capQueue;
    long undelivered;
    int currStation;
    int curr;
    cin >> numCases;

    while(numCases--){
        cin >> nStations >> capStack >> capQueue;

        vector<queue<int>> platformB {};
        queue<int> temp {};
        long totalTime {0};

        platformB.reserve(nStations+1);
        platformB.push_back(temp);

        

        //get current contents of platformB
        for(int i=1;i<=nStations;i++){
            int qi;
            cin >> qi;
            undelivered += qi;
            queue<int> temp {};
            for(int j=0;j<qi;j++){
                cin >> curr;
                temp.emplace(curr);
            }
            platformB.push_back(temp);
        }

        stack<int> carrier {};
        currStation = 1;

        while(undelivered > 0){
            
            //unloading procedure
            while(!carrier.empty() && (carrier.top() == currStation || platformB[currStation].size() < capQueue)){
                if(carrier.top() == currStation){
                    undelivered--;
                } else {
                    platformB[currStation].emplace(carrier.top());
                }
                carrier.pop();
                totalTime++;
            }

            if(undelivered == 0){
                break;
            }

            //loading procedure
            while(carrier.size() < capStack && !platformB[currStation].empty()){
                carrier.emplace(platformB[currStation].front());
                platformB[currStation].pop();
                totalTime++;
            }

            //move to next 
            if(currStation == nStations){
                currStation = 1;
            } else {
                currStation++;
            }
            totalTime+=2;
        }

        cout << totalTime << '\n';
    }
}