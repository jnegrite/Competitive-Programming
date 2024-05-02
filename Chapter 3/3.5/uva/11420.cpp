#include<cstdio>
#include<cstring>

using namespace std;

int n, s;

long long memo[2][66][66] {};

long long dp(int prev, int pos, int nLocked){
    if(nLocked == 0){
        return prev==0;
    }

    if(pos == 0){
        return nLocked == 1 && prev == 1;
    }

    auto &curr {memo[prev][pos][nLocked]};

    if(curr != -1){
        return curr;
    }
    long long v1 {dp(1,pos-1,nLocked-prev)};
    long long v2 {dp(0,pos-1,nLocked)};
    return curr = v1 + v2;

}

int main(){
    memset(memo,-1,sizeof(memo));
    while(scanf("%d %d\n",&n, &s), n> 0 && s >= 0){
        printf("%lld\n",dp(0,n,s));
    }
}