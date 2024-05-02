#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int coinValues[4] {};
int q;
int coinCounts[4] {};
int target {};

#define INF 1000000000

long long memo[4][100001] {};

long long dp(int idx, int pos){
    if(idx >= 4 || pos < 0){
        return 0LL;
    } else if(pos==0){
        return 1LL;
    }
    
    auto &curr {memo[idx][pos]};
    if(curr != -1){
        return curr;
    }

    return curr = dp(idx,pos-coinValues[idx]) + dp(idx+1,pos);
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);

    while(nCases--){
        for(int i=0;i<4;++i){
            scanf("%d",&coinValues[i]);
        }
        scanf("%d\n",&q);

        memset(memo,-1LL,sizeof(memo));
        while(q--){
            for(int i=0;i<4;++i){
                scanf("%d",&coinCounts[i]);
            }
            scanf("%d\n",&target);
            
            //remove single over layered
            int remover {};
            int temp {};
            long long val {dp(0,target)};
            for(int i=0;i<4;i++){
                temp = coinValues[i] * (coinCounts[i]+1);
                val -= dp(0,target - temp);
                remover += temp;
            }

            //add back double layered
            for(int i=0;i<4;i++){
                for(int j=i+1;j<4;j++){
                    temp = (coinValues[i] * (coinCounts[i]+1)) + (coinValues[j] * (coinCounts[j]+1));
                    val += dp(0, target - temp);
                }
            }

            //remove triple layered
            for(int i=0;i<4;i++){
                temp = coinValues[i] * (coinCounts[i]+1);
                val -= dp(0, target - remover + temp);
            }

            //add back 4x layered
            val += dp(0, target-remover);

            printf("%lld\n",val);
        }
    }
}