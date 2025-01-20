#include<iostream>
#include<map>

using namespace std;

long fibo[41] {};

void fillFibo(){
    fibo[0] = 0;
    fibo[1] = 1;

    for(long i=2;i<=40;++i){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

void addFactor(long n, long value, map<long,long> &f){
    auto it {f.find(n)};
    if(it == f.end()){
        f[n] = value;
    } else {
        f[n] = (it->second + value);
    }
}

void addFactor(long n, map<long,long> &f){
    addFactor(n, 1, f);
}

void primeFactorize(long val, long startNum, map<long,long> &f){
    for(long i=startNum; i*i <= val;++i){
        if(val%i == 0){
            addFactor(i,f);
            primeFactorize(val/i,i,f);
            return;
        }
    }
    addFactor(val,f);
}

map<long,long> consolidate(map<long, long> &fA, long xA, map<long, long> &fB, long xB) {
    map<long, long> res {};

    for(auto it: fA){
        addFactor(it.first, it.second*xA, res);
    }
    for(auto it: fB){
        addFactor(it.first, it.second*xB, res);
    }

    return res;
}

int main(){
    long nCases;
    cin >> nCases;
    
    map<long, long> factorA {};
    map<long, long> factorB {};
    fillFibo();

    while(nCases--){
        long a, b;
        long n;
        cin >> n >> a >> b;

        factorA.clear();
        factorB.clear();

        primeFactorize(a,2,factorA);
        primeFactorize(b,2,factorB);

        long expB = fibo[n];
        long expA = fibo[n-1];

        auto res {consolidate(factorA, expA, factorB, expB)};

        for(auto it: res){
            cout << it.first << ' ' << it.second << '\n';
        }
        cout << '\n';
    }


}