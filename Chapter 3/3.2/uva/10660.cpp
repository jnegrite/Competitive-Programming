#include<cstdio>
#include<iostream>

#define LSOne(x) ((x) & (-x))

using namespace std;

long costs[5][5] {};
int positions[5][2] {};
long isUsed{};
long minCost;
long currCost;
long bestConfig{};
int prevPos{-1};

long getCost(){
    long totalCost{};

    for(int row=0;row<5;++row){
        for(int col=0;col<5;++col){
            int nearest {8};
            for(int i=0;nearest>0 && i<5;++i){
                int curr {abs(row-positions[i][0]) + abs(col-positions[i][1])};
                nearest = min(nearest,curr);
            }

            totalCost += costs[row][col] * nearest;
        }
    }
    return totalCost;
}

void backtrack(int pos){
    if(pos==5){

        long currCost {getCost()};
        if(isUsed==31 || currCost<minCost){
            minCost=currCost;
            bestConfig = isUsed;
        }

        return;
    }
    
    for(int i=prevPos+1;i<25;i++){
        int cachePrev {prevPos};

        isUsed ^= (1<<i);
        prevPos = i;
        positions[pos][0] = i/5;
        positions[pos][1] = i%5;

        backtrack(pos+1);

        prevPos = cachePrev;
        isUsed ^= (1<<i);
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    while(nCases--){

        //clear data
        for(int row=0;row<5;++row){
            for(int col=0;col<5;++col){
                costs[row][col] = 0;
            }
        }
        isUsed = 0;

        int nData;
        scanf("%d\n",&nData);
        
        int row, col;
        while(nData--){
            scanf("%d %d ",&row,&col);
            scanf("%ld\n",&costs[row][col]);
        }

        backtrack(0);

        int pos = __builtin_ctz(bestConfig);
        printf("%d", pos);
        bestConfig -= (1<<pos);

        for(int i=0;i<4;i++){
            pos = __builtin_ctz(bestConfig);
            printf(" %d",pos);
            bestConfig -= (1<<pos);
        }
        printf("\n");
    }


}