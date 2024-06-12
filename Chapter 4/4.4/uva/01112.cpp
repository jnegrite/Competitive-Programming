#include<iostream>
#include<vector>
#include<tuple>
#include<queue>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;
    
    int nCells, exitCell, timer;
    int nConnections;
    vector<vector<pair<int,int>>> paths {};
    vector<int> dist {};

    while(nCases--){
        cin >> nCells >> exitCell >> timer >> nConnections;
        paths.assign(nCells+1,{});
        dist.assign(nCells+1,-1);

        //get paths
        int a, b, w;
        while(nConnections--){
            cin >> a >> b >> w;
            paths[b].emplace_back(a,w);
        }

        int cellsReached {};

        priority_queue<tuple<int,int>> q {};
        q.emplace(0,exitCell);

        while(!q.empty()){
            auto curr {q.top()};
            q.pop();

            int currCell {get<1>(curr)};
            int currDist {-get<0>(curr)};

            if(dist[currCell] != -1) continue;

            cellsReached++;
            dist[currCell] = currDist;

            for(auto nxt: paths[currCell]){
                int nxtCell {nxt.first};
                int nxtDist {currDist + nxt.second};

                if(dist[nxtCell] == -1 && nxtDist <= timer){
                    q.emplace(-nxtDist,nxtCell);
                }
            }
        }
        cout << cellsReached << '\n';

        if(nCases>0){
            cout << '\n';
        }
    }
}