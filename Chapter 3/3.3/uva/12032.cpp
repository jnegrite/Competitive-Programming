#include<cstdio>
#include<malloc.h>

using namespace std;

long *rungs;
long nRungs;

bool testK(long k){
    for(int i=0;i<nRungs;++i){
        if(rungs[i] == k){
            --k;
        } else if (rungs[i]>k){
            return false;
        }
    }
    return true;
}


int main(){
    int nCases;
    scanf("%d\n",&nCases);
    for(int tc=1;tc<=nCases;++tc){
        scanf("%ld\n",&nRungs);
        rungs = (long*)malloc(nRungs*sizeof(long));

        //get data
        rungs[0] = 0;
        long curr, prev;
        prev = 0;
        for(long i=0;i<nRungs;++i){
            scanf("%ld\n",&curr);
            rungs[i] = curr-prev;
            prev = curr;
        }

        long low {0};
        long high {curr};
        long mid;
        while(low<high){
            mid = (low+high)>>1;
            if(testK(mid)){
                high = mid;
            } else {
                low = mid+1;
            }
        }

        printf("Case %d: %ld\n",tc,low);
        free(rungs);
    }
}