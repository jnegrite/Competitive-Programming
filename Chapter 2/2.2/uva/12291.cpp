#include<iostream>
#include<vector>

using namespace std;

int n {}, m{};

bool inGrid(int row, int col){
    return row >= 0 && row < n && col >= 0 && col < n;
}

bool isValid(int grid[10][10], int subGrid[10][10]){
    //get top left of both
    pair<int,int> gridTL {};
    pair<int,int> subGridTL {};
    vector<pair<int,int>> markers{};

    bool isFound {false};
    for(int row=0;!isFound && row<n;row++){
        for(int col=0;!isFound && col<n;col++){
            if(grid[row][col] == 1){
                isFound = true;
                gridTL.first = row;
                gridTL.second = col;
            }
        }
    }
    if(!isFound){
        return false;
    }

    //get the subGrid vector of changes
    isFound = false;
    for(int row=0;row<m;row++){
        for(int col=0;col<m;col++){
            if(subGrid[row][col] == 1){
                if(!isFound){
                    isFound = true;
                    subGridTL.first = row;
                    subGridTL.second = col;
                }

                pair<int,int> temp {};
                temp.first = row - subGridTL.first;
                temp.second = col - subGridTL.second;
                markers.push_back(temp);
            }
        }
    }
    if(!isFound){
        return false;
    }

    //first removal of original layout
    for(auto pr:markers){
        int tempRow = gridTL.first + pr.first;
        int tempCol = gridTL.second + pr.second;

        if((!inGrid(tempRow,tempCol)) || (grid[tempRow][tempCol] == 0)){
            return false;
        } else {
            grid[tempRow][tempCol] = 0;
        }
    }

    isFound=false;
    for(int row=gridTL.first;!isFound && row<n;row++){
        for(int col=0;!isFound && col<n;col++){
            if(grid[row][col] == 1){
                isFound = true;
                gridTL.first = row;
                gridTL.second = col;
            }
        }
    }
    if(!isFound){
        return false;
    }

    //second removal
    for(auto pr:markers){
        int tempRow = gridTL.first + pr.first;
        int tempCol = gridTL.second + pr.second;

        if((!inGrid(tempRow,tempCol)) || (grid[tempRow][tempCol] == 0)){
            return false;
        } else {
            grid[tempRow][tempCol] = 0;
        }
    }

    //making sure nothing got left behind
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col] == 1){
                return false;
            }
        }
    }

    return true;
}

int main(){
    string s;
    while((cin>>n>>m)){
        if(m==0 & n==0){
            break;
        }
        auto grid = new int[10][10];
        auto subGrid = new int[10][10];

        for(int row=0;row<n;row++){
            cin >> s;
            for(int col=0;col<n;col++){
                if(s.at(col) == '*'){
                    grid[row][col]=1;
                } else {
                    grid[row][col]=0;
                }
            }
        }

        for(int row=0;row<m;row++){
            cin >> s;
            for(int col=0;col<m;col++){
                if(s.at(col) == '*'){
                    subGrid[row][col]=1;
                } else {
                    subGrid[row][col]=0;
                }
            }
        }

        if(isValid(grid, subGrid)){
            cout << 1;
        } else {
            cout << 0;
        }
        cout << '\n';

        delete grid;
        delete subGrid;
    }
    return 0;
}