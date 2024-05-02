#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
const int  maxDim = 100001;

int p[maxDim] {};
int climbCost[maxDim] {};

int memo[maxDim] {};
int n, f;
int a, b, c;
int totalCost {};

int dp(int pos){
    if(pos == 1){
        return 0;
    }

    auto &curr {memo[pos]};

    if(curr != -1){
        return curr;
    }

    totalCost += climbCost[pos];
    return curr = climbCost[pos] + dp(p[pos]);
}

int main(){
    while(scanf("%d %d\n",&n,&f)!=EOF){
        memset(memo,-1,sizeof(memo));
        for(int i=1;i<n;++i){
            scanf("%d %d %d\n",&a,&b,&c);
            p[b] = a;
            climbCost[b] = c;
        }

        totalCost = 0;
        int deepest {0};
        //set nodes to be visited
        for(int i=0;i<f;++i){
            scanf("%d",&c);
            deepest = max(deepest,dp(c));
        }

        //do dp
        printf("%d\n",totalCost - deepest);
    }
}