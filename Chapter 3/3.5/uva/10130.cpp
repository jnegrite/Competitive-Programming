#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int nObjects;
int objData[1000][2] {};
int memo[1000][30] {};

int dp(int pos, int remWeight){
    if(pos == nObjects || remWeight == 0){
        return 0;
    }

    auto &curr {memo[pos][remWeight]};

    if(curr != -1){
        return curr;
    }

    if(objData[pos][1] > remWeight){
        return curr = dp(pos+1,remWeight);
    } else {
        return curr = max(dp(pos+1,remWeight),objData[pos][0] + dp(pos+1,remWeight-objData[pos][1]));
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    while(nCases--){
        scanf("%d\n",&nObjects);
        for(int i=0;i<nObjects;++i){
            auto &curr {objData[i]};
            scanf("%d %d\n",&curr[0],&curr[1]);
        }
        memset(memo,-1,sizeof(memo));
        int nPeople;
        int weight;
        scanf("%d\n",&nPeople);
        long totalAns {};
        while(nPeople--){
            scanf("%d\n",&weight);
            totalAns += dp(0,weight);
        }
        printf("%ld\n",totalAns);
    }

}