#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#include<malloc.h>

using namespace std;

long items[101] {};
long nItems {};
long nOrders {};
long finAmount {};
long ub{};
long *memo;

long dp(long pos, long amount, stack<long> &finOrders){
    if(amount == 0){
        return 1;
    }
    
    if(pos >= nItems || amount < 0){
        return 0;
    }

    long &curr {memo[pos * ub + amount]};

    if(curr != 0){
        return curr - 1;
    }

    if(amount < items[pos]){
        curr = dp(pos+1,amount,finOrders);
    } else {
        curr = dp(pos,amount-items[pos],finOrders);
        if(curr > 1){
            return curr;
        }
        if(curr == 1){
            finOrders.push(pos);
        }
        curr += dp(pos+1,amount,finOrders);
    }
    return curr++;
}

int main(){
    scanf("%ld\n",&nItems);
    nItems++;
    for(long i=1;i<nItems;i++){
        scanf("%ld", &items[i]);
    }
    scanf("%ld\n",&nOrders);
    while(nOrders--){

        stack<long> finOrders {};
        scanf("%ld",&finAmount);
        ub = finAmount+1;
        memo = (long *)calloc(nItems * ub,sizeof(long));
        long val {dp(1,finAmount, finOrders)};
        switch(val){
            case 0:
                printf("Impossible\n");
                break;
            case 1:
                if(!finOrders.empty()){
                    printf("%ld",finOrders.top());
                    finOrders.pop();
                }
                while(!finOrders.empty()){
                    printf(" %ld",finOrders.top());
                    finOrders.pop(); 
                }
                printf("\n");
                break;
            default:
                printf("Ambiguous\n");
        }
        free(memo);
    }
}