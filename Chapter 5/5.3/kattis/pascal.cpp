#include<iostream>

using namespace std;

long long greatestFactor(int n){
    for(long long i=2;i*i <= n; ++i){
        if(n%i == 0){
            return n/i;
        }
    }
    return 1;
}

long long process(long long n){
    if(n <= 1){
        return 0;
    } else {
        return n - greatestFactor(n);
    }
}

int main(){
    long long n;
    cin >> n;
    cout << process(n) << '\n';
}