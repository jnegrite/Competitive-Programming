#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> energy {};
vector<bool> visited {};
vector<vector<int>> paths {};
vector<int> maxEnergy {};
vector<bool> inLoop {};

void processLoop(int pos){
    if(inLoop[pos]) return;

    inLoop[pos] = true;
    visited[pos] = true;
    for(int nxt:paths[pos]){
        processLoop(nxt);
    }
}

int main(){
    int nPoints;
    while(cin >> nPoints, nPoints != -1){
        ++nPoints;
        
        energy.assign(nPoints, 0);
        visited.assign(nPoints, false);
        paths.assign(nPoints, {});
        maxEnergy.assign(nPoints, -1);
        inLoop.assign(nPoints, false);

        for(int i=1;i<nPoints;i++){
            int nNeighbors;
            cin >> energy[i] >> nNeighbors;
            paths[i].assign(nNeighbors, 0);
            for(int j=0;j<nNeighbors;j++){
                cin >> paths[i][j];
            }
        }

        maxEnergy[1] = 100;
        visited[1] = true;

        nPoints--;
        bool didUpdate {true};
        queue<int> loopSeed {};
        for(int reps=1;didUpdate && reps<=nPoints;reps++){
            didUpdate = false;
            for(int i=1;i<=nPoints;i++){
                if(!visited[i] || maxEnergy[i] == 0) continue;

                for(int nxt: paths[i]){
                    int nxtEnergy {maxEnergy[i] + energy[nxt]};

                    if(nxtEnergy > maxEnergy[nxt]){
                        didUpdate = true;
                        maxEnergy[nxt] = nxtEnergy;
                        visited[nxt] = true;

                        if(reps == nPoints){
                            processLoop(nxt);
                        }
                    }
                }
            }
        }

        if(visited[nPoints]){
            cout << "winnable\n";
        } else {
            cout << "hopeless\n";
        }
    }
}