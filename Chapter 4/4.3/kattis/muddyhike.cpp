#include<cstdio>
#include<cstring>
#include<tuple>
#include<queue>

using namespace std;

int rows, cols;

int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};
int grid[1001][1001] {};
bool visited[1001][1001] {};
priority_queue<tuple<int,int,int>> q {};

bool inGrid(int row, int col){
    return row >= 0 && row < rows && col >=0 && col <= cols;
}

void process(int w, int row, int col){
    visited[row][col] = true;

    for(int i=0;i<4;++i){
        int tRow {row+dRow[i]};
        int tCol {col+dCol[i]};

        if(!inGrid(tRow,tCol)) continue;
        if(visited[tRow][tCol]) continue;

        q.emplace(min(w,-grid[tRow][tCol]),tRow,tCol);
    }
}

int main(){
    scanf("%d %d\n",&rows,&cols);
    for(int row=0;row<rows;++row){
        for(int col=1;col<=cols;++col){
            scanf("%d",&grid[row][col]);
        }
    }

    process(0,0,0);
    int ans {};
    while(!q.empty()){
        auto curr {q.top()};
        q.pop();

        int row {get<1>(curr)};
        int col {get<2>(curr)};
        int w {get<0>(curr)};

        if(col==cols){
            ans=-w;
            break;
        }

        if(visited[row][col]) continue;

        process(w,row,col);
    }
    printf("%d\n",ans);
}