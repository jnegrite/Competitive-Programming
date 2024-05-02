#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


int boardSize;
int maskRow {};
int maskD1 {};
int maskD2 {};
long solutions {};
string rows[15] {};

void backtrack(int col){
    if(col==boardSize){
        ++solutions;
        return;
    }

    for(int row=0;row<boardSize;row++){
        if(rows[row].at(col) == '*'){
            continue;
        }
        int id1 {row+col};
        int id2 {col-row + boardSize};

        if((maskRow & (1<<row))==0 && (maskD1 & (1<<id1))== 0 && (maskD2 & (1<<id2))==0){
            maskRow ^= (1<<row);
            maskD1 ^= (1<<id1);
            maskD2 ^= (1<<id2);

            backtrack(col+1);

            maskRow ^= (1<<row);
            maskD1 ^= (1<<id1);
            maskD2 ^= (1<<id2);
        }
    }
}

int main(){
    string s;
    int tc {};

    while(cin>>boardSize, boardSize != 0){
        //get data
        for(int row=0;row<boardSize;row++){
            cin >> rows[row];
        }

        solutions = 0;
        maskRow=0;
        maskD1=0;
        maskD2=0;
        backtrack(0);

        printf("Case %d: %ld\n",++tc,solutions);
    }
}