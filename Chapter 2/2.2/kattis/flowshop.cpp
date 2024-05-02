#include<iostream>

using namespace std;

int main(){
    int nSwathers, nStages;
    cin >> nSwathers >> nStages;

    auto costs = new int[nSwathers][1000];

    //get data
    for(int i=0;i<nSwathers;i++){
        for(int j=0;j<nStages;j++){
            cin >> costs[i][j];
        }
    }

    //adjust data
    for(int j=1;j<nStages;j++){
        costs[0][j] += costs[0][j-1];
    }

    for(int i=1;i<nSwathers;i++){
        costs[i][0] += costs[i-1][0];
    }

    for(int i=1;i<nSwathers;i++){
        for(int j=1;j<nStages;j++){
            costs[i][j] += max(costs[i-1][j],costs[i][j-1]);
        }
    }

    //print out results
    cout << costs[0][nStages-1];
    for(int j=1;j<nSwathers;j++){
        cout << ' ' << costs[j][nStages-1];
    }
    cout << '\n';
}