#include<iostream>
#include<vector>
#include<bitset>

using namespace std;
const long long MAXVAL = 4000001;
vector<long long> primes {};

void generatePrimes(){
    bitset<MAXVAL+1> isPrime {};
    isPrime.set();

    for(long long i=2;i<=MAXVAL;++i){
        if(isPrime.test(i)){
            primes.push_back(i);
            for(long long j=i*i;j<=MAXVAL;j+=i){
                isPrime.reset(j);
            }
        }
    }
}

int main(){
    generatePrimes();

    vector<long long> eulerPhi(MAXVAL+1,0);
    for(long long i=1;i<=MAXVAL;++i){
        eulerPhi[i] = i;
    }

    for(long long i=2;i<=MAXVAL;++i){
        if(eulerPhi[i] == i){
            for(long long j=i; j<=MAXVAL; j+=i){
                eulerPhi[j] = (eulerPhi[j]/i) * (i-1);
            }
        }
    }

    vector<long long> sums(MAXVAL+1,0);
    for(long long i=2;i<=MAXVAL;++i){
        long long val {eulerPhi[i]};
        for(long long j=i,currVal=val;j<=MAXVAL;j+=i,currVal+=val){
            sums[j] += currVal;
        }
    }

    for(long long i=2;i<=MAXVAL;++i){
        sums[i] += sums[i-1];
    }

    long long currVal;
    while(cin >> currVal, currVal != 0){
        cout << sums[currVal] << '\n';
    }
}