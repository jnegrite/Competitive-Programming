#include<cstdio>
#include<cstring>

using namespace std;

int rows, cols;
int grid[1002][1002] {};
char s[1001] {};
int lenCoast {};
int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

void floodfill(int row, int col){
    if(row < 0 || row > (rows+1)) return;
    if(col < 0 || col > (cols+1)) return;

    switch(grid[row][col]){
        case 1:
            ++lenCoast;
        case -1:
            return;
        default:
            grid[row][col] = -1;
            for(int i=0;i<4;++i){
                floodfill(row+dRow[i],col+dCol[i]);
            }
    }
}

int main(){
    scanf("%d %d\n",&rows,&cols);
    
    //get data
    for(int row=1;row<=rows;++row){
        auto &currRow {grid[row]};
        scanf("%s\n",&s);
        for(int col=1;col<=cols;++col){
            currRow[col] = s[col-1] - '0';
        }
    }

    lenCoast = 0;
    floodfill(0,0);
    printf("%d\n",lenCoast);
}