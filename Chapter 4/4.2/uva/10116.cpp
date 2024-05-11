#include<cstdio>
#include<cstring>
#include<unordered_map>

using namespace std;

int rows, cols;
char grid[10][11] {};
bool visited[10][10] {};
unordered_map<char,pair<int,int>> dir {
    {'N',{-1,0}},
    {'S',{1,0}},
    {'E',{0,1}},
    {'W',{0,-1}}
};

int cntLoop {};
int cntPath {};
bool isLoop {};
int rowLoop, colLoop;

void process(int row, int col){
    if(row < 0 || row >= rows) return;
    if(col < 0 || col >= cols) return;

    //check if loops
    if(visited[row][col]){
        rowLoop = row;
        colLoop = col;
        isLoop = true;
        return;
    }

    visited[row][col] = true;
    auto &offset {dir[grid[row][col]]};
    process(row+offset.first, col+offset.second);

    if(isLoop){
        cntLoop++;
        if(row==rowLoop && col==colLoop){
            isLoop=false;
        }
    } else {
        cntPath++;
    }
}

int main(){
    int startCol;
    while(scanf("%d %d %d\n",&rows,&cols,&startCol),rows!=0 || cols != 0){
        for(int i=0;i<rows;++i){
            scanf("%s\n",&grid[i]);
        }
        memset(visited,false,sizeof(visited));
        cntPath=0;
        cntLoop=0;
        isLoop=false;

        process(0,startCol-1);
        if(cntLoop > 0){
            printf("%d step(s) before a loop of %d step(s)\n",cntPath,cntLoop);
        } else {
            printf("%d step(s) to exit\n",cntPath);
        }
    }    
}