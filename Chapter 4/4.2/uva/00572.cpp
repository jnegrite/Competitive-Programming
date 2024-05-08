#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int rows, cols;

char grid[101][101] {};

void floodfill(int oRow, int oCol){
    int rFrom, rTo, cFrom, cTo;

    rFrom = max(0,oRow-1);
    rTo = min(rows-1,oRow+1);
    cFrom = max(0,oCol-1);
    cTo = min(cols-1,oCol+1);

    grid[oRow][oCol] = 'x';
    for(int row=rFrom;row<=rTo;++row){
        for(int col=cFrom;col<=cTo;++col){
            if(row!=oRow || col!=oCol){
                if(grid[row][col] == '@'){
                    floodfill(row,col);
                }
            }
        }
    }
}

int main(){
    while(scanf("%d %d\n",&rows,&cols),rows != 0){
        //get data for
        for(int i=0;i<rows;++i){
            scanf("%s\n",&grid[i]);
        }

        int nWells {0};

        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                if(grid[row][col] == '@'){
                    nWells++;
                    floodfill(row,col);
                }
            }
        }
        printf("%d\n",nWells);
    }
}