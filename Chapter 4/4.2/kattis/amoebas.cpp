#include<cstdio>
#include<iostream>

using namespace std;

char grid[100][101] {};
int rows, cols;

void floodfill(int oRow, int oCol){
    if(oRow < 0 || oRow >= rows ||
        oCol < 0 || oCol >= cols ||
        grid[oRow][oCol] == '.'){
        return;
    }

    grid[oRow][oCol] = '.';
    for(int row=max(0,oRow-1);row<=min(rows-1,oRow+1);++row){
        for(int col=max(0,oCol-1);col<=min(cols-1,oCol+1);++col){
            if(grid[row][col] == '#'){
                floodfill(row,col);
            }
        }
    }
}

int main(){
    scanf("%d %d\n",&rows,&cols);
    for(int i=0;i<rows;++i){
        scanf("%s\n",&grid[i]);
    }

    int ans {0};

    for(int row=0;row<rows;++row){
        for(int col=0;col<cols;++col){
            if(grid[row][col]=='#'){
                ans++;
                floodfill(row,col); //
            }
        }
    }
    printf("%d\n",ans);
}