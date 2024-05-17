#include<cstdio>

using namespace std;

int rows, cols, nInstructions;
int row, col;
char dirCodes[5] {"NLSO"};
int orientation {};
char instructions[50000] {};
char grid[100][100] {};

int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};
int nStickers {};

void move(){
    int tRow = row + dRow[orientation];
    int tCol = col + dCol[orientation];

    //check if invalid
    if(tRow < 0 || tRow >= rows) return;
    if(tCol < 0 || tCol >= cols) return;
    switch(grid[tRow][tCol]){
        case '*':
            ++nStickers;
            grid[tRow][tCol] = '.';
            //fallthrough
        case '.':
            row = tRow;
            col = tCol;
            break;
    }
}

int main(){
    while(scanf("%d %d %d\n",&rows,&cols,&nInstructions),rows!=0 || cols !=0 || nInstructions!=0){
        //get map
        orientation = -1;
        for(int i=0;i<rows;++i){
            scanf("%s\n",&grid[i]);
            for(int j=0;orientation==-1 && j<cols;++j){
                for(int k=0;orientation==-1 && k<4;++k){
                    if(grid[i][j] == dirCodes[k]){
                        orientation = k;
                        row = i;
                        col = j;
                        grid[i][j] = '.';
                    }
                }
            }
        }
        scanf("%s\n",&instructions);

        //follow instructions
        nStickers = 0;
        for(int i=0;i<nInstructions;++i){
            switch(instructions[i]){
                case 'D':
                    orientation = (orientation+1)%4;
                    break;
                case 'E':
                    orientation += 3;
                    orientation %= 4;
                    break;
                case 'F':
                    move();
                    break;
            }
        }

        printf("%d\n",nStickers);
    }
}