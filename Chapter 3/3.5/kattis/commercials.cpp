#include<cstdio>
#include<vector>

using namespace std;

int main(){
    long nBreaks;
    long p;

    scanf("%ld %ld\n",&nBreaks,&p);
    vector<long> vals {};
    long curr;
    vals.assign(nBreaks,-p);
    for(long i=0;i<nBreaks;i++){
        scanf("%ld",&curr);
        vals[i] += curr;
    }

    long bestRev {0};
    long currRev {0};

    for(long val:vals){
        currRev += val;

        bestRev=max(bestRev,currRev);
        
        if(currRev < 0){
            currRev = 0;
        };
    }
    printf("%ld\n",bestRev);
}
