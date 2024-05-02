#include<iostream>
#include<vector>

using namespace std;
string grid[4] {};
int boardSize{};
int numCells {};
int maxRooks {};
int currRooks {};

bool isDanger[4][4] {};

int dRow[4] {0,1,0,-1};
int dCol[4] {1,0,-1,0};

void backtrack(int pos){
    if(pos == numCells){
        if(currRooks > maxRooks){
            maxRooks = currRooks;
        }
        return;
    }

    int row {pos/boardSize};
    int col {pos%boardSize};

    backtrack(pos+1);

    //check if ok to put rook
    if(grid[row].at(col) == '.' && !isDanger[row][col]){
        isDanger[row][col] = true;
        ++currRooks;
        vector<pair<int,int>> blockedCells {};

        for(int i=0;i<4;i++){
            int tempRow = row+dRow[i];
            int tempCol = col+dCol[i];

            while(tempRow >= 0 && tempRow < boardSize
                    && tempCol >= 0 && tempCol < boardSize
                    && grid[tempRow].at(tempCol) == '.'){
                
                if(!isDanger[tempRow][tempCol]){
                    isDanger[tempRow][tempCol] = true;
                    blockedCells.push_back(pair<int,int>{tempRow, tempCol});
                }

                tempRow += dRow[i];
                tempCol += dCol[i];
            }
        }

        backtrack(pos+1);

        for(auto pr:blockedCells){
            isDanger[pr.first][pr.second] = false;
        }

        --currRooks;
        isDanger[row][col] = false;
    }
}


int main(){
    while(cin >> boardSize,boardSize > 0){
        
        numCells = boardSize * boardSize;

        //get data
        for(int i=0;i<boardSize;i++){
            cin >> grid[i];
        }

        maxRooks = 0;
        currRooks = 0;
        
        backtrack(0);

        cout << maxRooks << '\n';
    }
}