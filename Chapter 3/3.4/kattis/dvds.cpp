#include<cstdio>

using namespace std;

int main(){
    long nCases, nDVDs;
    long target, curr;

    scanf("%ld\n",&nCases);
    while(nCases--){
        scanf("%ld\n",&nDVDs);
        target = 1;
        for(long i=0;i<nDVDs;++i){
            scanf("%ld",&curr);
            if(curr == target){
                ++target;
            }
        }
        printf("%ld\n",nDVDs + 1 - target);
    }
}