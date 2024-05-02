#include<cstdio>

using namespace std;

int main(){
    long n, p, k;
    scanf("%ld %ld %ld\n",&n,&p,&k);
    long prev {0};
    long curr {};
    long currSpeed {100};
    long origLength {};

    //compute for the 
    for(int i=0;i<=n;i++){
        if(i==n){
            curr = k;
        } else {
            scanf("%ld",&curr);
        }

        origLength += (curr-prev)*currSpeed;
        prev = curr;
        currSpeed += p;
    }
    printf("%ld.%02d\n",origLength/100,origLength%100);
}