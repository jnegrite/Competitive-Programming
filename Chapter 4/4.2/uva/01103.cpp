#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
int rows, cols;
int grid[200][200] {};
int counts[6] {};
int hexVal {};
string s;

int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};
vector<pair<char,int>> codes {
    {'A',1},
    {'D',5},
    {'J',3},
    {'K',2},
    {'S',4},
    {'W',0},
};

int floodfill(int row, int col, int target, bool expand){
    if(row < 0 || row >= rows) return 0;
    if(col < 0 || col >= cols) return 0;

    int ans = 0;
    if(grid[row][col] == target){
        grid[row][col] = 2;
        for(int i=0;i<4;++i){
            ans += floodfill(row+dRow[i],col+dCol[i], target, expand);
        }
    } else if(grid[row][col] == 0 && expand){
        floodfill(row,col,0,false);
        ans++;
    }

    return ans;
}

int main(){
    int tc {};

    while(cin >> rows >> cols >> ws,rows!=0 || cols!=0){
        memset(grid,0,sizeof(grid));

        //process grid
        for(int row=0;row<rows;++row){
            cin >> s;
            for(int col=0;col<cols;col++){
                int startCol {col<<2};
                char ch {s.at(col)};
                if(ch >= '0' && ch <= '9'){
                    hexVal = ch - '0';
                } else {
                    hexVal = 10 + (ch - 'a');
                }

                for(int i=0;i<4;++i){
                    if(hexVal & (1<<(3-i))){
                        grid[row][startCol+i] = 1;
                    } else {
                        grid[row][startCol+i] = 0;
                    }
                }
            }
        }
        cols <<= 2;

        //fill outside border
        //top and bottom row
        for(int col=0;col<cols;++col){
            floodfill(0,col,0,false);
            floodfill(rows-1,col,0,false);
        }

        //left and right sides
        for(int row=1;row<rows-1;++row){
            floodfill(row,0,0,false);
            floodfill(row,cols-1,0,false);
        }

        memset(counts,0,sizeof(counts));
        //process
        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                if(grid[row][col] == 1){
                    int areas {floodfill(row,col,1,true)};
                    counts[areas]++;
                }
            }
        }

        cout << "Case " << ++tc << ": ";

        for(auto pr:codes){
            for(int i=0;i<counts[pr.second];++i){
                cout << pr.first;
            }
        }
        cout << '\n';
    }
}