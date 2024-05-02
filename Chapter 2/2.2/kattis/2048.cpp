#include<iostream>

using namespace std;

int main(){
    int grid[4][4] {};
    int output[4][4] {};
    for(int row=0;row<4;row++){
        for(int col=0;col<4;col++){
            cin >> grid[row][col];
        }
    }
    int dir;
    cin >> dir;

    int evalPos;
    int outputPos;
    if(dir==0){
        for(int row=0;row<4;row++){
            bool didMerge {false};
            outputPos = 0;
            for(int col=0;col<4;col++){
                if(grid[row][col] != 0){
                    output[row][outputPos] = grid[row][col];

                    if(outputPos>0 && !didMerge && output[row][outputPos] == output[row][outputPos-1]){
                        output[row][outputPos-1]*=2;
                        output[row][outputPos] = 0;
                        didMerge = true;
                    } else {
                        outputPos++;
                        didMerge = false;
                    }
                }
            }

        }
    } else if(dir==1){
        for(int col=0;col<4;col++){
            bool didMerge {false};
            outputPos = 0;
            for(int row=0;row<4;row++){
                if(grid[row][col] != 0){
                    output[outputPos][col] = grid[row][col];
                    
                    if(outputPos>0 && !didMerge && output[outputPos][col] == output[outputPos-1][col]){
                        output[outputPos-1][col]*=2;
                        output[outputPos][col] = 0;
                        didMerge = true;
                    } else {
                        outputPos++;
                        didMerge = false;
                    }
                }
            }

        }
    } if(dir==2){
        for(int row=0;row<4;row++){
            bool didMerge {false};
            outputPos = 3;
            for(int col=3;col>=0;col--){
                if(grid[row][col] != 0){
                    output[row][outputPos] = grid[row][col];

                    if(outputPos<3 && !didMerge && output[row][outputPos] == output[row][outputPos+1]){
                        output[row][outputPos+1]*=2;
                        output[row][outputPos] = 0;
                        didMerge = true;
                    } else {
                        outputPos--;
                        didMerge = false;
                    }
                }
            }

        }
    } else if(dir==3){
        for(int col=0;col<4;col++){
            bool didMerge {false};
            outputPos = 3;
            for(int row=3;row>=0;row--){
                if(grid[row][col] != 0){
                    
                    output[outputPos][col] = grid[row][col];

                    if(outputPos<3 && !didMerge && output[outputPos][col] == output[outputPos+1][col]){
                        output[outputPos+1][col]*=2;
                        output[outputPos][col] = 0;
                        didMerge = true;
                    } else {
                        outputPos--;
                        didMerge = false;
                    }
                }
            }

        }
    }

    for(int row=0;row<4;row++){
        cout << output[row][0];
        for(int col=1;col<4;col++){
            cout << ' ' << output[row][col];
        }
        cout << '\n';
    }
}