#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;

int nPoints, nNodes, source, target;
int p;
vector<tuple<int,int,int>> paths {};
vector<vector<pair<int,int>>> forwards {};
vector<vector<pair<int,int>>> backwards {};

vector<int> distF {};
vector<int> distB {};

int main(){
    int nCases;
    cin >> nCases;

    while(nCases--){
        cin >> nPoints >> nNodes >> source >> target >> p;
        paths.clear();
        forwards.assign(nPoints+1,{});
        backwards.assign(nPoints+1,{});
        distF.assign(nPoints+1,-1);
        distB.assign(nPoints+1,-1);

        int a, b, w;
        while(nNodes--){
            cin >> a >> b >> w;
            forwards[a].emplace_back(b,w);
            backwards[b].emplace_back(a,w);
            paths.emplace_back(w,a,b);
        }

        //forwards
        priority_queue<tuple<int,int>> q {};
        q.emplace(0,source);
        while(!q.empty()) {
            int currDist {-get<0>(q.top())};
            int currNode {get<1>(q.top())};
            q.pop();
            
            if(distF[currNode] != -1) continue;

            distF[currNode] = currDist;

            for(auto nxt:forwards[currNode]){
                if(distF[nxt.first] != -1) continue;

               q.emplace(-(currDist+nxt.second),nxt.first);
            }
        }

        //backwards
        q.emplace(0,target);
        while(!q.empty()) {
            int currDist {-get<0>(q.top())};
            int currNode {get<1>(q.top())};
            q.pop();
            
            if(distB[currNode] != -1) continue;

            distB[currNode] = currDist;

            for(auto nxt:backwards[currNode]){
                if(distB[nxt.first] != -1) continue;

               q.emplace(-(currDist+nxt.second),nxt.first);
            }
        }

        sort(paths.begin(),paths.end());
        int ans {-1};
        for(auto currPath {paths.rbegin()};ans == -1 &&currPath !=paths.rend();currPath++){
            int currDist {get<0>(*currPath)};
            int currFrom {get<1>(*currPath)};
            int currTo {get<2>(*currPath)};

            if(distF[currFrom] == -1 || distB[currTo]==-1){
                continue;
            }

            int tempCost {distF[currFrom] + currDist + distB[currTo]};

            if(tempCost > p) continue;

            ans = currDist;
        }

        cout << ans << '\n';
    }
}