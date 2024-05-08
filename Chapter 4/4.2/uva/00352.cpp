#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
int rows, cols;
char grid[25][26] {};

void floodfill(int oRow, int oCol){
    int rFrom {max(0,oRow-1)};
    int rTo {min(rows-1,oRow+1)};
    int cFrom {max(0,oCol-1)};
    int cTo {min(cols-1,oCol+1)};

    grid[oRow][oCol] = '0';
    for(int row=rFrom;row<=rTo;row++){
        for(int col=cFrom;col<=cTo;col++){
            if(grid[row][col] == '1'){
                floodfill(row,col);
            }
        }
    }
}

int main(){
    int tc {};

    while(scanf("%d\n",&rows)!=EOF){
        for(int i=0;i<rows;++i){
            scanf("%s\n",&grid[i]);
        }

        cols = rows;

        int nEagles {};
        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                if(grid[row][col] == '1'){
                    nEagles++;
                    floodfill(row,col);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",++tc,nEagles);
    }
}