#include<iostream>
#include<string>
#include<cstring>

using namespace std;

char grid[25][26] {};
string s;
int rows, cols;

int floodfill(int row, int col){
    if(row < 0 || row >= rows ||
            col < 0 || col >= cols ||
            grid[row][col] == '0'){
        return 0;
    }

    int ans {1};
    grid[row][col] = '0';
    for(int cRow=max(0,row-1);cRow<=min(rows-1,row+1);++cRow){
        for(int cCol=max(0,col-1);cCol<=min(cols-1,col+1);++cCol){
            ans += floodfill(cRow,cCol);
        }
    }
    return ans;
}

int main(){
    int nCases;
    cin >> nCases >> ws;

    while(nCases--){

        //get input
        rows = 0;
        while(true){
            getline(cin,s);
            if(s.length()==0){
                break;
            }
            strcpy(grid[rows++],s.c_str());
        }

        cols = strlen(grid[0]);

        int maxSize = 0;
        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                if(grid[row][col] == '1'){
                    maxSize = max(maxSize,floodfill(row,col));
                }
            }
        }
        cout << maxSize << '\n';

        if(nCases){
            cout << '\n';
        }
    }
}
