#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int main(){
    int nSites, nRoads, nBanks, nStations;
    vector<vector<pair<int,int>>> paths {};
    vector<int> dist {};
    vector<bool> isBank {};
    while(cin >> nSites >> nRoads >> nBanks >> nStations){
        int nVisited {0};
        int maxDist {-1};
        paths.assign(nSites, {});
        dist.assign(nSites,-1);
        isBank.assign(nSites,false);

        int a, b, w;
        while(nRoads--){
            cin >> a >> b >> w;
            paths[a].emplace_back(b,w);
            paths[b].emplace_back(a,w);
        }

        for(int i=0;i<nBanks;i++){
            cin >> a;
            isBank[a] = true;
        }

        //prepare queue
        priority_queue<tuple<int,int>> q {};

        for(int i=0;i<nStations;i++){
            cin >> a;
            q.emplace(0,a);
        }

        //do dijkstra

        while(!q.empty()){
            auto curr {q.top()};
            int currDist {-get<0>(curr)};
            int currNode {get<1>(curr)};
            q.pop();

            if(dist[currNode] != -1) continue;

            dist[currNode] = currDist;

            //check if bank
            if(isBank[currNode]){
                maxDist = currDist;
                nVisited++;
            }

            //process outgoing nodes
            for(auto &nxt:paths[currNode]){
                int nxtNode {nxt.first};
                int nxtDist {currDist + nxt.second};

                if(dist[nxtNode] != -1) continue;
                q.emplace(-nxtDist,nxtNode);
            }
        }

        if(nVisited < nBanks){
            maxDist = -1;
        }

        vector<int> sites {};
        sites.reserve(nBanks);
        for(int i=0;i<nSites;i++){
            if(isBank[i] && dist[i] == maxDist){
                sites.push_back(i);
            }
        }

        cout << sites.size() << ' ';
        if(maxDist==-1){
            cout << '*';
        } else {
            cout << maxDist;
        }

        cout << '\n';
        cout << sites[0];
        for(int i=1;i<sites.size();i++){
            cout << ' ' << sites[i];
        }
        cout << '\n';
    }
}