#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int memo[101][30001] {};
int coins[100] {};
int nCoins {};

int main(){
    int nCases;
    scanf("%d",&nCases);
    while(nCases--){
        memset(memo,0,sizeof(memo));
        int bill;
        scanf("%d",&bill);
        scanf("%d",&nCoins);
        for(int i=0;i<nCoins;++i){
            scanf("%d",&coins[i]);
        }

        int currMax {0};
        
        memo[0][0] = 1;
        //go through all values
        for(int pos=0;pos<nCoins;++pos){
            for(int i=0;i<=currMax;++i){
                auto &currVal {memo[pos][i]};
                if(currVal != 0){
                    //not use
                    auto &target1 {memo[pos+1][i]};
                    if(target1 == 0 || target1 > currVal){
                        target1 = currVal;
                    }

                    //use
                    if(i+coins[pos] <= 20001){
                        auto &target2 {memo[pos+1][i+coins[pos]]};
                        if((target2 == 0) || (target2 > currVal+1)){
                            target2 = currVal +1;
                        }
                    }
                }
            }
            currMax += coins[pos];
            currMax = min(currMax,20001);
        }

        //check upwards
        while(memo[nCoins][bill] <= 1){
            ++bill;
        }
        printf("%d %d\n", bill, memo[nCoins][bill]-1);
    }
}
