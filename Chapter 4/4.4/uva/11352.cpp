#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
using ii = pair<int,int>;

int rows, cols;
string s;
ii locA {};
ii locB {};
vector<ii> knights {};
char grid[100][100] {};
int dRow[8] {-2,-2,-1,-1,1,1,2,2};
int dCol[8] {-1,1,-2,2,-2,2,-1,1};

bool inGrid(int row, int col){
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

int main(){
    int nCases;
    cin >> nCases;

    while(nCases--){
        //get data
        cin >> rows >> cols;
        knights.clear();
        for(int row=0;row<rows;++row){
            cin >> s;
            for(int col=0;col<cols;col++){
                grid[row][col] = s.at(col);

                switch(grid[row][col]){
                    case 'A':
                        locA = {row,col};
                        break;
                    case 'B':
                        locB = {row,col};
                        break;
                    case 'Z':
                        knights.emplace_back(row,col);
                        break;
                }
            }
        }

        //process blocked locations
        for(ii currK:knights){
            int row {currK.first};
            int col {currK.second};

            for(int i=0;i<8;++i){
                int tRow = row + dRow[i];
                int tCol = col + dCol[i];

                //only process if valid
                if(inGrid(tRow,tCol) && grid[tRow][tCol] == '.'){
                    grid[tRow][tCol] = 'D';
                }
            }
        }

        //do the walk
        queue<tuple<int,int,int>> q {};
        q.push({locA.first,locA.second,0});

        int ans {-1};
        while(!q.empty() && ans == -1){
            auto curr {q.front()};
            q.pop();
            int row {get<0>(curr)};
            int col {get<1>(curr)};
            int currDist {get<2>(curr)};

            for(int i=-1;i<=1 && ans == -1;++i){
                for(int j=-1;j<=1 && ans == -1;++j){
                    int tRow = row+i;
                    int tCol = col+j;

                    //check if target
                    if(inGrid(tRow,tCol)){
                        switch(grid[tRow][tCol]){
                            case 'B':
                                ans = currDist+1;
                                break;
                            case '.':
                                q.emplace(tRow,tCol,currDist+1);
                                grid[tRow][tCol] = 'X';
                                break;
                        }
                    }
                }
            }
        }

        if(ans == -1){
            cout << "King Peter, you can't go now!\n";
        } else {
            cout << "Minimal possible length of a trip is " << ans << '\n';
        }
    }
}