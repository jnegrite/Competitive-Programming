#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

long memo[40][80001]{};
long long flags[2] {};
long values[40] {};
long n, f;

long dp(long pos, long val){
    if(pos == n){
        if(val==40000){
            return 1;
        } else {
            return 0;
        }
    }
    
    auto &curr {memo[pos][val]};
    
    if(curr!=-1){
        return curr;
    }

    long v1 {dp(pos+1, val+values[pos])};
    long v2 {dp(pos+1, val-values[pos])};
    
    if(v1==1){
        flags[0] |= (1LL<<pos);
    }

    if(v2==1){
        flags[1] |= (1LL<<pos);
    }

    return curr = max(v1,v2);

}

int main(){
    while(scanf("%ld %ld\n",&n,&f),n!=0 || f!=0){
        flags[0] = flags[1] = 0;
        memset(memo,-1,sizeof(memo));
        for(long i=0;i<n;i++){
            scanf("%ld\n",&values[i]);
        }
        
        long long vFlag {(1<<n)-1};
        if(dp(0,40000+f)==0){
            printf("*\n");
        } else {
            for(long i=0;i<n;i++){
                long long mask {1LL<<i};
                if((flags[0] & flags[1] & mask)> 0){
                    printf("?");
                } else if((flags[1] & mask) > 0){
                    printf("+");
                } else if((flags[0] & mask) > 0){
                    printf("-");
                } else {
                    printf("X");
                }
            }
            printf("\n");
        }
    }
}