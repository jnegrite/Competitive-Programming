#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int nComputers, nCables;
vector<vector<int>> paths {};
vector<bool> visited {};

pair<int,int> getFarthest(int src){
    queue<int> q {};
    vector<int> dist {};
    dist.assign(nComputers,-1);
    dist[src] = 0;

    q.push(src);

    int lastId {-1};
    while(!q.empty()){
        lastId = q.front();
        q.pop();
        visited[lastId] = true;

        for(int nxt: paths[lastId]){
            if(dist[nxt] != -1) continue;

            dist[nxt] = dist[lastId]+1;
            q.push(nxt);
        }
    }
    return {lastId,dist[lastId]};
}

int main(){
    cin >> nComputers >> nCables;
    paths.assign(nComputers,{});
    visited.assign(nComputers,false);

    int a, b;
    while(nCables--){
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }

    
    vector<int> diameters {};
    for(int i=0;i<nComputers;++i){
        if(!visited[i]){
            pair<int,int> tmp {getFarthest(i)};
            diameters.push_back(getFarthest(tmp.first).second);
        }
    }

    sort(diameters.begin(),diameters.end(),greater<int>());
    int ans {};

    if(diameters.size() == 1){
        ans = diameters[0];
    } else {
        ans = diameters[0];
        for(int i=0;i<diameters.size();++i){
            diameters[i]++;
            diameters[i] >>= 1;
        }

        ans = max(ans,diameters[0] + diameters[1] + 1);
        if(diameters.size()>2){
            int tempDiam = diameters[1] + diameters[2] + 2;
            ans = max(ans,tempDiam);
        }
    }

    cout << ans << '\n';
}
