#include<iostream>
#include<bitset>
#include<vector>
#include<cmath>


using namespace std;

using ll = long long;

const ll MAX_VAL {50000};
vector<ll> primes {};


void initPrimes(){
    primes.clear();
    bitset<MAX_VAL+1> isPrime {};
    isPrime.set();

    for(ll i=2;i<=MAX_VAL;++i){
        if(isPrime.test(i)){
            primes.push_back(i);
            for(ll j=i*i;j<=MAX_VAL;j+=i){
                isPrime.reset(j);
            }
        }
    }
}

vector<pair<ll,ll>> primeFactorize(ll value){
    vector<pair<ll,ll>> res {};

    for(ll currVal: primes){
        if(currVal * currVal > value){
            break;
        }

        ll cnt {0};
        while(value % currVal == 0){
            ++cnt;
            value /= currVal;
        }

        if(cnt != 0){
            res.push_back({currVal,cnt});
        }
    }

    if(value != 1){
        res.push_back({value,1});
    }

    return res;
}

int main(){
    initPrimes();
    ll val;

    while(cin >> val){
        auto pf {primeFactorize(val)};
        ll ans {1};
        for(auto pr: pf){
            ans *= powl(pr.second,pr.first);
        }
        cout << val << ' ' << ans << '\n';
    }
}