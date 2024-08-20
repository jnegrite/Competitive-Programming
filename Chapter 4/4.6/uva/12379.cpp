#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int nCities;
vector<vector<int>> paths {};

pair<int,int> traverse(int pos){
    vector<int> dist {};
    dist.assign(nCities+1,-1);
    queue<int> q {};
    q.push(pos);
    dist[pos] = 0;

    int curr;
    while(!q.empty()){
        curr = q.front();
        q.pop();

        int distVal = dist[curr]+1;
        for(int nxt: paths[curr]){
            auto &nxtDist {dist[nxt]};

            if(nxtDist == -1){
                nxtDist = distVal;
                q.push(nxt);
            }
        }
    }

    return {curr, dist[curr]};
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        paths.clear();
        cin >> nCities;
        paths.assign(nCities+1,{});

        int nNeighbors;
        int val;
        for(int i=1;i<=nCities;++i){
            cin >> nNeighbors;
            while(nNeighbors--){
                cin >> val;
                paths[i].push_back(val);
            }
        }

        auto farthest {traverse(1)};
        auto ans {traverse(farthest.first)};

        cout << ((nCities-1)<<1) - ans.second << '\n';
    }
}
