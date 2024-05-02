#include<cstdio>
#include<cstring>
#include<iostream>

#define INF 1000000

int coinVals[9] {};
int memo[100001] {};

int dp(int pos){
    if( pos < 0){
        return INF;
    } else if(pos == 0){
        return 0;
    }

    auto &curr {memo[pos]};

    if(curr != -1){
        return curr;
    }

    curr = INF;
    for(int i=1;i<=8;++i){
        curr = std::min(curr,dp(pos-coinVals[i]));
    }

    if(curr >= INF){
        return curr;
    } else {
        return ++curr;
    }

}
int main(){
    memset(memo,-1,sizeof(memo));
    coinVals[0] = 1;
    for(int i=1;i<=8;i++){
        coinVals[i] = coinVals[i-1] * i;
        memo[coinVals[i]] = 1;
    }

    int curr;
    while(scanf("%d\n",&curr)!=EOF){
        printf("%d\n",dp(curr));
    }    
}