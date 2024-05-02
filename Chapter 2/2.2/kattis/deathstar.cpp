#include<iostream>
#include<malloc.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    long **grid = (long**)malloc(N * sizeof(long*));
    long values[1000] {};
    for(int row=0;row<N;row++){
        grid[row] = (long*)malloc(N * sizeof(long));
        for(int col=0;col<N;col++){
            cin >> grid[row][col];
        }
    }

    for(int row=0;row<N;row++){
        for(int col=row+1;col<N;col++){
            values[row] |= grid[row][col];
            values[col] |= grid[row][col];
        }
        free(grid[row]);
    }
    free(grid);
    
    cout << values[0];
    for(int i=1;i<N;i++){
        cout << ' ' << values[i];
    }
    cout << '\n';
}