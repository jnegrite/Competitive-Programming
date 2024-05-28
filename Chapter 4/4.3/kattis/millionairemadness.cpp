#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>

using namespace std;

int rows, cols;
bool visited[1001][1001] {};
int grid[1001][1001] {};
priority_queue<tuple<int,int,int>> q {};

int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

bool inGrid(int row, int col){
    return row > 0 && row <= rows &&
        col > 0 && col <= cols;
}

void process(int w, int row, int col){
    visited[row][col] = true;

    for(int i=0;i<4;i++){
        int tempRow {row + dRow[i]};
        int tempCol {col + dCol[i]};

        if(!inGrid(tempRow,tempCol)) continue;
        if(visited[tempRow][tempCol]) continue;
        q.emplace(min(w,grid[row][col]-grid[tempRow][tempCol]),tempRow,tempCol);
    }
}


int main(){
    scanf("%d %d\n",&rows,&cols);
    memset(visited,false,sizeof(visited));
    int ans;
    for(int row=1;row<=rows;++row){
        for(int col=1;col<=cols;++col){
            scanf("%d",&grid[row][col]);
        }
    }

    q.emplace(0,1,1);

    while(!q.empty()){
        auto curr {q.top()};
        q.pop();
        int row {get<1>(curr)};
        int col {get<2>(curr)};
        int w {get<0>(curr)};

        if(visited[row][col]) continue;
        if(row == rows && col == cols){
            ans = -w;
            break;
        }

        process(w,row,col);
    }
    printf("%d\n",ans);
}