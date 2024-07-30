#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int gridSize;
unsigned int numPaths[1000][1000] {};
const unsigned int mod {(1u<<31)-1u};
vector<string> grid {};

bool traversible(){
    bool visited[1000][1000] {};
    queue<pair<int,int>> q {};

    int dRow[4] {-1,0,1,0};
    int dCol[4] {0,1,0,-1};

    q.emplace(0,0);
    visited[0][0] = true;

    int row, col, tRow, tCol;
    while(!q.empty()){
        row = q.front().first;
        col = q.front().second;
        q.pop();

        for(int i=0;i<4;++i){
            tRow = row + dRow[i];
            tCol = col + dCol[i];

            if(tRow < 0 || tRow >= gridSize ||
                tCol < 0 || tCol >= gridSize ||
                visited[tRow][tCol] ||
                grid[tRow].at(tCol) == '#') continue;
            
            visited[tRow][tCol] = true;
            q.emplace(tRow, tCol);
        }
    }
    return visited[gridSize-1][gridSize-1];
}

int main(){
    cin >> gridSize;
    grid.reserve(gridSize);
    string s;

    for(int i=0;i<gridSize;++i){
        cin >> s;
        grid.push_back(s);
    }

    //check numPaths
    if(grid[0].at(0) == '.'){
        numPaths[0][0] = 1;
        for(int row=0;row<gridSize;++row){
            string &currS {grid[row]};
            for(int col=0;col<gridSize;++col){
                if(currS.at(col) == '#') continue;

                if(col < gridSize-1 && currS.at(col+1) == '.'){
                    numPaths[row][col+1] += numPaths[row][col];
                    numPaths[row][col+1] %= mod;
                }

                if(row < gridSize-1 && grid[row+1].at(col) == '.'){
                    numPaths[row+1][col] += numPaths[row][col];
                    numPaths[row][col+1] %= mod;
                }
            }
        }
    }

    auto &ans {numPaths[gridSize-1][gridSize-1]};
    if(ans != 0){
        cout << ans << '\n';
    } else if (traversible()){
        cout << "THE GAME IS A LIE\n";
    } else {
        cout << "INCONCEIVABLE\n";
    }
}