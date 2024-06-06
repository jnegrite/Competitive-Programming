#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int gridSize, nQueries;
int dist[20][20][3] {};

vector<vector<pair<int,int>>> paths {
    {
        {-2,-1},
        {-2,1},
        {-1,-2},
        {-1,2},
        {1,-2},
        {1,2},
        {2,-1},
        {2,1},
    },
    {
        {-3,-1},
        {-3,1},
        {-1,-3},
        {-1,3},
        {1,-3},
        {1,3},
        {3,-1},
        {3,1},
    },
    {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1},
    },
    {
        {-1,-1},
        {-1,1},
        {1,-1},
        {1,1},
    }
};

bool inGrid(int row, int col){
    return row>=0 && row<gridSize && col>=0 && col<gridSize;
}

int bfs(int idxFrom, int idxTo){
    int rFrom, cFrom, rTo, cTo;

    if(idxFrom == idxTo) return 0;

    int ans {-1};
    memset(dist,-1,sizeof(dist));
    queue<tuple<int,int,int>> q {};

    --idxFrom;
    --idxTo;

    rFrom = idxFrom/gridSize;
    cFrom = idxFrom%gridSize;

    rTo = idxTo/gridSize;
    cTo = idxTo%gridSize;
    
    //set seed values
    for(int i=0;i<3;i++){
        q.emplace(rFrom,cFrom,i);
        dist[rFrom][cFrom][i] = 0; 
    }

    while(!q.empty() && ans==-1){
        int row {get<0>(q.front())};
        int col {get<1>(q.front())};
        int mode {get<2>(q.front())};

        q.pop();

        int tRow, tCol;
        if(mode <= 1){
            for(auto nxt:paths[mode]){
                tRow = row + nxt.first;
                tCol = col + nxt.second;

                if(!inGrid(tRow,tCol) || dist[tRow][tCol][mode+1] != -1) continue;

                if(tRow == rTo && tCol==cTo){
                    return dist[row][col][mode] + 1;
                    break;
                }

                dist[tRow][tCol][mode+1] = dist[row][col][mode] + 1;
                q.emplace(tRow,tCol,mode+1);
            }
        } else {
            //mode == 2
            for(int md=2;ans==-1 && md<=3;md++){
                for(auto nxt:paths[md]){
                    tRow = row + nxt.first;
                    tCol = col + nxt.second;

                    if(!inGrid(tRow,tCol) || (md==2 && dist[tRow][tCol][0] != -1)) continue;

                    if(tRow == rTo && tCol==cTo){
                        return dist[row][col][mode] + 1;
                        break;
                    }

                    if(md==2){
                        dist[tRow][tCol][0] = dist[row][col][mode] + 1;
                        q.emplace(tRow,tCol,0);
                    }

                    if(ans!=-1){
                        break;
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    int tc {};
    while(scanf("%d",&gridSize),gridSize!=0){
        scanf("%d\n",&nQueries);
        printf("Set %d:\n",++tc);
        
        int idxFrom, idxTo;
        while(nQueries--){
            scanf("%d %d\n",&idxFrom,&idxTo);
            int ans {bfs(idxFrom,idxTo)};

            if (ans==-1){
                printf("?\n");
            } else {
                printf("%d\n",ans);
            }
        }

    }
}