#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>

using namespace std;

int nPoints, nRoads, bossHouse, office, yourHouse, market;
vector<bool> ok {};
vector<int> dist {};
vector<vector<pair<int,int>>> paths {};
vector<vector<int>> parents {};
vector<bool> visited {};

void markBossPath(int pos){
    ok[pos] = false;
    
    for(int nxt: parents[pos]){
        if(ok[nxt]){
            markBossPath(nxt);
        }
    }
}

int main(){
    while(cin >> nPoints >> nRoads >> bossHouse >> office >> yourHouse >> market){
        ok.assign(nPoints+1,true);
        paths.assign(nPoints+1,{});
        parents.assign(nPoints+1,{});

        int a, b, d;
        while(nRoads--){
            cin >> a >> b >> d;
            paths[a].emplace_back(b,d);
            paths[b].emplace_back(a,d);
        }

        //check best path for boss
        int bestDist {20000};
        dist.assign(nPoints+1,bestDist);
        dist[bossHouse] = 0;

        //dist, node, parent
        priority_queue<tuple<int,int,int>> q {};
        q.push({0,bossHouse,bossHouse});
        visited.assign(nPoints+1, false);
        
        while(!q.empty()){
            int currDist {-get<0>(q.top())};
            int currNode {get<1>(q.top())};
            int currParent {get<2>(q.top())};
            q.pop();

            //cout << "Processing " << currNode << ": " << currDist << '\n';
            
            visited[currNode] = true;
    
            if(currNode==office){
                bestDist = currDist;
            }

            if(currDist < dist[currNode]){
                parents[currNode] = {currParent};
                dist[currNode] = currDist;
            } else if(currDist == dist[currNode]){
                parents[currNode].push_back(currParent);
            } else {
                continue;
            }

            for(auto nxt: paths[currNode]){
                int nxtNode {nxt.first};
                int nxtDist {currDist + nxt.second};
                if(visited[nxtNode]) continue;

                q.push({-nxtDist,nxtNode,currNode});
            }    
        }

        markBossPath(office);
        
        //do actual dijkstra here
        visited.assign(nPoints+1,false);
        priority_queue<tuple<int,int>> q2 {};

        if(ok[yourHouse]){
            q2.push({0,yourHouse});
        }

        while(!visited[market] && !q2.empty()){
            int currDist {-get<0>(q2.top())};
            int currNode {get<1>(q2.top())};

            q2.pop();
            if(visited[currNode]) continue;
            visited[currNode] = true;
            dist[currNode] = currDist;

            for(auto nxt: paths[currNode]){
                int nxtNode {nxt.first};
                int nxtDist {currDist + nxt.second};

                if(ok[nxtNode] && !visited[nxtNode]){
                    q2.push({-nxtDist, nxtNode});
                }
            }
        }

        if(!visited[market]){
            cout << "MISSION IMPOSSIBLE.\n";
        } else {
            cout << dist[market] << '\n';
        }
    }
}