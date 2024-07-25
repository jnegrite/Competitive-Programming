#include<iostream>
#include<queue>

using namespace std;

int gridSize;
int k;

int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

int currValue[100][100] {};
int maxValue[100][100] {};
int deps[100][100] {};

bool inGrid(int row, int col){
    return row >= 0 && row < gridSize && col >= 0 && col < gridSize;
}

void trace(int row, int col){
    int tRow, tCol;
    for(int dir=0;dir<4;++dir){
        for(int i=1;i<=k;i++){
            tRow = row + dRow[dir] * i;
            tCol = col + dCol[dir] * i;

            if(!inGrid(tRow,tCol)) break;

            if(currValue[tRow][tCol] > currValue[row][col]){
                if(deps[tRow][tCol]++ == 0){
                    trace(tRow, tCol);
                }
            }
        }
    }
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        cin >> gridSize >> k;
        for(int row=0;row<gridSize;row++){
            for(int col=0;col<gridSize;col++){
                cin >> currValue[row][col];
                deps[row][col] = maxValue[row][col] = 0;
            }
        }

        //traverse neighbors
        trace(0,0);

        int ans {0};

        queue<pair<int,int>> q {};
        q.emplace(0,0);
        int tRow, tCol;
        
        while(!q.empty()){
            int row {q.front().first};
            int col {q.front().second};
            q.pop();

            const auto &curr = (maxValue[row][col] += currValue[row][col]);
            ans = max(ans, curr);
            for(int dir=0;dir<4;++dir){
                for(int i=1;i<=k;i++){
                    tRow = row + dRow[dir] * i;
                    tCol = col + dCol[dir] * i;

                    if(!inGrid(tRow,tCol)) break;

                    if(currValue[tRow][tCol] > currValue[row][col]){
                        maxValue[tRow][tCol] = max(maxValue[tRow][tCol], curr);

                        if(--deps[tRow][tCol] == 0){
                            q.emplace(tRow,tCol);
                        }
                    }
                }
            }
        }

        cout << ans << '\n';

        if(nCases>0){
            cout << '\n';
        }
    }
}