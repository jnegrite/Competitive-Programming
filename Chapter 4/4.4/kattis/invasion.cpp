#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int nCities, nRoads, nBases, minSafe;
vector<vector<pair<int,int>>> paths {};
vector<bool> isSafe {};
vector<int> dist {};
vector<int> maxProp {};

int nSafe {};
int main(){
    while(true){
        cin >> nCities >> nRoads >> nBases >> minSafe;
        
        if(nCities==0 && nRoads==0 && nBases==0 && minSafe==0) break;
        nSafe = nCities;

        paths.assign(nCities+1,{});
        isSafe.assign(nCities+1,true);
        maxProp.assign(nCities+1,-1);

        int a, b, w;
        while(nRoads--){
            cin >> a >> b >> w;
            paths[a].emplace_back(b,w);
            paths[b].emplace_back(a,w);
        }

        //simulate bases
        while(nBases--){
            cin >> a;

            priority_queue<tuple<int,int>> q {};
            q.emplace(0,a);
            dist.assign(nCities+1,-1);

            while(!q.empty() && nSafe > 0){
                int currDist {-get<0>(q.top())};
                int currNode {get<1>(q.top())};
                q.pop();

                if(dist[currNode] != -1) continue;

                dist[currNode] = currDist;

                if(isSafe[currNode]) {
                    nSafe--;
                    isSafe[currNode] = false;
                }

                int currProp {minSafe - currDist};
                if(currProp <= maxProp[currNode]){
                    continue;
                }

                maxProp[currNode] = currProp;

                for(auto nxt: paths[currNode]){
                    int nxtNode {nxt.first};
                    int nxtDist {currDist + nxt.second};

                    if(dist[nxtNode]!=-1 || nxtDist >= minSafe){
                        continue;
                    }

                    q.emplace(-nxtDist,nxtNode);
                }
            }
            cout << nSafe << '\n';
        }
        cout << '\n';
    }
}