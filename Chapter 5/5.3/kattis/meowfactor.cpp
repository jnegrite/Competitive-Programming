#include<iostream>
#include<unordered_map>
#include <vector>

using namespace std;

vector<int> primes {};

vector<int> generatePrimes() {
    const int N = 200;
    primes.clear();
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int primeFactorize(long long value) {
    int ans {1};

    for(int i=0;i<primes.size();++i){
        int nFactors {};
        int curr {primes[i]};

        if(value < curr){
            break;
        }
        while(value % curr == 0){
            value/=curr;
            ++nFactors;
        }
        nFactors/=9;
        for(int j=0;j<nFactors;++j){
            ans *= curr;
        }
    }
    return ans;
}

int main(){
    long long value;
    
    generatePrimes();
    
    cin >> value;

    cout << primeFactorize(value) << '\n';
}