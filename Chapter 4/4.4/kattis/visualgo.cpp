#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

#define INF 1000000

using namespace std;

int nPoints, nEdges;
vector<vector<pair<int,int>>> paths {};
vector<vector<int>> parents {};
vector<int> dist {};
vector<int> totalParents {};
int source, target;

int getParents(int pos){
    if(pos == source){
        return 1;
    }

    auto &curr {totalParents[pos]};

    if (curr != -1){
        return curr;
    }

    curr = 0;
    for(auto p:parents[pos]){
        curr += getParents(p);
    }

    return curr;
}


int main(){
    cin >> nPoints >> nEdges;
    paths.assign(nPoints,{});
    parents.assign(nPoints,{});
    dist.assign(nPoints,-1);
    totalParents.assign(nPoints,-1);

    //get data
    int a, b, w;
    while(nEdges--){
        cin >> a >> b >> w;
        paths[a].emplace_back(b,w);
    }

    //do dijkstra
    int cutoff {INF};
    cin >> source >> target;
    priority_queue<tuple<int,int,int>> q {};
    q.emplace(0,source,source);

    while(!q.empty()){
        int currDist {-get<0>(q.top())};
        int currNode {get<1>(q.top())};
        int currParent {get<2>(q.top())};

        q.pop();

        if(currDist > cutoff){
            break;
        }

        if(currNode == target){
            cutoff = currDist;
        }

        if(dist[currNode] == -1){
            dist[currNode] = currDist;
            parents[currNode].push_back(currParent);

            for(auto nxt: paths[currNode]){
                int nxtNode {nxt.first};
                int nxtDist {currDist + nxt.second};

                if(dist[nxtNode] == -1 | dist[nxtNode] == nxtDist){
                    q.emplace(-nxtDist,nxtNode,currNode);
                }
            }
        } else if (dist[currNode] == currDist){
            parents[currNode].push_back(currParent);
        }
    }

    cout << getParents(target) << '\n';
}
