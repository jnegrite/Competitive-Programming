#include<cstdio>

using namespace std;

int rows, cols;
char grid[51][51] {};
int dRow[4] {-1,0,1,0};
int dCol[4] {0,-1,0,1};

void floodfill(int row, int col){
    if(row < 0 || row >= rows) return;
    if(col < 0 || col >= cols) return;

    switch(grid[row][col]){
        case 'L': case 'C':
            grid[row][col] = 'X';
            for(int i=0;i<4;++i){
                floodfill(row+dRow[i],col+dCol[i]);
            }
    }
}

int main(){
    scanf("%d %d\n",&rows,&cols);
    for(int row=0;row<rows;++row){
        scanf("%s\n",&grid[row]);
    }

    int nIslands {};
    for(int row=0;row<rows;++row){
        for(int col=0;col<cols;++col){
            if(grid[row][col] == 'L'){
                nIslands++;
                floodfill(row,col);
            }
        }
    }

    printf("%d\n",nIslands);
}