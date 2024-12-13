#include<iostream>
#include<bitset>

using namespace std;

int main(){
    long n, k;
    cin >> n >> k;
    bitset<100001> isPrime {};
    isPrime.set();
    
    long ans {};
    long nCrossed {};
    for(long p=2;p<=n, nCrossed<k;++p){
        if(!isPrime.test(p)){
            continue;
        }

        for(long val=p;val<=n && nCrossed<k;val+=p){
            if(isPrime.test(val)){
                isPrime.reset(val);
                if(++nCrossed == k){
                    ans = val;
                }
            }
            
            if(val==p){
                val = (val * (val-1));
            }
        }
    }
    cout << ans << '\n';
}