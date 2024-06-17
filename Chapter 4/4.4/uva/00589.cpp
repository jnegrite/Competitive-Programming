#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
#include<string>

using namespace std;

int rows, cols;
int targetRow, targetCol, bRow, bCol, row, col;

const int dRow[4] {-1,0,1,0};
const int dCol[4] {0,1,0,-1};
const char chCode[4] {'n','e','s','w'};
const int offset {'A' - 'a'};

char grid[20][20] {};
int dist[20][20][20][20] {};

string s;

struct State {
    int dist {};
    int totalSteps {};
    int row {};
    int col {};
    int bRow {};
    int bCol {};
    string path {};

    State(int _dist, int _totalSteps, int _row, int _col, int _bRow, int _bCol, string _path){
        dist = _dist;
        totalSteps = _totalSteps;
        row = _row;
        col = _col;
        bRow = _bRow;
        bCol = _bCol;
        path = _path;
    }

    bool operator<(const State &o) const {
        if(dist != o.dist){
            return dist > o.dist;
        } else if(totalSteps != o.totalSteps){
            return totalSteps > o.totalSteps;
        } else if(row!=o.row){
            return row <o.row;
        } else if(col!=o.col){
            return col < o.col;
        } else if(bRow != o.bRow){
            return bRow < o.bRow;
        } else {
            return bCol < o.bCol;
        }
    }
};

bool isValid(int row, int col){
    return row>=0 && row<rows && col>=0 && col<cols && grid[row][col] == '.';
}

int main(){
    int tc {};
    while(cin >> rows >> cols, rows!=0 && cols!=0){
        //get data
        for(int i=0;i<rows;i++){
            cin >> s;
            for(int j=0;j<cols;j++){
                switch(s.at(j)){
                    case 'T':
                        targetRow = i;
                        targetCol = j;
                        break;
                    case 'B':
                        bRow = i;
                        bCol = j;
                        break;
                    case 'S':
                        row = i;
                        col = j;
                        break;
                }

                if(s.at(j) == '#'){
                    grid[i][j] = '#';
                } else {
                    grid[i][j] = '.';
                }
            }
        }

        memset(dist,-1,sizeof(dist));
        priority_queue<State> q {};
        q.push({0,0,row,col,bRow,bCol,""});

        string finPath {"A"};
        while(!q.empty()){
            State curr {q.top()};
            q.pop();

            int &ref {dist[curr.row][curr.col][curr.bRow][curr.bCol]};

            if(ref != -1) continue;

            ref = curr.dist;

            if(curr.bRow==targetRow && curr.bCol==targetCol) {
                finPath = curr.path;
                break;
            }

            //check locations
            for(int i=0;i<4;i++){
                int tRow {curr.row + dRow[i]};
                int tCol {curr.col + dCol[i]};

                if(!isValid(tRow,tCol)) continue;

                //check if box is in the way
                if(tRow == curr.bRow && tCol == curr.bCol){
                    //check if valid next pos
                    int tbRow {curr.row + 2*dRow[i]};
                    int tbCol {curr.col + 2*dCol[i]};

                    if(isValid(tbRow,tbCol)){
                        string nxtPath {curr.path + static_cast<char>(chCode[i] + offset)};
                        q.push({curr.dist+1,curr.totalSteps+1,tRow,tCol,tbRow,tbCol,nxtPath});
                    }
                } else {
                    string nxtPath {curr.path + static_cast<char>(chCode[i])};
                    q.push({curr.dist,curr.totalSteps+1,tRow,tCol,curr.bRow,curr.bCol,nxtPath});
                }
            }
        }

        cout << "Maze #" << ++tc << '\n';

        if(finPath == "A"){
            cout << "Impossible.\n";
        } else {
            cout << finPath << '\n';
        }
        cout << '\n';
    }
}