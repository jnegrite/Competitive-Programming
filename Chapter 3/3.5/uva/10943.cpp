#include<cstdio>
#include<cstring>

using namespace std;

long memo[101][101] {};

long dp(long n, long k){
    if(n < 0){
        return 0;
    }

    if(n==0 || k==1){
        return 1;
    }

    long &ans {memo[n][k]};
    if(ans!=-1){
        return ans;
    }

    ans = 0;
    for(int i=0;i<=n;i++){
        ans += dp(n-i,k-1);
        ans %= 1000000;
    }
    return ans;
}


int main(){
    int n, k;
    while(scanf("%d %d\n", &n, &k),n!=0 || k!=0){
        memset(memo,-1,sizeof(memo));

        printf("%ld\n",dp(n,k));

    }
}