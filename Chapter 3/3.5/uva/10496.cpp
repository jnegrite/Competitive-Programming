#include<cstdio>
#include<cstring>
#include<iostream>

#define LSOne(x) ((x) & (-x))
#define INF 1000000000

using namespace std;

int memo[11][1<<22] {};

int beepers[11][2] {};
int dist[11][11] {};
int rows, cols;
int nBeepers;

int dp(int pos, long mask){
    if(mask==0){
        return dist[0][pos];
    }

    auto &curr {memo[pos][mask]};
    if(curr!=-1){
        return curr;
    }

    curr = INF;
    long tempMask {mask};
    while(tempMask!=0){
        long flag {LSOne(tempMask)};
        int target {__builtin_ctz(flag)+1};
        curr = min(curr, dist[pos][target] + dp(target,mask ^ flag));
        tempMask -= flag;
    }
    return curr;
}

int main(){
    int nScenarios;
    scanf("%d\n",&nScenarios);
    while(nScenarios--){
        scanf("%d %d\n",&rows,&cols);
        scanf("%d %d\n",&beepers[0][0],&beepers[0][1]);
        scanf("%d\n",&nBeepers);

        for(int i=1;i<=nBeepers;++i){
            scanf("%d %d\n",&beepers[i][0],&beepers[i][1]);
        }

        //get distances
        for(int i=0;i<=nBeepers;++i){
            dist[i][i] = 0;
            for(int j=i+1;j<=nBeepers;++j){
                dist[i][j] = dist[j][i] =
                    abs(beepers[i][0] - beepers[j][0]) + abs(beepers[i][1] - beepers[j][1]);
            }
        }

        //initialize traveling salesman
        memset(memo,-1,sizeof(memo));
        int ans {dp(0,(1L<<nBeepers)-1L)};
        printf("The shortest path has length %d\n",ans);
    }
}
