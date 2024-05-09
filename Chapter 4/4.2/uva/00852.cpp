#include<cstdio>

using namespace std;
int gridSize {9};
char grid[9][10] {};
int mask {};
int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

int floodfill(int row, int col){
    if(row<0 || row >= gridSize){
        return 0;
    }
    if(col<0 || col >= gridSize){
        return 0;
    }
    int ans;

    switch(grid[row][col]){
        case '-':
            return 0;
        case 'X':
            mask |= 1;
            return 0;
        case 'O':
            mask |= 2;
            return 0;
        case '.':
            ans = 1;
            grid[row][col] = '-';
            for(int i=0;i<4;++i){
                ans += floodfill(row+dRow[i],col+dCol[i]);    
            }
            return ans;
    }
    return 0;
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    while(nCases--){
        for(int i=0;i<9;i++){
            scanf("%s\n",&grid[i]);
        }
        
        int nBlack {};
        int nWhite {};

        for(int row=0;row<gridSize;++row){
            for(int col=0;col<gridSize;++col){
                int temp {};
                switch(grid[row][col]){
                    case 'X':
                        ++nBlack;
                        break;
                    case 'O':
                        ++nWhite;
                        break;
                    case '.':
                        mask = 0;
                        temp = floodfill(row,col);
                        if(mask == 1){
                            nBlack += temp;
                        } else if(mask==2){
                            nWhite += temp;
                        }
                }
            }
        }

        printf("Black %d White %d\n",nBlack,nWhite);
    }
}