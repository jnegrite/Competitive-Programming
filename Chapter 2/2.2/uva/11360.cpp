#include<iostream>

using namespace std;

int N;
int grid[10][10] {};

void increase(){
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            if(grid[row][col] == 9){
                grid[row][col] = 0;
            } else {
                grid[row][col]++;
            }
        }
    }
}

void decrease(){
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            if(grid[row][col] == 0){
                grid[row][col] = 9;
            } else {
                grid[row][col]--;
            }
        }
    }
}

void swapRows(int rowA, int rowB){
    int temp;
    for(int i=0;i<N;i++){
        temp = grid[rowA][i];
        grid[rowA][i] = grid[rowB][i];
        grid[rowB][i] = temp;
    }
}

void swapCols(int colA, int colB){
    int temp;
    for(int i=0;i<N;i++){
        temp = grid[i][colA];
        grid[i][colA] = grid[i][colB];
        grid[i][colB] = temp;
    }
}

void transpose(){
    int temp;
    for(int row=0;row<N;row++){
        for(int col=row+1;col<N;col++){
            temp = grid[row][col];
            grid[row][col] = grid[col][row];
            grid[col][row] = temp;
        }
    }
}

int main(){
    int numCases;
    cin >> numCases;
    int numCommands;
    string s;


    for(int tc=1;tc<=numCases;tc++){

        //get data
        cin >> N;
        for(int row=0;row<N;row++){
            cin >> s;
            for(int col=0;col<N;col++){
                grid[row][col] = s.at(col) - '0';
            }
        }

        //get
        int numCommands;
        cin >> numCommands;

        while(numCommands--){
            cin >> s;
            if(s == "row"){
                int rowA, rowB;
                cin >> rowA >> rowB;
                swapRows(rowA-1,rowB-1);
            } else if (s == "col"){
                int colA, colB;
                cin >> colA >> colB;
                swapCols(colA-1,colB-1);
            } else if (s=="inc"){
                increase();
            } else if (s=="dec"){
                decrease();
            } else if (s=="transpose"){
                transpose();
            } else {
                cout << "ERROR\n";
            }
        }

        cout << "Case #" << tc << '\n';
        for(int row=0;row<N;row++){
            for(int col=0;col<N;col++){
                cout << grid[row][col];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}