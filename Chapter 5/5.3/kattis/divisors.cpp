#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

void addFactor(long long val, unordered_map<long long,long long> &factors){
    auto it {factors.find(val)};
    if( it == factors.end()){
        factors[val] = 1;
    } else {
        factors[val] = (1+(it->second));
    }
}

void getFactors(long long val, long long fromBase, unordered_map<long long,long long> &factors){
    for(long long i=fromBase;i*i <= val; ++i){
        if(val%i == 0){
            addFactor(i,factors);
            getFactors(val/i, i, factors);
            return;       
        }
    }
    addFactor(val,factors);
}

void primeFactorize(long long from, long long to, unordered_map<long long,long long> &factors){
    for(long long i=from;i<=to;++i){
        getFactors(i,2,factors);
    }
}

int main(){
    long long n, r, x;
    while(cin >> n >> r){
        unordered_map<long long,long long> fNumer {};
        unordered_map<long long,long long> fDenom {};

        x = n-r;

        if(x < r){
            swap(r,x);
        }

        primeFactorize(x+1,n,fNumer);
        primeFactorize(1,r,fDenom);

        long long ans {1};
        for(auto it: fNumer){
            long long mult {it.second};
            
            auto itd {fDenom.find(it.first)};
            if(itd != fDenom.end()){
                mult -= itd->second;
            }
            ans *= (1 + mult);
        }
        
        cout << ans << '\n';
    }
}

