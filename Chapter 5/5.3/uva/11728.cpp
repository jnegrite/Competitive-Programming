#include<cstdio>
#include<vector>
#include<bitset>

using namespace std;

using ll = long long;

vector<long> primes {};
bitset<1001> isPrime {};
vector<int> ans {};


ll sumDiv(ll N){
    ll ans = 1;

    for(int i=0;i<primes.size() && (primes[i] * primes[i] <= 1000); ++i){
        ll multiplier = primes[i], total = 1;
        while(N%primes[i] == 0){
            N/=primes[i];
            total += multiplier;
            multiplier *= primes[i];
        }
        ans *= total;
    }
    if(N!= 1) {
        ans *= (N+1);
    }
    return ans;
}

int main(){
    isPrime.set();
    primes.clear();
    ans.assign(1001,-1);

    //generate set of primes
    for(long long factor=2;factor<=1000;++factor){
        if(!isPrime.test(factor)){
            continue;
        }

        primes.push_back(factor);

        long long increment {(factor == 2LL) ? factor : (factor << 1)};
        for(long long i=factor*factor; i <= 1000; i+=increment){
            isPrime.reset(i);
        }
    }

    for(int i=1;i<=1000;++i){
        long v = sumDiv(i);
        if(v<=1000){
            ans[sumDiv(i)] = i;
        }
    }

    int n;
    int nCase {};
    while(scanf("%d",&n), n!=0){
        printf("Case %d: %d\n",++nCase,ans[n]);
    }
}