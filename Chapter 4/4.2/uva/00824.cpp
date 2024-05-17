#include<iostream>

using namespace std;

int grid[3][3];
int currDir {};
int cX, cY;
int x, y, v;

int dirs[8][2] {
    {0,1},
    {-1,1},
    {-1,0},
    {-1,-1},
    {0,-1},
    {1,-1},
    {1,0},
    {1,1}
};

int main(){
    while(true){
        //check first item
        cin >> cX;
        if(cX==-1){
            break;
        }
        cin >> cY >> currDir;

        cX--;
        cY--;

        for(int i=0;i<8;i++){
            cin >> x >> y >> v;
            grid[x-cX][y-cY] = v;
        }

        int actualDir;
        for(int i=5;i<13;i++){
            actualDir = (currDir+i)%8;
            auto pr {dirs[actualDir]};
            if(grid[1+pr[0]][1+pr[1]] == 1){
                break;
            }
        }
        cout << actualDir << '\n';
    }
}