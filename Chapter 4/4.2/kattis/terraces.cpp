#include<cstdio>

using namespace std;
int rows, cols;
int grid[500][500] {};
bool visited[500][500] {};

int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

bool fall {};

inline bool inGrid(int row, int col){
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

int dfs(int row, int col){
    if(visited[row][col]) return 0;

    visited[row][col] = true;
    int ans {1};
    for(int i=0;i<4;i++){
        int tempRow {row + dRow[i]};
        int tempCol {col + dCol[i]};
        if(inGrid(tempRow,tempCol)){
            if(grid[tempRow][tempCol] < grid[row][col]){
                fall=true;
            } else if (!visited[tempRow][tempCol] && grid[tempRow][tempCol] == grid[row][col]){
                ans += dfs(tempRow,tempCol);
            }
        }
    }
    return ans;
}


int main(){
    scanf("%d %d\n",&cols,&rows);
    for(int row=0;row<rows;++row){
        for(int col=0;col<cols;++col){
            scanf("%d",&grid[row][col]);
        }
    }

    int ans {0};
    for(int row=0;row<rows;++row){
        for(int col=0;col<cols;++col){
            if(!visited[row][col]){
                fall = false;
                int size {dfs(row,col)};
                if(!fall){
                    //printf("Include %d,%d:%d\n",row,col,size);
                    ans += size;
                }    
            }
        }
    }
    printf("%d\n",ans);
}
