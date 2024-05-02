#include<cstdio>
#include<cstring>

#define LSOne(x) ((x) & -(x))

using namespace std;

int n;
int bannedEdges[16][16] {};
long long memo[16][1<<17] {};

long long dp(int pos, int mask){
    if(mask == 0){
        return (bannedEdges[pos][1] == 1) ? 0 : 1;
    }

    auto &curr {memo[pos][mask]};

    if(curr != -1){
        return curr;
    }

    curr = 0;
    int tMask {mask};
    while(tMask != 0){
        int flag {LSOne(tMask)};
        int target {__builtin_ctz(flag)};

        if(bannedEdges[pos][target] == 0){
            curr += dp(target,mask^flag);
        }
        tMask -= flag;
    }

    return curr;
}


int main(){
    int nCases;
    int k;
    int a, b;
    scanf("%d\n",&nCases);

    for(int tc=1;tc<=nCases;++tc){
        scanf("%d %d\n", &n, &k);
        memset(bannedEdges,0,sizeof(bannedEdges));
        memset(memo,-1,sizeof(memo));

        while(k--){
            scanf("%d %d\n",&a,&b);
            bannedEdges[a][b] = bannedEdges[b][a] = 1;
        }

        int mask{(1<<(n+1))-4};
        long long finAns {0LL}; 
        for(int i=2;i<=n;i++){
            if(bannedEdges[1][i] == 0){
                finAns += dp(i,mask^(1<<i))%9901;
            }
        }
        printf("Case #%d: %lld\n",tc,(finAns>>1)%9901);
    }
}