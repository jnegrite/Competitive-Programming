#include<cstdio>
#include<queue>
using namespace std;

int memo[15][15][8] {};
int ans[15] {};

int dX[6] {-1,-1,0,0,1,1};
int dY[6] {-1,0,-1,1,0,1};

struct State {
    int x {};
    int y {};
    int level {};

    State(int _x, int _y, int _level){
        x=_x;
        y=_y;
        level=_level;
    }
};

int main(){

    int tX, tY;
    //initialize grid
    memo[7][7][0] = 1;

    queue<State> q {};
    q.emplace(7,7,0);

    while(!q.empty()){
        State curr {q.front()};
        q.pop();
        
        int &currVal {memo[curr.x][curr.y][curr.level]};
        ans[curr.level*2] += (currVal*currVal);
        if(curr.level > 0){
            ans[curr.level*2-1] += currVal * memo[curr.x][curr.y][curr.level-1];
        }

        if(curr.level < 7){
            int nxtLevel = curr.level+1;
            for(int dir=0;dir<6;++dir){
                tX = curr.x + dX[dir];
                tY = curr.y + dY[dir];

                if(memo[tX][tY][nxtLevel] == 0){
                    q.emplace(tX, tY, nxtLevel);
                }
                memo[tX][tY][nxtLevel] += currVal;
            }
        }
    }

    int nCases, val;
    scanf("%d",&nCases);
    while(nCases--){
        scanf("%d",&val);
        printf("%d\n",ans[val]);
    }
}