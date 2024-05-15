#include<cstdio>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>

#define INF 1000000000000001

using namespace std;


using ll = long long;
using ii = pair<int,ll>;

int nStations;
vector<vector<ii>> paths {};
vector<set<int>> parents {};
vector<ll> currDist;
vector<vector<int>> ssPaths {};

//for articulation points
vector<int> p {};
vector<int> dfs_low {};
vector<int> dfs_num {};
int ctr {0};

set<int> artPoints {};

int from, to;

struct cmpNodes {
    bool operator()(const ii &a, const ii &b) const {
        if(a.second != b.second){
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

vector<bool> visited {};

void traceBack(int pos){

    visited[pos] = true;
    for(auto it{parents[pos].begin()};it!=parents[pos].end();++it){
        int nxt {*it};
        ssPaths[pos].push_back(nxt);
        ssPaths[nxt].push_back(pos);

        if(!visited[nxt]){
            traceBack(nxt);
        }
    }
}

void getArtPoints(int pos){

    dfs_num[pos] = dfs_low[pos] = ctr++;
    bool isArt {false};

    for(int &nxt:ssPaths[pos]){

        if(dfs_num[nxt] == -1){
            p[nxt] = pos;
            getArtPoints(nxt);

            if(dfs_low[nxt] >= dfs_num[pos]){
                isArt=true;
            }

            dfs_low[pos]=min(dfs_low[pos],dfs_low[nxt]);
        } else if(p[pos] != nxt){
            dfs_low[pos] = min(dfs_low[pos],dfs_num[nxt]);
        }
    }

    if(isArt){
        artPoints.emplace(pos);
    }
}


int main(){
    int nConnections;
    scanf("%d %d\n",&nStations,&nConnections);
    paths.assign(nStations,{});
    currDist.assign(nStations,INF);
    parents.assign(nStations,{});
    int a, b;
    ll w;
    while(nConnections--){
        scanf("%d %d %Ld\n",&a,&b,&w);
        paths[a].push_back({b,w});
        paths[b].push_back({a,w});
    }

    scanf("%d %d\n",&from,&to);
    priority_queue<ii,vector<ii>,cmpNodes> q {};
    q.push({from,0LL});
    currDist[from] = 0LL;

    if(from == to){
        printf("%d\n",from);
        return 0;
    }

    while(!q.empty()){
        auto curr {q.top()};
        q.pop();

        int node {curr.first};
        ll dist {curr.second};

        if(dist > currDist[node]){
            continue;
        }

        if(dist > currDist[to]){
            break;
        }
        
        //propagate
        for(ii &nxt: paths[node]){
            //check if this will improve the current distance
            int &nxtNode {nxt.first};
            ll &nxtDist {nxt.second};
            ll tempDist {dist + nxtDist};

            if(tempDist < currDist[nxtNode]){
                currDist[nxtNode] = tempDist;
                parents[nxtNode].clear();
                parents[nxtNode].emplace(node);
                q.push({nxtNode,tempDist});
            } else if (tempDist == currDist[nxtNode]){
                parents[nxtNode].emplace(node);
            }
        }
    }

    //create new tree for dijkstra
    ssPaths.assign(nStations, {});
    visited.assign(nStations,false);
    traceBack(to);
    
    //setup articulation points
    dfs_num.assign(nStations,-1);
    dfs_low.assign(nStations,0);
    p.assign(nStations,-1);

    getArtPoints(from);
    artPoints.emplace(from);
    artPoints.emplace(to);

    vector<ii> orderedArtPoints {};

    auto it{artPoints.begin()};
    while(it!=artPoints.end()){
        orderedArtPoints.push_back({*it,currDist[*it]});
        it++;
    }

    sort(orderedArtPoints.begin(), orderedArtPoints.end(),cmpNodes());
    for(int i=orderedArtPoints.size()-1;i>0;i--){
        printf("%d ",orderedArtPoints[i].first);
    }
    printf("%d\n",orderedArtPoints[0].first);
}