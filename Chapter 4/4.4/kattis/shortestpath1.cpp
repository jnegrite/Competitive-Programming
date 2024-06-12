#include<cstdio>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int nNodes;
int nEdges;
int nQueries;
int startNode;
vector<vector<pair<int,int>>> paths {};
vector<int> dist {};

int main(){
    while(true){
        scanf("%d %d %d %d\n",&nNodes,&nEdges,&nQueries,&startNode);
        
        if(nNodes==0 && nEdges==0 && nQueries==0 && startNode==0){
            break;
        }

        paths.assign(nNodes,{});
        int a, b, w;
        while(nEdges--){
            scanf("%d %d %d\n",&a,&b,&w);
            paths[a].emplace_back(b,w);
        }

        //do dijkstra
        dist.assign(nNodes,-1);
        priority_queue<tuple<int,int>> q {};
        q.emplace(0,startNode);
        
        while(!q.empty()){
            tuple<int,int> curr {q.top()};
            int currDist {get<0>(curr)};
            int currNode {get<1>(curr)};
            q.pop();

            if(dist[currNode] != -1) continue;

            dist[currNode] = -currDist;

            for(auto nxt: paths[currNode]){
                if(dist[nxt.first] != -1) continue;
                q.emplace(currDist-nxt.second,nxt.first);
            }
        }
        
        //answer queries;
        while(nQueries--){
            scanf("%d\n",&a);
            if(dist[a] == -1){
                printf("Impossible\n");
            } else {
                printf("%d\n",dist[a]);
            }
        }
    }
}