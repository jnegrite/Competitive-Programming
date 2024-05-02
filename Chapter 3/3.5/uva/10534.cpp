#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    long n;
    long A[10000] {};
    long L[10000] {};
    long lsFront[10000] {};
    long lsBack[10000] {};
    long bestSeq {0};

    while(scanf("%ld\n",&n)!=EOF){
        //get data
        for(long i=0;i<n;++i){
            scanf("%ld",&A[i]);
        }

        bestSeq = 1;
        //processs front
        long k=0;
        for(long i=0;i<n;++i){
            lsFront[i] = lower_bound(L,L+k,A[i])-L;
            L[lsFront[i]] = A[i];
            if(lsFront[i] == k){
                ++k;
            }
        }

        //processs reverse
        k=0;
        reverse(A,A+n);
        for(long i=0;i<n;++i){
            const long &pos {lsBack[i] = lower_bound(L,L+k,A[i])-L};
            L[pos] = A[i];
            if(pos == k){
                ++k;
            }
        }

        reverse(lsBack,lsBack+n);
        for(long i=0;i<n;++i){
            bestSeq = max(bestSeq,1+((min(lsFront[i],lsBack[i]))<<1));
        }
        printf("%ld\n",bestSeq);
    }
}