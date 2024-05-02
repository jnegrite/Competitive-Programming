#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int N, x, T, K;
int favorValues[100] {};
int prices[100] {};
int memo[100][1000][20] {};
int px;

int dp(int pos, int budget, int remDishes){
    if(pos==K || budget == 0 || remDishes == 0){
        return 0;
    }

    auto &curr {memo[pos][budget][remDishes]};
    if(curr != -1){
        return curr;
    }

    curr = dp(pos+1,budget,remDishes);
    for(int i=1;i<=2 && i<=remDishes && prices[pos]*i<=budget;++i){
        curr = max(curr,favorValues[pos]*i + dp(pos+1,budget-i*prices[pos],remDishes-i));
    }
    return curr;
}

int main(){
    while(scanf("%d %d %d %d",&N,&x,&T,&K),N!=0 || x!=0 || T!=0 || K!=0){
        memset(prices,0,sizeof(prices));
        memset(favorValues,0,sizeof(favorValues));
        memset(memo,-1,sizeof(memo));

        for(int i=0;i<K;++i){
            scanf("%d",&prices[i]);
            for(int j=0;j<=N;j++){
                scanf("%d",&px);
                favorValues[i] += px;
            }     
        }
        int maxBudget = (((N+1) * x * 10)/11) - (T*(N+1));

        double maxFavor {0};
        if (maxBudget > 0){
           maxFavor = dp(0,maxBudget,2*(N+1));
        }
        printf("%.02lf\n",maxFavor/(N+1));
    }
}