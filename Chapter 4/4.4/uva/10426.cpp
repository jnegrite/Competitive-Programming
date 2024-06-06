#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int rows, cols;
int positions [4][2] {};
int monster[2] {};

int gridData[4][2][17][17] {};

int dRow[8] {-2,-2,-1,-1,1,1,2,2};
int dCol[8] {-1,1,-2,2,-2,2,-1,1};

bool inGrid(int row, int col){
    return row>0 && row<=rows && col>0 && col <= cols;
}

void bfs(int king, int mon){
    auto &currGrid {gridData[king][mon]};
    
    //set monster as an invalid square
    if(mon==1){
        currGrid[monster[0]][monster[1]] = -2;
    }

    //set bfs
    queue<pair<int,int>> q {};
    auto &kingLoc {positions[king]};
    currGrid[kingLoc[0]][kingLoc[1]] = 0;
    q.emplace(kingLoc[0],kingLoc[1]);

    int row, col, dist;
    int tRow, tCol;
    while(!q.empty()){
        row = q.front().first;
        col = q.front().second;
        dist = currGrid[row][col];
        q.pop();

        for(int i=0;i<8;i++){
            tRow = row + dRow[i];
            tCol = col + dCol[i];

            if(!inGrid(tRow,tCol) || currGrid[tRow][tCol] != -1){
                continue;
            }
            currGrid[tRow][tCol] = dist+1;
            q.emplace(tRow,tCol);
        }
    }
}

int evaluate(int row, int col){
    //check which to relax
    
    //check if location is impossible for any king
    for(int king=0;king<4;king++){
        if(gridData[king][0][row][col] < 0 && gridData[king][1][row][col] < 0){
            return -1;
        }
    }

    //check if multiple kings are blocked by the monster
    int cntBlocked {0};
    for(int king=0;king<4;king++){
        if(gridData[king][1][row][col] < 0){
            cntBlocked++;
        }
    }

    if(cntBlocked > 1){
        return -1;
    }
    
    //check which king to allow through the monster
    int bestDist {-1};
    for(int king=0;king<4;king++){
        bool ok {true};

        int currDist {0};
        for(int i=0;ok && i<4;i++){
            
            
            int idx {1};
            if(i==king){
                idx = 0;
            }

            //make invalid if blocked
            if(gridData[i][idx][row][col] < 0){
                ok = false;
                break;
            }

            currDist += gridData[i][idx][row][col];
        }

        if(!ok) continue;

        if(bestDist == -1 || currDist < bestDist){
            bestDist = currDist;
        }
    }

    return bestDist;
}


int main(){
    string setCode;
    while(cin >> setCode){
        cin >> rows >> cols;
        memset(gridData,-1,sizeof(gridData));

        //get data
        for(int i=0;i<4;i++){
            cin >> positions[i][0] >> positions[i][1];
        }
        cin >> monster[0] >> monster[1];

        //do bfs for each king
        for(int king=0;king<4;king++){
            for(int mon=0;mon<2;mon++){
                bfs(king, mon);
            }
        }

        //do evaluation here
        int bestDist {-1};

        for(int row=1;row<=rows;row++){
            for(int col=1;col<=cols;col++){
                int temp {evaluate(row,col)};

                if(temp == -1) continue;

                if(bestDist == -1 || temp<bestDist){
                    bestDist = temp;
                }
            }
        }

        cout << setCode << '\n';
        if(bestDist == -1){
            cout << "Meeting is impossible.\n";
        } else {
            cout << "Minimum time required is " << bestDist << " minutes.\n";
        }
    }
}