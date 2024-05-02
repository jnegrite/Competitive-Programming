#include<iostream>
#include<vector>

using namespace std;

struct RowSpecs{
    int offset {};
    int interval {};
    int speed {};
};

int totalRows, totalCols;
vector<RowSpecs> rowDetails {};

int carPos(int row, int col, int time);

bool isSafe(int row, int col, int time, char dir){
    if(row < 0 || row >= totalRows){
        return true;
    }

    if(dir=='U' || dir == 'D') {
        return abs(carPos(row,col,time) - col) >= rowDetails[row].speed;
    }

    //case when moving left or right and area stayed at is not safe
    if(abs(carPos(row,col,time) - col) < rowDetails[row].speed){
        return false;
    }

    //if occupied is safe but conflict of direction
    if(row%2 == 0 && dir == 'L' && !isSafe(row,col+1,time-1,'U')){
        return false;
    }

    if(row%2 == 1 && dir == 'R' && !isSafe(row,col-1,time-1,'U')){
        return false;
    }

    return true;
}

int carPos(int row, int col, int time){
    if(row%2){
        col = totalCols - col;
    }

    RowSpecs rs {rowDetails[row]};
    int actualOffset = {(rs.offset + time * rs.speed)%rs.interval};
    int carPos = actualOffset;

    if(col > actualOffset){
        int factor {1 + ((col - actualOffset)/rs.interval)};
        carPos = actualOffset + (rs.interval * factor);
    }

    if(row%2){
        carPos = totalCols - carPos;
    }
    return carPos;
}


int main(){
    cin >> totalRows >> totalCols;

    
    for(int i=0;i<totalRows;i++){
        RowSpecs temp {};
        cin >> temp.offset >> temp.interval >> temp.speed;
        rowDetails.push_back(temp);
    }
    int currRow, currCol;
    string movements {};

    cin >> currCol >> movements;

    currRow = totalRows;
    bool safe {true};

    for(int i=0 ; safe && i<movements.length();i++){
        char currMove {movements.at(i)};
        switch(currMove){
            case 'U':
                currRow--;
                break;
            case 'D':
                currRow++;
                break;
            case 'L':
                currCol--;
                break;
            case 'R':
                currCol++;
                break;
        }

        if(!isSafe(currRow,currCol,i+1,currMove)){
            safe = false;
        }
    }

    if(currRow >= 0){
        safe = false;
    }

    cout << (safe?"safe":"squish") << '\n';
}