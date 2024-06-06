#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int gridSize;

int dist[100][100] {};
vector<pair<int,int>> paths {
    {-2,-1},
    {-2,1},
    {-1,-2},
    {-1,2},
    {1,-2},
    {1,2},
    {2,-1},
    {2,1},
};

bool inGrid(int row, int col){
    return row>=0 && row < gridSize && col>=0 && col < gridSize;
}

int main(){
    cin >> gridSize;
    memset(dist,-1,sizeof(dist));

    queue<pair<int,int>> q {};

    string s;
    for(int row=0;row<gridSize;row++){
        cin >> s;
        for(int col=0;col<gridSize;col++){
            switch(s.at(col)){
                case 'K':
                    dist[row][col] = 0;
                    q.emplace(row,col);
                    break;
                case '#':
                    dist[row][col] = -2;
                    break;
            }
        }
    }

    int ans {-1};

    while(!q.empty() && ans==-1){
        int row {q.front().first};
        int col {q.front().second};

        q.pop();

        if(row==0 && col==0){
            ans = dist[row][col];
            break;
        }

        for(auto nxt: paths){
            int tRow {row+nxt.first};
            int tCol {col+nxt.second};

            if(!inGrid(tRow,tCol) || dist[tRow][tCol] != -1) continue;

            dist[tRow][tCol] = dist[row][col]+1;
            q.emplace(tRow,tCol);
        }
    }

    cout << ans << '\n';
    
}