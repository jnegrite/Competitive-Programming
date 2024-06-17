#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int rows, cols;
bool visited[500][500] {};
int height[500][500] {};

int getHeight(int row, int col, int currHeight){
    if(row<0 || row>=rows || col<0 || col>=cols || visited[row][col] || height[row][col] >= 0) return 0;

    return min(currHeight,-height[row][col]);
}

int main(){
    cin >> rows >> cols;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin >> height[i][j];
        }
    }
    
    int row, col;
    cin >> row >> col;
    --row;
    --col;

    long long totalWater {};
    priority_queue<tuple<int,int,int>> q {};
    
    if(height[row][col] < 0){
        q.push({-height[row][col],row,col});
    }

    while(!q.empty()){
        int cRow {get<1>(q.top())};
        int cCol {get<2>(q.top())};
        int currHeight {get<0>(q.top())};
        q.pop();

        if(visited[cRow][cCol]) continue;

        visited[cRow][cCol] = true;
        totalWater += currHeight;

        for(int i=-1;i<=1;i++){
            int tRow {cRow+i};
            for(int j=-1;j<=1;j++){
                int tCol {cCol+j};

                int possible {getHeight(tRow,tCol,currHeight)};

                if(possible <= 0) continue;

                q.emplace(possible,tRow,tCol);
            }
        }
    }

    cout << totalWater << '\n';
}