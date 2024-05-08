#include<cstdio>
#include<cstring>

using namespace std;
int rows, cols;
char grid[50][51] {};
bool draft[50][50] {};
int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

int floodfill(int row, int col){
    int ans {0};
    switch(grid[row][col]){
        case '#':
        case 'T':
            ans = 0;
            break;
        case 'G':
            ans = 1;
            //fallthrough
        case '.':
        case 'P':
            grid[row][col] = '#';
            if(!draft[row][col]){
                for(int i=0;i<4;++i){
                    ans += floodfill(row+dRow[i],col+dCol[i]);
                } 
            }
    }
    return ans;
}

int main(){
    while(scanf("%d %d\n",&cols,&rows)!=EOF){
        memset(draft,false,sizeof(draft));
        for(int row=0;row<rows;++row){
            scanf("%s\n",&grid[row]);
        }

        //set drafts
        int initRow = -1;
        int initCol = -1;
        for(int row=1;row<rows-1;++row){
            for(int col=1;col<cols-1;++col){
                switch(grid[row][col]){
                    case 'T':
                        for(int i=0;i<4;++i){
                            draft[row+dRow[i]][col+dCol[i]] = true;
                        }
                        break;
                    case 'P':
                        initRow = row;
                        initCol = col;
                        break;
                }
            }
        }

        printf("%d\n",floodfill(initRow,initCol));
    }
}