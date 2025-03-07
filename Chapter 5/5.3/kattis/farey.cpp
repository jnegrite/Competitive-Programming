#include<iostream>
#include<vector>
#include<bitset>

using namespace std;
const long MAXVAL = 10000;
vector<long> primes {};

void generatePrimes(){
    bitset<MAXVAL+1> isPrime {};
    isPrime.set();

    for(long i=2;i<=MAXVAL;++i){
        if(isPrime.test(i)){
            primes.push_back(i);
            for(long j=i*i;j<=MAXVAL;j+=i){
                isPrime.reset(j);
            }
        }
    }
}

int main(){
    generatePrimes();

    vector<long> eulerPhi(MAXVAL+1,0);
    for(long i=1;i<=MAXVAL;++i){
        eulerPhi[i] = i;
    }

    eulerPhi[1]++;
    for(long i=2;i<=MAXVAL;++i){
        if(eulerPhi[i] == i){
            for(long j=i; j<=MAXVAL; j+=i){
                eulerPhi[j] = (eulerPhi[j]/i) * (i-1);
            }
        }
        eulerPhi[i] += eulerPhi[i-1];
    }

    int nCases;
    cin >> nCases;
    int dNum, val;
    while(nCases--){
        cin >> dNum >> val;
        cout << dNum << ' ' << eulerPhi[val] << '\n';
    }
}