#include<iostream>

using namespace std;

const long long md {1000000007};

long long pow(long long base, long long power){
    if(power == 0){
        return 1;
    } else if(power%2 == 0 ){
        long long temp {base * base};
        temp %= md;
        return pow(temp,power>>1);
    } else {
        long long temp {pow(base,power-1)};
        temp %= md;
        temp *= base;
        temp %= md;
        return temp;
    }
}

int main(){
    int nCases;
    long long  power;
    
    cin >> nCases;
    while(nCases--){
        cin >> power;
        
        long long ans {pow(9,power-1)};
        ans *= 8;
        ans %= md;
        cout << ans << '\n';
    }
}
