#include<cstdio>
#include<vector>

using namespace std;
int nPeople;
vector<vector<int>> paths {};
vector<int> p {};
vector<int> dfs_num {};
vector<int> dfs_low {};
int ctr {};

bool hasBridge {false};

bool determineBridge(int pos) {
    dfs_num[pos] = dfs_low[pos] = ctr++;
    for(int &nxt:paths[pos]){
        if(dfs_num[nxt] == -1){
            p[nxt] = pos;

            if(determineBridge(nxt)){
                return true;
            }

            if(dfs_low[nxt] > dfs_num[pos]){
                return true;
            }
            dfs_low[pos] = min(dfs_low[pos],dfs_low[nxt]);
        } else if (p[pos] != nxt){
            dfs_low[pos] = min(dfs_low[pos],dfs_num[nxt]);
        }
    }
    return false;
}

int main(){
    int nConnections;
    while(scanf("%d %d\n",&nPeople,&nConnections),nPeople!=0 || nConnections!=0){
        paths.assign(nPeople,{});
        p.assign(nPeople,-1);
        dfs_num.assign(nPeople,-1);
        dfs_low.assign(nPeople,0);

        int a, b;
        while(nConnections--){
            scanf("%d %d\n",&a,&b);
            paths[a].push_back(b);
            paths[b].push_back(a);
        }

        int cc {};
        hasBridge = false;
        for(int i=0;!hasBridge && i<nPeople;i++){
            if(dfs_num[i] == -1){
                if(cc++ > 0 || determineBridge(i)){
                    hasBridge=true;
                }
            }
        }

        if(hasBridge){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}