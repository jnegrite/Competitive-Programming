#include<cstdio>
#include<cstring>

using namespace std;

long memo[31] {};

int dp(int pos){

    auto &curr {memo[pos]};

    if(curr != -1){
        return curr;
    }

    curr = 0;

    if(pos == 0){
        curr = 1;
    } else if(pos == 1){
        curr = dp(pos-1);
    } else {
        curr = dp(pos-1) + 2*dp(pos-2);
    }

    return curr;
}

int main(){
    memset(memo,-1,sizeof(memo));

    int val;
    int nCases;

    scanf("%d\n",&nCases);
    while(nCases--){
        scanf("%d\n",&val);

        long ans = dp(val); //number of valid combinations
        long diff; // number of symmetric combinations
        if(val%2 == 0){
            diff = 2*dp((val/2)-1) + dp(val/2);
        } else {
            diff = dp(val/2);
        }

        printf("%ld\n",diff + (ans-diff)/2);
    }
}