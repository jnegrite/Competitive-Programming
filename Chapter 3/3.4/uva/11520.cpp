#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

char grid[10][10];
int gridSize;
string curr;
int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

bool inGrid(int row, int col){
    return row >= 0 && row < gridSize
        && col >= 0 && col < gridSize;
}

unordered_set<char> getNeighbors(int row, int col){
    unordered_set<char> output {};
    int tempRow;
    int tempCol;
    for(int i=0;i<4;i++){
        tempRow = row + dRow[i];
        tempCol = col + dCol[i];

        if(inGrid(tempRow,tempCol) && grid[tempRow][tempCol] != '.'){
            output.emplace(grid[tempRow][tempCol]);
        }
    }
    return output;
}

int main(){
    int nCases;
    cin >> nCases;
    for(int tc=1;tc<=nCases;++tc){
        cin >> gridSize;
        for(int row=0;row<gridSize;++row){
            auto &rowRef {grid[row]};
            cin >> curr;
            for(int col=0;col<gridSize;++col){
                rowRef[col] = curr.at(col);
            }
        }

        //process
        cout << "Case " << tc << ":\n";
        for(int row=0;row<gridSize;++row){
            auto &rowRef {grid[row]};
            for(int col=0;col<gridSize;++col){
                if(rowRef[col] == '.'){
                    auto neighbors = getNeighbors(row,col);
                    char ans {};
                    for(char ch='A'; ch <= 'E'; ch++){
                        if(neighbors.count(ch) == 0){
                            rowRef[col] = ch;
                            cout << ch;
                            break;
                        }
                    }
                } else {
                    cout << rowRef[col];
                }
            }
            cout << '\n';
        }
    }
}
