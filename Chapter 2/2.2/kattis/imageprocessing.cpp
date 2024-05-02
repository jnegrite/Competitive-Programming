#include<iostream>

using namespace std;

int main(){
    int H, W, N, M, rH, rW;

    cin >> H >> W >> N >> M;

    rH = H-N+1;
    rW = W-M+1;
    auto *grid = new long[H][20];
    auto *kernel = new long[N][20];
    auto *output = new long[rH][20];

    //get data
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> kernel[i][j];
        }
    }
    
    //perform computation
    for(int row=0;row<rH;row++){
        for(int col=0;col<rW;col++){
            output[row][col] = 0;
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    output[row][col] += grid[row+i][col+j] * kernel[N-1-i][M-1-j];
                }
            }
        }
    }

    //print output
    for(int i=0;i<rH;i++){
        cout << output[i][0];
        for(int j=1;j<rW;j++){
            cout << ' ' << output[i][j];
        }
        cout << '\n';
    }

}