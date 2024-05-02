#include<iostream>

using namespace std;

bool inGrid(int row, int col){
    return row >= 0 && row < 5 && col >= 0 && col < 5;
}

int dRow[8] {-2,-2,-1,-1,1,1,2,2};
int dCol[8] {-1,1,-2,2,-2,2,-1,1};

int main(){
    string data[5] {};
    bool validSolution {true};
    int numKnights {0};
    for(int i=0;i<5;i++){
        cin >> data[i];
    }

    for(int row=0;validSolution && row<5;row++){
        for(int col=0;validSolution && col<5;col++){
            if(data[row].at(col) == 'k'){
                numKnights++;
                for(int i=0;i<8;i++){
                    int tempRow = row + dRow[i];
                    int tempCol = col + dCol[i];

                    if(inGrid(tempRow,tempCol) && data[tempRow].at(tempCol) == 'k'){
                        validSolution = false;
                    }
                }
            }
        }
    }

    if(validSolution && numKnights == 9){
        cout << "valid\n";
    } else {
        cout << "invalid\n";
    }
}