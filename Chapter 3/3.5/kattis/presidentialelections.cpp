#include<cstdio>
#include<vector>
#include<malloc.h>


using namespace std;

int *memo;
int swingStates[2016][2] {};
int nSwing {};
int ub;

int dp(int pos, int delegates){
    if(delegates <= 0){
        return 0;
    }

    if(pos == nSwing){
        return 1000000000;
    }

    auto &curr {memo[pos * ub + delegates]};

    if(curr != -1){
        return curr;
    }
    int v1 {dp(pos+1,delegates)};
    int v2 {dp(pos+1,delegates - swingStates[pos][0])};

    return curr = min(v1,swingStates[pos][1] + v2);

}

int main(){
    int nStates {};
    int targetDelegates {};
    
    int currDelegates {};
    int assuredDelegates {};
    int swingDelegates {};
    int c, f, u;
    scanf("%d\n",&nStates);
    for(int i=0;i<nStates;++i){
        scanf("%d %d %d %d",&currDelegates,&c,&f,&u);
        targetDelegates += currDelegates;

        if(c > f+u){
            //assured win
            assuredDelegates += currDelegates;
        } else if (c+u > f){
            //swing state
            swingDelegates += currDelegates;
            swingStates[nSwing][0] = currDelegates;
            swingStates[nSwing][1] = ((c+f+u)>>1)+1-c;
            ++nSwing;
        }
    }

    targetDelegates >>= 1;
    targetDelegates++;

    if(assuredDelegates >= targetDelegates){
        printf("%d\n",0);
    } else if(assuredDelegates + swingDelegates < targetDelegates){
        printf("impossible\n");
    } else {
        int ub {targetDelegates-assuredDelegates+1};
        memo = (int*)calloc(ub * swingDelegates,sizeof(int));
        printf("%d\n",max(0,dp(0,targetDelegates-assuredDelegates)));
    }

}