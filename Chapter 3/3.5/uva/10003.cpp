#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

long memo[52][52] {};
int cuts[52];
int nCuts;

long getCost(int from, int to){
    if(from+1 == to){
        return 0;
    }

    long &ans {memo[from][to]};

    if(ans != -1){
        return ans;
    }

    //base case
    ans = getCost(from,from+1) + getCost(from+1,to);
    for(int i=from+2;i<to;i++){
        ans = min(ans, getCost(from,i) + getCost(i,to));
    }
    ans += cuts[to] - cuts[from];
    return ans;
}

int main(){
    int len;
    while(scanf("%d\n",&len),len!=0){
        cuts[0] = 0;

        scanf("%d\n",&nCuts);
        int curr;

        for(int i=1;i<=nCuts;++i){
            scanf("%d",&cuts[i]);
        }
        cuts[nCuts+1] = len;
        
        memset(memo,-1,sizeof(memo));
        printf("The minimum cutting is %ld.\n",getCost(0,nCuts+1));
    }
}