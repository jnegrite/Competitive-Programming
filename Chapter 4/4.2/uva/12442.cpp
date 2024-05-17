#include<cstdio>
#include<cstring>

#define LEN 50001
using namespace std;

int sendTo[LEN] {};
int depth[LEN] {};
int tempDepth[LEN] {};
int loopDepth {};
int loopCounter;

int getDepth(int pos, int seed){

    //check if value exists in actual
    if(depth[pos] != -1){
        return depth[pos]; 
    }

    //check if already has value in temp
    if(tempDepth[pos] != -1){
        loopCounter = loopDepth = seed - tempDepth[pos];
        return depth[pos] = loopDepth;
    }

    //if not, mark and pass on to next
    tempDepth[pos] = seed;
    loopDepth = getDepth(sendTo[pos],seed+1);

    //mark final value
    if(loopCounter>0){
        loopCounter--;
        return depth[pos] = loopDepth;
    } else {
        return depth[pos] = loopDepth+1;
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    for(int tc=1;tc<=nCases;++tc){
        int nPeople;
        scanf("%d\n",&nPeople);
        memset(depth,-1,sizeof(depth));
        
        int a, b;
        for(int i=0;i<nPeople;++i){
            scanf("%d %d\n",&a,&b);
            sendTo[a] = b;
        }

        //checking the loops
        int bestLoop {};
        int bestStart {};
        for(int i=1;i<=nPeople;++i){
            if(depth[i]==-1){
                memset(tempDepth,-1,sizeof(tempDepth));
                getDepth(i,0);

                if(depth[i] > bestLoop){
                    bestLoop = depth[i];
                    bestStart = i;
                }
            }
        }

        printf("Case %d: %d\n",tc,bestStart);

    }
}