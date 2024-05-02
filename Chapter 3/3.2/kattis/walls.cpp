#include<iostream>
#include<vector>

using namespace std;
int l, w, n, r;
long maxDist;
int walls[4][2] {};
vector<int> cranes {};
int currCovered {0};
int minCranes {0};
int currCranes {0};


void backtrack(int pos){
    if(pos == cranes.size()){
        if(currCovered == 15 && (minCranes == 0 || currCranes < minCranes)){
            minCranes = currCranes;
        }
        return;
    }

    backtrack(pos+1);

    if((currCovered | cranes[pos]) != currCovered){
        int prevCovered = currCovered;
        
        currCovered |= cranes[pos];
        currCranes++;
        backtrack(pos+1);
        currCranes--;
        currCovered = prevCovered;
    }
}

int main(){
    cin >> l >> w >> n >> r;
    r <<= 1;

    maxDist = r*r;
    walls[0][0] = -l;
    walls[1][0] = l;
    walls[2][1] = -w;
    walls[3][1] = w;

    int covered {};
    int configs {};

    int row, col;
    int dRow, dCol;
    while(n--){
        cin >> row >> col;
        row <<= 1;
        col <<= 1;
        
        //check per wall
        int mask {0};
        for(int i=0;i<4;i++){
            dRow = row - walls[i][0];
            dCol = col - walls[i][1];

            if(dRow * dRow + dCol * dCol <= maxDist){
                mask |= (1<<i);
            }
        }

        //only process if crane can reach a wall and is unique
        if(mask != 0 && (configs & (1<<mask))==0){
            covered |= mask;
            configs |= (1<<mask);
            cranes.push_back(mask);
        }
    }

    if(covered != 15) {
        cout << "Impossible\n";
    } else {
        currCranes = 0;
        minCranes = 0;
        backtrack(0);
        cout << minCranes << '\n';
    }
}