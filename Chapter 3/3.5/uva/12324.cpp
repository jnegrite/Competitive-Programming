#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
int n;
int memo[101][101] {};
int df[101][2] {};

int dp(int pos, int sphere){
    if(pos == n){
        return 0;
    }

    sphere = min(n,sphere);

    auto &curr {memo[pos][sphere]};

    if(curr != -1){
        return curr;
    }

    curr = 0;
    int dur {df[pos][0]};
    if(sphere > 0){
        //if has sphere, choose whether to use it or not
        curr = min(dur + dp(pos+1,sphere+df[pos][1]), dur/2 + dp(pos+1,sphere+df[pos][1]-1));
    } else {
        curr = dur + dp(pos+1,df[pos][1]);
    }
    return curr;
}

int main(){
    while(scanf("%d\n",&n),n>0){
        for(int i=0;i<n;i++){
            scanf("%d %d\n",&df[i][0],&df[i][1]);
        }

        memset(memo,-1,sizeof(memo));
        printf("%d\n",dp(0,0));
    }
}