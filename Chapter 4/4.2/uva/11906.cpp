#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int rows, cols, m, n;
int dRow[4] {-1,-1,1,1};
int dCol[4] {-1,1,-1,1};

int grid[100][100] {};

void dfs(int row, int col){
    auto &curr {grid[row][col]};
    curr = 0;

    int r = m;
    int c = n;
    int tempRow, tempCol;
    
    if(r == 0 && c==0){
        return;
    }

    for(int reps=0;reps<2;++reps){
        int startIdx {0};
        int endIdx {3};

        if(r==0 || c==0){
            startIdx = 1;
            endIdx = 2;
        }
        for(int i=startIdx;i<=endIdx;i++){
            tempRow = row + r*dRow[i];
            tempCol = col + c*dCol[i];

            if(tempRow < 0 || tempRow >= rows) continue;
            if(tempCol < 0 || tempCol >= cols) continue;
            if(grid[tempRow][tempCol] == -2) continue;

            ++curr;
            if(grid[tempRow][tempCol] == -1){
                dfs(tempRow, tempCol);
            }
        }
        if(r==c){
            break;
        }
        swap(r,c);
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    for(int tc=1;tc<=nCases;++tc){
        memset(grid,-1,sizeof(grid));
        int nWater;
        int a, b;
        scanf("%d %d %d %d",&rows,&cols,&m,&n);
        scanf("%d\n",&nWater);
        while(nWater--){
            scanf("%d %d\n",&a,&b);
            grid[a][b] = -2;
        }
        
        dfs(0,0);
        int nOdd {};
        int nEven {};

        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                auto &curr {grid[row][col]};
                if(curr >= 0){
                    if(curr%2==0){
                        ++nEven;
                    } else {
                        ++nOdd;
                    }
                }
            }
        }

        printf("Case %d: %d %d\n",tc,nEven,nOdd);
    }
}