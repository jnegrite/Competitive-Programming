#include<cstdio>
#include<cmath>
using namespace std;

void process(long value, long &from, long &to){
    long nTerms {1+static_cast<long>(sqrt(2*value))};
    for(;nTerms >= 1;nTerms--){
        if(nTerms%2==1){
            //if divisible
            if(value%nTerms==0){
                long mid {value/nTerms};
                long span {nTerms/2};
                from = mid-span;
                to = mid+span;
                if(from > 0){
                    return;
                }
            }
        } else {
            if(value%nTerms==(nTerms>>1)){
                to = (2*value/nTerms + nTerms)>>1;
                from = to - nTerms + 1;
                if(from > 0){
                    return;
                }
            }
        }
    }
}


int main(){
    long num, front, back;
    while(scanf("%ld\n",&num), num != -1){
        process(num,front,back);
        printf("%ld = %ld + ... + %ld\n",num,front,back);
    }
}