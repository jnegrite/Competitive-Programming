#include<iostream>
#include<vector>

#define INF 1000000000

using namespace std;

int nPoints, nEdges, nQueries, sourceNode;
vector<bool> visited {};
vector<vector<pair<int,int>>> paths {};
vector<int> dist {};
vector<bool> inLoop {};

void processLoop(int pos){
    if(inLoop[pos]) return;

    inLoop[pos] = true;
    visited[pos] = true;

    for(auto nxt: paths[pos]){
        processLoop(nxt.first);
    }    
}

int main(){
    while(true){
        cin >> nPoints >> nEdges >> nQueries >> sourceNode;
        if(nPoints==0 && nEdges==0 && nQueries==0 && sourceNode==0){
            break;
        }

        visited.assign(nPoints,false);
        paths.assign(nPoints,{});
        dist.assign(nPoints, INF);
        inLoop.assign(nPoints,false);

        int a, b, w;
        while(nEdges--){
            cin >> a >> b >> w;
            paths[a].emplace_back(b,w);
        }

        dist[sourceNode] = 0;
        visited[sourceNode] = true;
        bool didUpdate {true};
        for(int reps=1;didUpdate && reps<=nPoints;reps++){
            didUpdate = false;
            for(int i=0;i<nPoints;i++){
                if(!visited[i]) continue;

                for(auto nxt: paths[i]){
                    int nxtNode {nxt.first};
                    int nxtDist {dist[i] + nxt.second};
                
                    if(nxtDist < dist[nxtNode]){
                        didUpdate = true;
                        dist[nxtNode] = nxtDist;
                        visited[nxtNode] = true;

                        if(reps==nPoints){
                            processLoop(nxtNode);
                        }
                    }
                }
            }
        }
    
        while(nQueries--){
            cin >> a;

            if(!visited[a]) {
                cout << "Impossible\n";
            } else if(inLoop[a]){
                cout << "-Infinity\n";
            } else {
                cout << dist[a] << '\n';
            }
        }
    }
}