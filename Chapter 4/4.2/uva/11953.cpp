#include<cstdio>
#include<iostream>

using namespace std;
int gridSize;

char grid[100][101] {};

bool floodfill(int row, int col){
    if(row < 0 || row >= gridSize ||
            col < 0 || col >= gridSize ||
            grid[row][col] == '.'){
        return false;
    }

    bool ans {grid[row][col] == 'x'};
    grid[row][col] = '.';

    for(int cRow=max(0,row-1);cRow<=min(gridSize-1,row+1);++cRow){
        for(int cCol=max(0,col-1);cCol<=min(gridSize-1,col+1);++cCol){
            if(floodfill(cRow,cCol)){
                ans = true;
            }
        }
    }
    return ans;
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);

    for(int tc=1;tc<=nCases;++tc){
        scanf("%d\n",&gridSize);

        for(int i=0;i<gridSize;++i){
            scanf("%s\n",&grid[i]);
        }

        int nShips {};
        for(int row=0;row<gridSize;++row){
            for(int col=0;col<gridSize;++col){
                switch(grid[row][col]){
                    case 'x': case '@':
                        if(floodfill(row,col)){
                            nShips++;
                        }
                }
            }
        }
        printf("Case %d: %d\n",tc,nShips);
    }

}