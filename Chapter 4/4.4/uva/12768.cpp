#include<iostream>
#include<vector>

#define negINF -1000000000

using namespace std;

int nPoints, nEdges;
vector<vector<pair<int,int>>> paths {};
vector<int> dist {};

int main(){
    while(cin >> nPoints >> nEdges, nPoints!=0 || nEdges!=0){
        dist.assign(nPoints+1,negINF);
        dist[1] = 0;
        paths.assign(nPoints+1,{});

        int a, b, w;
        while(nEdges--){
            cin >> a >> b >> w;
            paths[a].emplace_back(b,w);
        }

        int maxProc {0};
        int nReps {0};
        for(nReps=0;nReps<nPoints;nReps++){
            bool didUpdate{false};

            for(int i=1;i<=nPoints;i++){
                if(dist[i] == negINF) continue;

                for(auto nxt: paths[i]){
                    int nxtPoint {nxt.first};
                    int nxtDist {dist[i] + nxt.second};

                    if(nxtDist > dist[nxtPoint]){
                        didUpdate = true;
                        dist[nxtPoint] = nxtDist;
                        maxProc = max(maxProc,nxtDist);
                    }
                }
            }
            if(!didUpdate) break;
        }

        if(nReps == nPoints){
            cout << "Unlimited!\n";
        } else {
            cout << maxProc << '\n';
        }
    }
}