#include<cstdio>
#include<malloc.h>

using namespace std;

long nValues;
long *values;

int main(){
    while(scanf("%ld\n",&nValues),nValues!=0){
        values = (long*)malloc(nValues*sizeof(long));
        for(long i=0;i<nValues;i++){
            scanf("%ld",&values[i]);
        }
        
        long maxSum {-1};
        long currSum {0};
    
        for(long i=0;i<nValues;++i){
            currSum += values[i];

            if(currSum < 0){
                currSum = 0;
            } else if(currSum > maxSum){
                maxSum = currSum;
            }
        }
        
        if(maxSum <= 0){
            printf("Losing streak.\n");
        } else {
            printf("The maximum winning streak is %ld.\n", maxSum);
        }

        free(values);
    }
}