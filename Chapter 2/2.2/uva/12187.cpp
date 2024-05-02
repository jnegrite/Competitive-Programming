#include<iostream>

using namespace std;

int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};
int numPlayers, nRows, nCols, numBattles;

bool inGrid(int row, int col){
    return row >= 0 && row < nRows &&
        col >= 0 && col < nCols;
}

int main(){

    while(true){
        cin >> numPlayers >> nRows >> nCols >>numBattles;

        //end
        if(numPlayers==0 && nRows==0 && nCols==0 && numBattles==0){
            break;
        }

        //get data
        auto grid = new int[nRows][100];
        for(int row=0;row<nRows;row++){
            for(int col=0;col<nCols;col++){
                cin >> grid[row][col];
            }
        }

        //data
        int thisVal, angryVal;
        while(numBattles--){

            auto handlerGrid = new int[nRows][100];
            for(int row=0;row<nRows;row++){
                

                for(int col=0;col<nCols;col++){
                    bool isAngry {false};
                    thisVal = grid[row][col];
                    angryVal = (thisVal==0?numPlayers-1:thisVal-1);
                    
                    for(int i=0;!isAngry && i<4;i++){
                        int tempRow = row + dRow[i];
                        int tempCol = col + dCol[i];

                        if(inGrid(tempRow,tempCol) && grid[tempRow][tempCol] == angryVal){
                            isAngry = true;;
                        }
                    }

                    handlerGrid[row][col] = (isAngry?angryVal:thisVal);
                }
            }
            auto temp = grid;
            grid = handlerGrid;
            delete temp;
        }

        for(int row=0;row<nRows;row++){
            cout << grid[row][0];
            for(int col=1;col<nCols;col++){
                cout << ' ' << grid[row][col];
            }
            cout << '\n';
        }
        delete grid;
    }
}