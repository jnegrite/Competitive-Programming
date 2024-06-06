#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int,int>> paths {
    {-2,-1},
    {-2,1},
    {-1,-2},
    {-1,2},
    {1,-2},
    {1,2},
    {2,-1},
    {2,1},
};

int dist[100][100] {};

int rows, cols;
int rFrom, cFrom, rTo, cTo;

bool inGrid(int row, int col){
    return row>=0 && row<rows && col>=0 && col<cols;
}

int bfs(){
    if(rFrom==rTo && cFrom==cTo) return 0;
    --rFrom;
    --cFrom;
    --rTo;
    --cTo;

    memset(dist,-1,sizeof(dist));

    queue<pair<int,int>> q {};
    q.emplace(rFrom,cFrom);
    dist[rFrom][cFrom] = 0;

    while(!q.empty()){
        int row {q.front().first};
        int col {q.front().second};
        q.pop();

        for(auto nxt:paths){
            int tRow {row+nxt.first};
            int tCol {col+nxt.second};

            if(!inGrid(tRow,tCol) || dist[tRow][tCol]!=-1) continue;

            if(tRow==rTo && tCol==cTo) return dist[row][col]+1;

            dist[tRow][tCol] = dist[row][col]+1;
            q.emplace(tRow,tCol);
        }
    }
    return -1;
}

int main(){
    while(scanf("%d %d %d %d %d %d\n",&rows,&cols,&rFrom,&cFrom,&rTo,&cTo)!=EOF){
        int ans {bfs()};

        if(ans==-1){
            printf("impossible\n");
        } else {
            printf("%d\n",ans);
        }
    }
}