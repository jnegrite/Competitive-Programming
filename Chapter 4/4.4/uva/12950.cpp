#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>

using namespace std;

int nCities, nRoads;

vector<vector<pair<int,int>>> paths {};
int dist[10001][2] {};

int main(){
    while(cin >> nCities >> nRoads){
        paths.assign(nCities+1,{});
        memset(dist,-1,sizeof(dist));

        int a, b, w;
        while(nRoads--){
            cin >> a >> b >> w;
            paths[a].emplace_back(b,w);
            paths[b].emplace_back(a,w);
        }

        priority_queue<tuple<int,int,int>> q {};
        q.emplace(0,1,1);

        int ans {-1};
        while(!q.empty()){
            int currDist {-get<0>(q.top())};
            int currNode {get<1>(q.top())};
            int isValid {get<2>(q.top())};
            q.pop();

            if (dist[currNode][isValid] != -1) continue;

            dist[currNode][isValid] = currDist;
            if(currNode == nCities && isValid == 1){
                ans = currDist;
                break;
            }

            int nxtValid {1-isValid};
            for(auto nxt: paths[currNode]){
                int nxtNode {nxt.first};
                int nxtDist {currDist + nxt.second};
                
                if(dist[nxtNode][nxtValid] != -1) continue;

                q.emplace(-nxtDist,nxtNode,nxtValid);
            }
        }
        cout << ans << '\n';
    }
}