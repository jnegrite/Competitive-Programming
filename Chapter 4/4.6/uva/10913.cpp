#include<iostream>
#include<cstring>

using namespace std;
int gridSize;
int grid[75][75] {};
int memo[75][75][3][6] {};
int visited[75][75][3][6] {};
int nNeg;

bool inGrid(int row, int col){
    return row >= 0 && row < gridSize &&
        col >= 0 && col < gridSize;
}

pair<bool,int> dp(int row, int col, int dir, int remNeg){
    
    if(grid[row][col] < 0){
        if(remNeg == 0){
            return {false, 0};
        } else {
            --remNeg;
        }
    }

    if((row==gridSize-1) && (col==gridSize-1)){
        return {true,grid[row][col]};
    }

    int &flag {visited[row][col][dir][remNeg]};
    int &curr {memo[row][col][dir][remNeg]};

    if(flag == 0){
        return {false, 0};
    } else if(flag == 1){
        return {true, curr};
    }
    
    flag = 0;
    int low {0};
    int high {2};
    if(dir == 0){
        high = 1;
    } else if(dir==2){
        low = 1;
    }

    int tRow, tCol;
    for(int i=low;i<=high;++i){
        if(i==1){
            tRow = row+1;
            tCol = col;
        } else {
            tRow = row;
            tCol = col+i-1;
        }

        if(!inGrid(tRow,tCol)) continue;

        auto temp {dp(tRow,tCol,i,remNeg)};

        if(!temp.first) continue;
        
        int tempVal {grid[row][col] + temp.second};
        if((flag == 0) || (curr < tempVal)){
            flag = 1;
            curr = tempVal;
        }
    }

    if(flag==0){
        return {false,0};
    } else {
        return {true,curr};
    }
}

int main(){
    int tc {};
    while(cin >> gridSize >> nNeg, gridSize!=0 || nNeg!=0){
        memset(grid,-1,sizeof(grid));
        memset(memo,-1,sizeof(memo));
        memset(visited,-1,sizeof(visited));
        
        for(int row=0;row<gridSize;++row){
            for(int col=0;col<gridSize;++col){
                cin >> grid[row][col];
            }
        }

        auto curr {dp(0,0,1,nNeg)};

        cout << "Case " << ++tc << ": ";

        if(curr.first){
            cout << curr.second << '\n';
        } else {
            cout << "impossible\n";
        }
    }
}