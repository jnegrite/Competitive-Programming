#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

string s;
int rows, cols;
int steps[500][500] {};
int grid[500][500] {};

int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

int main(){
    cin >> rows >> cols >> ws;
    memset(steps,-1,sizeof(steps));

    for(int i=0;i<rows;++i){
        cin >> s;
        for(int j=0;j<cols;++j){
            grid[i][j] = s.at(j)-'0';
        }
    }

    steps[0][0] = 0;
    queue<pair<int,int>> q {}; 
    q.push({0,0});

    while(!q.empty() && steps[rows-1][cols-1] == -1){
        auto curr {q.front()};
        q.pop();

        int row {curr.first};
        int col {curr.second};

        for(int i=0;i<4;i++){
            int tRow {row + grid[row][col] * dRow[i]};
            int tCol {col + grid[row][col] * dCol[i]};

            if(tRow < 0 || tRow >= rows || tCol < 0 || tCol >= cols) continue;
            if(steps[tRow][tCol] != -1) continue;

            steps[tRow][tCol] = steps[row][col] + 1;
            q.push({tRow,tCol});
        }
    }

    cout << steps[rows-1][cols-1] << '\n';
}