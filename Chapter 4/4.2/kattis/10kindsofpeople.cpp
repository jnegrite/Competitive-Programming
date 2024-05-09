#include<cstdio>

using namespace std;
int rows, cols;
int idx0 {2}, idx1 {3};
char s[1001] {};
int grid[1000][1000] {};
int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

void floodfill(int row, int col, int target, int newVal){
    if(row<0 || row >= rows) return;
    if(col<0 || col >= cols) return;
    if(grid[row][col] != target) return;

    grid[row][col] = newVal;
    for(int i=0;i<4;++i){
        floodfill(row+dRow[i],col+dCol[i],target,newVal);
    }
}

int main(){
    scanf("%d %d\n",&rows,&cols);

    for(int row=0;row<rows;++row){
        scanf("%s\n",&s);
        for(int col=0;col<cols;++col){
            grid[row][col] = s[col] - '0';
        }
    }

    int nQueries;
    int rFrom, cFrom, rTo, cTo;

    scanf("%d\n",&nQueries);
    while(nQueries--){
        scanf("%d %d %d %d\n",&rFrom,&cFrom,&rTo,&cTo);

        rFrom--;
        cFrom--;
        rTo--;
        cTo--;

        //check if not reached by floodfill yet
        if(grid[rFrom][cFrom] == 0){
            floodfill(rFrom,cFrom,0,idx0);
            idx0 += 2;
        } else if(grid[rFrom][cFrom] == 1){
            floodfill(rFrom,cFrom,1,idx1);
            idx1 += 2;
        }

        if(grid[rFrom][cFrom] == grid[rTo][cTo]){
            if(grid[rFrom][cFrom] % 2 == 0){
                printf("binary\n");
            } else {
                printf("decimal\n");
            }
        } else {
            printf("neither\n");
        }
    }
}