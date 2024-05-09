#include<cstdio>
#include<iostream>

using namespace std;

int rows, cols;
char grid[20][21] {};
int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};
char land;
char water;

int floodfill(int row, int col){
    //normalize
    if(row < 0 || row >= rows){
        return 0;
    }

    if(col < 0){
        col+=cols;
    } else if (col >= cols){
        col-=cols;
    }

    if(grid[row][col] != land){
        return 0;
    }

    int ans {1};
    grid[row][col] = water;
    for(int i=0;i<4;++i){
        ans += floodfill(row+dRow[i],col+dCol[i]);
    }
    return ans;
}

int main(){
    while(scanf("%d %d\n",&rows,&cols)!=EOF){
        for(int i=0;i<rows;i++){
            scanf("%s\n",&grid[i]);
        }

        //clear old teritory
        int iRow, iCol;
        scanf("%d %d\n\n",&iRow,&iCol);
        land = grid[iRow][iCol];
        if(land=='a'){
            water='b';
        } else {
            water=land-1;
        }
        floodfill(iRow,iCol);
        int bestArea {0};

        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                if(grid[row][col] == land){
                    bestArea = max(bestArea,floodfill(row,col));
                }
            }
        }
        printf("%d\n",bestArea);
    }
}