#include<iostream>
#include<vector>
#include<bitset>

using namespace std;
const long MAXVAL = 100000000;

bitset<MAXVAL+1> isPrime {};

int main(){
    //generate the sieve
    isPrime.set();

    isPrime.reset(1);
    isPrime.reset(0);

    for(long long i=4;i<=MAXVAL;i+=2){
        isPrime.reset(i);
    }

    for(long long i=3;i<=MAXVAL;i+=2){
        if(!isPrime.test(i)){
            continue;
        }
        long long increment {i<<1};
        for(long long j=i*i;j<=MAXVAL;j+=increment){
            isPrime.reset(j);
        }
    }

    long n, q;
    cin >> n >> q;

    //check count of prime
    long cntPrime {0};
    for(int i=2;i<=n;++i){
        if(isPrime.test(i)){
            ++cntPrime;
        }
    }

    cout << cntPrime << '\n';

    for(int i=0;i<q;++i){
        cin >> n;
        cout << static_cast<int>(isPrime.test(n)) << '\n';
    }

}
