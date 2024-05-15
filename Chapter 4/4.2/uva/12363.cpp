#include<cstdio>
#include<vector>

using namespace std;

vector<vector<int>> paths {};
vector<vector<int>> bridges {};
vector<int> p {};
vector<int> dfs_num {};
vector<int> dfs_low {};
vector<bool> visited {};

int nRooms;
int ctr {};
int roomFrom, roomTo;

bool dfs(int pos){
    if(pos == roomTo){
        return true;
    }
    visited[pos] = true;
    for(int &nxt:bridges[pos]){
        if(!visited[nxt]){
            if(dfs(nxt)){
                return true;
            }
        }
    }
    return false;
}

void getBridges(int pos){
    dfs_num[pos] = dfs_low[pos] = ctr++;
    for(int &nxt: paths[pos]){
        if(dfs_num[nxt]==-1){
            p[nxt] = pos;
            getBridges(nxt);

            if(dfs_low[nxt] > dfs_num[pos]){
                bridges[nxt].push_back(pos);
                bridges[pos].push_back(nxt);
            }

            dfs_low[pos] = min(dfs_low[pos],dfs_low[nxt]);
        } else if(p[pos] != nxt){
            dfs_low[pos] = min(dfs_low[pos],dfs_num[nxt]);
        }
    }
}

int main(){
    int nCorridors, nQueries;

    while(scanf("%d %d %d\n",&nRooms,&nCorridors,&nQueries),
            nRooms!=0 || nCorridors!=0 || nQueries!=0){
        nRooms++;
        paths.assign(nRooms,{});
        bridges.assign(nRooms,{});
        p.assign(nRooms,-1);
        dfs_num.assign(nRooms,-1);
        dfs_low.assign(nRooms,0);
        nRooms--;

        int a, b;
        while(nCorridors-- > 0){
            scanf("%d %d\n",&a,&b);
            paths[a].push_back(b);
            paths[b].push_back(a);
        }

        //check bridges
        for(int i=1;i<=nRooms;++i){
            if(dfs_num[i] == -1){
                ctr=0;
                getBridges(i);
            }
        }

        while(nQueries--){
            scanf("%d %d\n",&roomFrom,&roomTo);
            visited.assign(nRooms+1,false);
            if(dfs(roomFrom)){
                printf("Y\n");
            } else {
                printf("N\n");
            }
        }
        printf("-\n");
    }

}