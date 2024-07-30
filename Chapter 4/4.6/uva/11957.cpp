#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<string> grid {};
int vals[100][100] {};
int gridSize;
int dCol[2] {-1,1};

int main(){
    int nCases;
    cin >> nCases;
    for(int tc=1;tc<=nCases;++tc){
        cin >> gridSize;
        memset(vals,0,sizeof(vals));
        grid.assign(gridSize,"");
        for(int i=gridSize-1;i>=0;--i){
            cin >> grid[i];
            auto it {grid[i].find('W')};
            if(it != -1){
                vals[i][it] = 1;
            }
        }

        for(int row=0;row<gridSize-1;++row){
            for(int col=0;col<gridSize;++col){
                for(int d:dCol){
                    int tCol = col + d;

                    if(tCol < 0 || tCol >= gridSize) continue;

                    //check if occupied by black
                    if(grid[row+1].at(tCol) == 'B'){
                        tCol += d;
                        if((row+2 >= gridSize) || (tCol < 0) || (tCol >= gridSize)) continue;
                        
                        if(grid[row+2].at(tCol) != '.') continue;

                        vals[row+2][tCol] += vals[row][col];
                        vals[row+2][tCol] %= 1000007;
                    } else {
                        vals[row+1][tCol] += vals[row][col];
                        vals[row+1][tCol] %= 1000007;
                    }
                }
            }
        }
        int ans {0};
        int rowNum {gridSize-1};
        for(int i=0;i<gridSize;++i){
            ans += vals[rowNum][i];
            ans %= 1000007;
        }
        cout << "Case " << tc << ": " << ans << '\n';
    }
}