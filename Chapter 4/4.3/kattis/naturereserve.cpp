#include<cstdio>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

vector<vector<pair<int,int>>> paths {};
vector<int> sourceStations {};
priority_queue<tuple<int,int>> q {};
vector<bool> visited {};
int nStations;
long long progSize;
long long totalCost;
int nProcessed;

//cost, destination, currJumps
void process(int cost, int pos){
    visited[pos] = true;
    totalCost -= cost;
    ++nProcessed;
    
    //printf("Added %d for %d\n",pos,cost);
    for(auto &nxt: paths[pos]){
        int nxtPos {nxt.first};
        int nxtWeight {nxt.second};

        if(visited[nxtPos]){
            continue;
        }

        q.emplace(nxtWeight,nxtPos);
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    while(nCases--){
        int nConnections;
        int nInit;
        scanf("%d %d %lld %d\n",&nStations,&nConnections,&progSize,&nInit);
        ++nStations;
        totalCost = 0;

        visited.assign(nStations,false);
        paths.assign(nStations,{});
        while(!q.empty()){
            q.pop();
        }

        sourceStations.assign(nInit,0);
        for(int i=0;i<nInit;++i){
            scanf("%d",&sourceStations[i]);
        }
        
        int a, b, w;
        while(nConnections--){
            scanf("%d %d %d\n",&a,&b,&w);
            w*=-1;
            paths[a].emplace_back(b,w);
            paths[b].emplace_back(a,w);
        }

        for(int station:sourceStations){
            process(0,station);
        }

        //do processing
        while(!q.empty()){
            auto curr {q.top()};
            q.pop();

            int nxtPos {get<1>(curr)};
            if(visited[nxtPos]) continue;

            process(get<0>(curr),nxtPos);
        }
        printf("%lld\n",totalCost + (nStations-nInit-1)*progSize);
    }
}