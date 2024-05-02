#include<cstdio>
#include<cstring>

using namespace std;
long long memo[87][2] {};
int nDepth;

long long dp(int pos, int didBranch){
    if (pos == nDepth){
        return 1;
    }

    auto &curr {memo[pos][didBranch]};
    
    if(curr != -1){
        return curr;
    }

    curr = 0;
    if(didBranch == 0){
        curr = dp(pos+1,1);
    } else {
        curr = dp(pos+1,1) + dp(pos+1,0);
    }

    return curr;
}

int main(){
    while(scanf("%d\n",&nDepth), nDepth > 0){
        memset(memo,-1,sizeof(memo));
        printf("%lld\n",dp(1,0));
    }
}