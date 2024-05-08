#include<cstdio>
#include<iostream>

using namespace std;

char grid[100][101] {};
int rows, cols;
int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

void floodfill(int row, int col){
    if(row < 0 || row >= rows ||
        col < 0 || col >= cols ||
        grid[row][col] == '#'){
        return;
    }

    grid[row][col] = '#';
    for(int i=0;i<4;++i){
        floodfill(row+dRow[i],col+dCol[i]);
    }
}

int main(){
    int tc {0};
    while(scanf("%d %d\n",&rows,&cols)!=EOF){
        for(int i=0;i<rows;++i){
            scanf("%s\n",&grid[i]);
        }

        int ans {0};

        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                if(grid[row][col]=='-'){
                    ans++;
                    floodfill(row,col); //
                }
            }
        }
        printf("Case %d: %d\n",++tc,ans);
    }
}