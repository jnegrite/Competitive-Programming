#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

int nRows, nCols;
vector<vector<int>> grid {};

int main(){
    int nCases;
    cin >> nCases >> ws;

    while(nCases--){
        cin >> nRows >> nCols >> ws;
        grid.clear();        
        vector<int> subGrid {};
        subGrid.assign(nCols+1,0);
        grid.assign(nRows+1,subGrid);

        //get row data
        string s;
        int rowNum, colNum;
        while(getline(cin,s),s.length() != 0){
            auto strIn {stringstream(s)};
            
            strIn >> rowNum;
            while(strIn >> colNum){
                grid[rowNum][colNum] = -1;
            }
        }

        //traverse
        if(grid[1][1] == -1 || grid[nRows][nCols] == -1){
            grid[nRows][nCols] = 0;
        } else {
            grid[1][1] = 1;
            for(int row=1;row<=nRows;++row){
                for(int col=1;col<=nCols;++col){
                    const auto &curr {grid[row][col]};
                    if (curr == -1) continue;

                    if (col != nCols && grid[row][col+1] != -1){
                        grid[row][col+1] += curr;
                    }

                    if(row != nRows && grid[row+1][col] != -1){
                        grid[row+1][col] += curr;
                    }
                }
            }
        }
        cout << grid[nRows][nCols] << '\n';

        if(nCases > 0){
            cout << '\n';
        }


    }

}