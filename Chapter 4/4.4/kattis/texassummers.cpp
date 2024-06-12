#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<cmath>
using namespace std;

int nSpots {};
vector<pair<int,int>> spots {};
vector<int> parent {};
vector<int> dist {};

int getDist(int a, int b){
    int dx {spots[a].first - spots[b].first};
    int dy {spots[a].second - spots[b].second};

    return dx*dx + dy*dy;
}

int main(){
    cin >> nSpots;
    spots.assign(nSpots+2,{0,0});
    parent.assign(nSpots+2,-1);
    dist.assign(nSpots+2,-1);

    for(int i=1;i<=nSpots;i++){
        cin >> spots[i].first >> spots[i].second;
    }

    cin >> spots[0].first >> spots[0].second;
    cin >> spots[nSpots+1].first >> spots[nSpots+1].second;

    priority_queue<tuple<int,int,int>> q {};
    q.emplace(0,0,0);

    while(!q.empty() && parent[nSpots+1] == -1){
        int currDist {-get<0>(q.top())};
        int currNode {get<1>(q.top())};
        int currP {get<2>(q.top())};

        q.pop();

        if(parent[currNode] != -1) continue;
        
        parent[currNode] = currP;
        dist[currNode] = currDist;

        for(int i=1;i<=nSpots+1;i++){
            if(parent[i] != -1) continue;

            q.emplace(-(currDist+getDist(currNode,i)),i,currNode);
        }
    }

    deque<int> ans {};
    int curr {parent[nSpots+1]};
    while(curr!=0){
        ans.push_front(curr);
        curr = parent[curr];
    };

    if(ans.empty()){
        cout << "-\n";
    } else {
        while(!ans.empty()){
            cout << ans.front()-1 << '\n';
            ans.pop_front();
        }
    }
}