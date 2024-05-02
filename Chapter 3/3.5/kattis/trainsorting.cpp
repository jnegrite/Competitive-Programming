#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    int nValues;
    scanf("%d\n",&nValues);

    long values[2000] {};
    long inc[2000] {};
    long dec[2000] {};

    for(int i=0;i<nValues;i++){
        scanf("%ld\n",&values[i]);
    }

    long L[2000] {};
    //for increasing subsequence
    reverse(values,values+nValues);
    int k=0;
    for(int i=0;i<nValues;i++){
        int pos {lower_bound(L,L+k,values[i]) - L};
        inc[i]=pos;
        L[pos] = values[i];

        if(pos==k){
            ++k;
        }
    }

    k=0;
    for(int i=0;i<nValues;i++){
        int pos {lower_bound(L,L+k,values[i],greater<long>()) - L};
        dec[i]=pos;
        L[pos] = values[i];

        if(pos==k){
            ++k;
        }
    }

    long maxAns {0};
    for(int i=0;i<nValues;i++){
        maxAns = max(maxAns, 1 + inc[i] + dec[i]);
    }
    
    printf("%ld\n",maxAns);

}