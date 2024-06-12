#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;

    int nPoints, nEdges, from, to;
    vector<vector<pair<int,int>>> paths {};
    vector<int> dist {};
    for(int tc=1;tc<=nCases;tc++){
        cin >> nPoints >> nEdges >> from >> to;

        paths.assign(nPoints,{});
        dist.assign(nPoints,-1);

        //get paths
        int a, b, w;
        for(int i=0;i<nEdges;i++){
            cin >> a >> b >> w;
            paths[a].emplace_back(b,w);
            paths[b].emplace_back(a,w);
        }

        priority_queue<tuple<int,int>> q {};
        q.emplace(0,from);

        while(!q.empty() && dist[to] == -1){
            int currNode {get<1>(q.top())};
            int currDist {-get<0>(q.top())};
            q.pop();

            if(dist[currNode]!=-1) continue;

            dist[currNode] = currDist;

            for(auto nxt: paths[currNode]){
                int nxtNode {nxt.first};
                int nxtDist {currDist + nxt.second};

                if(dist[nxtNode]!=-1) continue;

                q.emplace(-nxtDist,nxtNode);
            }
        }

        cout << "Case #" << tc << ": ";

        if(dist[to] == -1){
            cout << "unreachable\n";
        } else {
            cout << dist[to] << '\n';
        }
    }
}