#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define INF 10000000

using namespace std;

vector<vector<int>> paths {}; //structure of pair is weight and counts 
vector<int> dist {};
vector<vector<int>> parents {};
vector<bool> visited {};
vector<bool> included {};

class PathDef{
private:
    int id {};
    int n1 {};
    int n2 {};
    int l {};

public:
    PathDef(int _id, int a, int b, int _l){
        id = _id;
        n1 = a;
        n2 = b;
        l = _l;
    }

    pair<int,int> traverse(int a, int w){
        int code {a==n1?n2:n1};
        if((dist[code] == -1) || (dist[code] == dist[a] + w)){
            return {dist[a] + w,code};
        } else {
            return {-1,0};
        }
    }

    int getOther(int a){
        return a==n1?n2:n1;
    }

    int getLength(){
        return l;
    }
};

vector<PathDef> pathDefs {};
int totalDist {0LL};

void process(int pos){
    if(visited[pos]) return;

    visited[pos] = true;
    for(int nxt:parents[pos]){
        included[nxt] = true;

        int other {pathDefs[nxt].getOther(pos)};
        if(!visited[other]){
            process(other);
        }
    }
}

int main(){
    int nPoints;
    int nTrails;

    while(cin >> nPoints >> nTrails){
        paths.assign(nPoints,{});
        dist.assign(nPoints,-1);
        parents.assign(nPoints, {});
        visited.assign(nPoints,false);
        included.assign(nTrails,false);
        pathDefs.clear();
        pathDefs.reserve(nTrails);

        totalDist = 0;
        
        //get paths
        long long a, b, w;
        for(int i=0;i<nTrails;i++){
            cin >> a >> b >> w;
            pathDefs.emplace_back(i,a,b,w);
            paths[a].push_back(i);
            paths[b].push_back(i);
        }
        
        //cummulative dist, node, viaPath
        priority_queue<tuple<int,int,int>> q {};

        int cutoff {INF};
        q.emplace(0,0,-1);
        
        while(!q.empty()){
            int currDist {-get<0>(q.top())};
            int currNode {get<1>(q.top())};
            int prevPath {get<2>(q.top())};

            q.pop();
            
            if(currDist > cutoff) break;

            if(dist[currNode] == -1){
                parents[currNode].push_back(prevPath);
                dist[currNode] = currDist;

                if(currNode == (nPoints-1)){
                    cutoff = currDist;
                }

                //process next nodes
                for(int i:paths[currNode]){
                    auto nxt {pathDefs[i]};
                    auto trav {nxt.traverse(currNode,nxt.getLength())};

                    if(trav.first!=-1){
                        q.emplace(-trav.first,trav.second,i);
                    }
                }
            } else if (dist[currNode] == currDist){
                parents[currNode].push_back(prevPath);
            } 
        }

        //backtrack
        parents[0].clear();
        process(nPoints-1);
        
        totalDist = 0;
        for(int i=0;i<nTrails;i++){
            if(included[i]){
                totalDist += pathDefs[i].getLength();
            }
        }

        cout << (totalDist<<1) << '\n';
    }
}