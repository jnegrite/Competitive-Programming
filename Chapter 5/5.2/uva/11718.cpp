#include<iostream>

using namespace std;

int n, k, mod;
long long val;
long long valSum;

long long power(long long base, long long exponent){
    if(exponent == 0){
        return 1;
    } else if (exponent%2 == 0){
        long long temp = (base * base)%mod;
        return power(temp, exponent>>1);
    } else {
        long long temp = power(base,exponent-1);
        temp %= mod;
        temp *= base;
        return temp%mod;
    }
}

int main(){
    int nCases;
    cin >> nCases;
    
    for(int tc=1;tc<=nCases;++tc){
        cin >> n >> k >> mod;
        valSum = 0;
        for(int i=0;i<n;++i){
            cin >> val;
            valSum += val;
            valSum %= mod;
        }

        long long ans {power(n,k-1)};
        ans %= mod;
        ans *= k;

        ans *= valSum;
        ans %= mod;

        cout << "Case " << tc << ": " << ans << '\n'; 
    }
}