#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int nCases;
vector<string> grid {};
vector<pair<int,int>> points {};
bool isUsed[100][100] {};
int rows, cols;

int floodfill(int row, int col, char mark){
    if(row < 0 || row >= rows) return 0;
    if(col < 0 || col >= cols) return 0;
    if(isUsed[row][col] || grid[row].at(col) != mark) return 0;

    int ans = 1;
    isUsed[row][col] = true;
    for(int i=row-1;i<=row+1;++i){
        for(int j=col-1;j<=col+1;++j){
            if(i!=row || j!=col){
                ans += floodfill(i,j,mark);
            }
        }
    }
    return ans;
}

string s;
int pos; 
int main(){
    cin >> nCases >> ws;

    while(nCases--){
        points.clear();
        grid.clear();

        //get data
        while(true){
            getline(cin,s);

            if(s.length() == 0){
                break;
            } else if((pos=s.find(' ')) != -1){
                points.push_back({stoi(s.substr(0,pos))-1,stoi(s.substr(pos+1))-1});
                continue;
            }

            //put into grid
            grid.push_back(s);
        }

        rows = grid.size();
        cols = grid[0].length();

        //process
        for(auto pr:points){
            memset(isUsed,false,sizeof(isUsed));
            cout << floodfill(pr.first, pr.second, 'W') << '\n';
        }
        if(nCases > 0){
            cout << '\n';
        }
    }
}