#include<iostream>
#include<vector>

using namespace std;

const int INF {1<<30};
int nPoints, nEdges;
vector<int> dist {};
vector<vector<pair<int,int>>> paths {};

int main(){
    int nCases;
    cin >> nCases;

    while(nCases--){
        cin >> nPoints >> nEdges;
        paths.assign(nPoints,{});
        dist.assign(nPoints,INF);
        dist[0] = 0;

        //get data
        int a, b, w;
        while(nEdges--){
            cin >> a >> b >> w;
            paths[a].emplace_back(b,w);
        }

        int reps {0};
        for(reps=0;reps<nPoints;reps++){
            bool didUpdate {false};

            for(int i=0;i<nPoints;i++){
                for(auto nxt: paths[i]){
                    int nxtPoint {nxt.first};
                    int nxtDist {dist[i] + nxt.second};

                    if(nxtDist < dist[nxtPoint]){
                        didUpdate = true;
                        dist[nxtPoint] = nxtDist;
                    }

                }
            }

            if(!didUpdate){
                break;
            }
        }

        cout << ((reps == nPoints)?"possible\n":"not possible\n");
    }
}