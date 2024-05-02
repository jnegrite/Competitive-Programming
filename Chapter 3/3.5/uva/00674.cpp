#include<cstdio>
#include<cstring>

using namespace std;

int coins[5] {50,25,10,5,1};

long memo[5][7490] {};

long dp(int pos, int val){
    if(val == 0){
        return 1;
    }

    if(pos == 5 || val < 0){
        return 0;
    }

    auto &curr {memo[pos][val]};
    
    if(curr != -1){
        return curr;
    }
    
    return curr = dp(pos,val-coins[pos]) + dp(pos+1,val);
}

int main(){
    memset(memo,-1,sizeof(memo));
    int val;
    while(scanf("%d\n",&val)!=EOF){
        printf("%ld\n",dp(0,val));
    }
}