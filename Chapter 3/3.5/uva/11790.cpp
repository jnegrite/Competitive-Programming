#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
    int nCases;
    long nValues;
    scanf("%d\n",&nCases);
    long heights[10000] {};
    long widths[10000] {};

    long LIS[10000]{};
    long LDS[10000];
    long k;
    for(int tc=1;tc<=nCases;++tc){
        //get data
        scanf("%ld\n",&nValues);
        for(long i=0;i<nValues;++i){
            scanf("%ld",&heights[i]);
        }
        for(long i=0;i<nValues;++i){
            scanf("%ld",&widths[i]);
        }

        
        long bestForward {};
        long bestBackward {};
        memset(LIS,0,sizeof(LIS));
        memset(LDS,0,sizeof(LDS));
        for(long i=0;i<nValues;++i){
            for(long j=0;j<i;++j){
                //longest increasing sub
                if(heights[j] < heights[i] && LIS[j] > LIS[i]){
                    LIS[i] = LIS[j];
                }
                //longest decreasing sub
                if(heights[j] > heights[i] && LDS[j] > LDS[i]){
                    LDS[i] = LDS[j];
                }

            }

            LIS[i] += widths[i];
            LDS[i] += widths[i];

            if(LIS[i]>bestForward){
                bestForward = LIS[i];
            }

            if(LDS[i] > bestBackward){
                bestBackward = LDS[i];
            }
        }

        printf("Case %d. ",tc);
        if(bestForward >= bestBackward){
            printf("Increasing (%ld). Decreasing (%ld).\n",bestForward,bestBackward);
        } else {
            printf("Decreasing (%ld). Increasing (%ld).\n",bestBackward,bestForward);
        }
    }
}