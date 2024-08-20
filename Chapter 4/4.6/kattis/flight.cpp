#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int nCities;
vector<vector<int>> paths {};

//returns farthest point, diameter, midpoint
tuple<int,int,int> traverse(int pos, int blocker, bool getMid){
    vector<int> dist {};
    vector<int> parent {};

    dist.assign(nCities+1,-1);
    parent.assign(nCities+1,-1);

    queue<int> q {};
    dist[pos] = 0;
    q.push(pos);

    int curr {};
    while(!q.empty()){
        curr = q.front();
        q.pop();

        int nxtDist {dist[curr]+1};
        for(int nxt: paths[curr]){
            if(nxt == blocker) continue;
            if(dist[nxt] != -1) continue;

            dist[nxt] = nxtDist;
            parent[nxt] = curr;
            q.push(nxt);
        }
    }

    int hops {dist[curr] >> 1};
    int mid {curr};
    if(getMid){
        while(hops--){
            mid = parent[mid];
        }
    }
    
    return {curr, dist[curr], mid};
}

int main(){
    cin >> nCities;

    paths.assign(nCities+1,{});

    int a, b;
    for(int i=1;i<nCities;++i){
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }

    int bestDiam {nCities};
    pair<int,int> nodesDisconnect {-1,-1};
    pair<int,int> nodesConnect {-1,-1};

    for(int i=1;i<=nCities;++i){
        for(int j: paths[i]){
            if(i<j){
                auto temp1 {traverse(i,j,false)};
                auto v1 {traverse(get<0>(temp1),j,true)};

                auto temp2 {traverse(j,i,false)};
                auto v2 {traverse(get<0>(temp2),i,true)};
                
                int d1 {get<1>(v1)};
                int d2 {get<1>(v2)};
                
                int currDiam {
                    ((d1+1) >> 1) + 
                    ((d2+1) >> 1) + 1
                };

                currDiam = max(max(currDiam, d1),d2);

                if(currDiam < bestDiam){
                    bestDiam = currDiam;
                    nodesDisconnect = {i,j};
                    nodesConnect = {get<2>(v1), get<2>(v2)};
                }
            }
        }
    }
    cout << bestDiam << '\n';
    cout << nodesDisconnect.first << ' ' << nodesDisconnect.second << '\n';
    cout << nodesConnect.first << ' ' << nodesConnect.second << '\n';
}