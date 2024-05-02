#include<cstdio>
#include<malloc.h>
#include<cmath>

using namespace std;

int main(){
    int t;
    scanf("%ld",&t);
    unsigned long n, q, a, nActual, curr, maxVal, *values;
    while(t--){
        scanf("%ld %ld\n",&n,&q);
        nActual = 0;
        values = (unsigned long*)malloc(n*sizeof(unsigned long));
        for(unsigned long i=0;i<n;i++){
            scanf("%ld",&curr);
            bool isNew{true};
            for(unsigned long j=0;j<nActual;j++){
                unsigned long resAnd {curr & values[j]};
                if(resAnd==curr){
                    isNew=false;
                } else if(resAnd == values[j]){
                    isNew=false;
                    values[j] = curr;
                }
            }
            if(isNew){
                values[nActual++] = curr;
            }
        }

        for(int i=0;i<q;i++){
            maxVal = 0;
            scanf("%ld\n",&a);
            for(int j=0;j<nActual;j++){
                unsigned long v {a & values[j]};
                if(v>maxVal){
                    maxVal = v;
                }
            }
            printf("%ld\n",maxVal);
        }

        free(values);
    }
}