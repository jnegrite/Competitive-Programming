#include<iostream>
#include<vector>
#include<bitset>
#include<unordered_map>
#include<cmath>

using namespace std;
using uli = unordered_map<long,int>;

vector<int> primes {};

void generatePrimes() {
    const int MAXVAL = 1000;
    bitset<MAXVAL + 1> isPrime;

    primes.clear();
    isPrime.set(); // Set all bits to true
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAXVAL; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAXVAL; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

uli primeFactorize(long value) {
    uli factors;
    for (int prime : primes) {
        if (prime * prime > value) {
            break;
        }
        while (value % prime == 0) {
            factors[prime]++;
            value /= prime;
        }
    }
    if (value > 1) {
        factors[value] = 1;
    }
    return factors;
}

int main() {
    generatePrimes();
    int nValues;
    long value;
    cin >> nValues;
    vector<uli> primeFactors {};

    uli globalFactors {};
    uli commonFactors {};

    for(int i=0;i<nValues;++i){
        cin >> value;
        uli pf {primeFactorize(value)};
        primeFactors.push_back(pf);
        for(auto pr: pf){
            if(globalFactors.find(pr.first) == globalFactors.end()){
                globalFactors[pr.first] = 0;
            }
            globalFactors[pr.first] += pr.second;
        }
    }

    //summarize final factors
    long gcd {1};
    for(auto pr: globalFactors){
        int minVal = pr.second/nValues;
        if(minVal >= 1){
            commonFactors[pr.first]=minVal;
            for(int i=0;i<minVal;++i){
                gcd *= pr.first;
            }
        }
    }

    //evaluate current factors to check how much they need
    int nMoves {0};
    for(uli pf: primeFactors){
        //check with every common factor
        for(auto pr: commonFactors){
            int need {pr.second - pf[pr.first]};
            if( need > 0){
                nMoves += need;
            }
        }
    }

    cout << gcd << ' ' << nMoves << '\n';
    
}