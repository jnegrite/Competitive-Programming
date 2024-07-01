#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int nPoints;
int a, b, w;
const int INF {~(1<<31)};
vector<int> dist {};
vector<int> busyness {};
vector<vector<pair<int,int>>> paths {};
vector<bool> valUpdated {};

int main(){
    int tc {};
    while(cin >> nPoints){
        dist.clear();
        dist.assign(nPoints+1,INF);
        dist[1] = 0;
        
        busyness.clear();
        busyness.assign(nPoints+1,0);
        
        paths.clear();
        paths.assign(nPoints+1,{});

        for(int i=1;i<=nPoints;i++){
            cin >> busyness[i];
        }

        int nEdges;
        cin >> nEdges;
        while(nEdges--){
            cin >> a >> b;
            w = (busyness[b] - busyness[a]);
            w = w*w*w;
            paths[a].emplace_back(b,w);
        }

        
        bool didUpdate {true};
        for(int reps=0;reps<nPoints;reps++){
            didUpdate = false;
            for(int i=1;i<=nPoints;i++){
                if(dist[i] == INF) continue;

                for(auto nxt: paths[i]){
                    int nxtPoint {nxt.first};
                    int nxtDist {dist[i] + nxt.second};

                    if(nxtDist < dist[nxtPoint]){
                        didUpdate = true;
                        dist[nxtPoint] = nxtDist;
                    }
                }
            }

            if(!didUpdate) break;
        }

        valUpdated.assign(nPoints+1,false);
        didUpdate = true;        
        while(didUpdate){
            didUpdate = false;
            for(int i=1;i<=nPoints;i++){
                for(auto nxt: paths[i]){
                    int nxtPoint {nxt.first};
                    int nxtDist {dist[i] + nxt.second};

                    if(nxtDist < dist[nxtPoint]){
                        dist[nxtPoint] = nxtDist;
                        
                        if(!valUpdated[nxtPoint]){
                            didUpdate = true;
                            valUpdated[nxtPoint] = true;
                        }
                    }
                }
            }
        }
        
        int nQueries;
        cin >> nQueries;

        cout << "Set #" << ++tc << '\n';
        while(nQueries--){
            cin >> a;
            
            if(valUpdated[a] || dist[a] < 3 || dist[a] == INF){
                cout << "?\n";
            } else {
                cout << dist[a] << '\n';
            }
        
        }
    }
}