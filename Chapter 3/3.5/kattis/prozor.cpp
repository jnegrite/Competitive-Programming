#include<cstdio>

using namespace std;

char grid[101][101] {};
int vals[100][100] {};
int rows, cols, k;

int main(){
    scanf("%d %d %d\n", &rows, &cols, &k);
    int bestCoords[4] {0,0,k-1,k-1};
    k-=2;
    for(int row=0;row<rows;++row){
        scanf("%s\n",&grid[row]);
        for(int col=0;col<cols;++col){
            if(grid[row][col] == '*'){
                vals[row][col] = 1;
            }

            if(col > 0){
                vals[row][col] += vals[row][col-1];
            }
        }
    }

    int bestAns = -1;
    for(int l=1,r=l+k-1;r<cols-1;++l,++r){
        int currAns = 0;
        //initialize
        for(int row=0;row<k;++row){
            currAns += vals[row][r] - vals[row][l-1];
        }

        for(int t=0,b=t+k;b<rows-1;++t,++b){
            currAns -= (vals[t][r] - vals[t][l-1]);
            currAns += (vals[b][r] - vals[b][l-1]);
        
            if(currAns > bestAns){
                bestCoords[0] = t;
                bestCoords[1] = l-1;
                bestCoords[2] = b+1;
                bestCoords[3] = r+1;
                bestAns = currAns;
            }
        }
    }
    printf("%ld\n",bestAns);

    for(int row=0;row<rows;++row){
        for(int col=0;col<cols;++col){
            if((row == bestCoords[0] || row == bestCoords[2])
                    && (col==bestCoords[1] || col == bestCoords[3])){
                grid[row][col] = '+';
            } else if ((row == bestCoords[0] || row == bestCoords[2]) && bestCoords[1] < col && bestCoords[3] > col){
                grid[row][col] = '-';
            } else if ((col == bestCoords[1] || col == bestCoords[3]) && bestCoords[0] < row && bestCoords[2] > row){
                grid[row][col] = '|';
            }
        }
    }
    for(int i=0;i<rows;++i){
        printf("%s\n", grid[i]);
    }
}