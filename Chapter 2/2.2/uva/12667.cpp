#include<iostream>

using namespace std;

int main(){
    int numProblems, numTeams, numSubmissions;

    cin >> numProblems >> numTeams >> numSubmissions;

    auto teamSolved = new bool[numTeams][12];
    auto lastSolve = new int[12][2];
    bool isSolved[12] {};

    int time, team, probId;
    char prob;
    string decision;
    while(numSubmissions--){
        cin >> time >> team >> prob >> decision;
        probId = prob - 'A';
        if((decision == "No") || (teamSolved[team][probId]==true)){
            continue;
        }

        teamSolved[team][probId] = true;
        lastSolve[probId][0] = time;
        lastSolve[probId][1] = team;
        isSolved[probId] = true;
    }

    for(int i=0;i<numProblems;i++){
        printf("%c",'A' + i);
        if(isSolved[i]){
            printf(" %d %d\n",lastSolve[i][0],lastSolve[i][1]);
        } else {
            printf(" - -\n");
        }
    }
}