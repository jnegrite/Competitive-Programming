#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int nNests, nTrails;
vector<vector<int>> paths {};
vector<int> dist {};

int tryRoots(int root1, int root2){
    vector<int> dist {};
    dist.assign(nNests,-1);

    dist[root1] = 0;
    queue<int> q {};
    q.push(root1);

    if(root2 != -1){
        dist[root2] = 0;
        q.push(root2);
    }

    //set the used edges
    int lastIdx {-1};
    int nxtDist {};
    while(!q.empty()){
        int curr {q.front()};
        lastIdx = curr;
        q.pop();

        nxtDist = dist[curr]+1;

        for(int nxt: paths[curr]){
            if(dist[nxt] >= 0) continue;
            
            dist[nxt] = nxtDist;
            q.push(nxt);
        }
    }

    if(root2 == -1){
        return (dist[lastIdx] << 1);
    } else {
        return (dist[lastIdx] << 1) + 1;
    }
}


int main(){
    int nCases;
    cin >> nCases;
    
    for(int tc=1;tc<=nCases;++tc){
        cin >> nNests >> nTrails;

        dist.assign(nNests,-1);        
        paths.assign(nNests,{});

        int a, b;
        while(nTrails--){
            cin >> a >> b;
            paths[a].push_back(b);
            paths[b].push_back(a);
        }

        queue<int> q {};

        int ans {nNests};

        for(int i=0;i<nNests;++i){
            ans = min(ans,tryRoots(i,-1));
            for(int j: paths[i]){
                if(i<j){
                    ans = min(ans,tryRoots(i,j));
                }
            }
        }

        cout << "Case #" << tc << ":\n";
        cout << ans << "\n\n";

    }

}