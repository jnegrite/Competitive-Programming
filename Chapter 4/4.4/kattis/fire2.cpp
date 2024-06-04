#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
using ii = pair<int,int>;

int rows, cols;
char grid[1000][1000] {};
string s;
vector<ii> fireLocations {};
ii personLoc {};

int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

bool inGrid(int row, int col){
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

int main(){
    int nCases;
    cin >> nCases;
    
    while(nCases--){
        cin >> cols >> rows;
        fireLocations.clear();
        //get data
        for(int row=0;row<rows;++row){
            cin >> s;
            for(int col=0;col<cols;++col){
                grid[row][col] = s.at(col);

                switch(grid[row][col]){
                    case '@':
                        personLoc = {row,col};
                        break;
                    case '*':
                        fireLocations.emplace_back(row,col);
                        break;
                }
            }
        }

        //process queue

        //row, col, distance, character
        queue<tuple<int,int,int,char>> q {};
        for(ii fire:fireLocations){
            q.emplace(fire.first,fire.second,0,'*');
        }
        q.emplace(personLoc.first,personLoc.second,0,'@');

        //process queue
        int tRow, tCol, row, col, dist;
        char ch;
        int ans {-1};
        while(!q.empty() && ans==-1){
            auto curr {q.front()};
            q.pop();

            row = get<0>(curr);
            col = get<1>(curr);
            dist = get<2>(curr);
            ch = get<3>(curr);

            if(ch == '*'){
                for(int i=0;i<4;++i){
                    tRow = row+dRow[i];
                    tCol = col+dCol[i];
                
                    if(inGrid(tRow,tCol) && 
                            (grid[tRow][tCol]=='.' || grid[tRow][tCol] == '@')){
                        q.emplace(tRow,tCol,0,ch);
                        grid[tRow][tCol] = ch;
                    }
                }
            } else if (ch == '@') {
                for(int i=0;i<4;++i){
                    tRow = row+dRow[i];
                    tCol = col+dCol[i];
                
                    if(inGrid(tRow,tCol) && grid[tRow][tCol]=='.'){
                        q.emplace(tRow,tCol,dist+1,ch);
                        grid[tRow][tCol] = ch;
                    } else if(!inGrid(tRow,tCol)){
                        ans = dist+1;
                        break;
                    }
                }
            }
        }

        if(ans==-1){
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ans << '\n';
        }
    }
}