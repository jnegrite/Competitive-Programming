#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

const long long MAX_VAL = 50000;
vector<long long> primes {};
vector<pair<long long, long long>> primeFactors {};
vector<int> divisors {};

long long currVal{};

void initPrimes(){
    
    bitset<MAX_VAL+1> isPrime {};
    isPrime.set();
    primes.clear();
    
    for(long long i=2;i<=MAX_VAL;++i){
        if(isPrime.test(i)){
            primes.push_back(i);

            for(long long j=i*i;j<=MAX_VAL;j+=i){
                isPrime.reset(j);
            }
        }
    }
}

vector<pair<long long,long long>> primeFactorize(long long value){
    vector<pair<long long,long long>> ans {};

    for(long long pos=0; pos<primes.size(); ++pos){
        long long currPrime {primes[pos]};

        if(currPrime * currPrime > value){
            break;
        }

        long long cnt {0};
        while(value%currPrime == 0){
            ++cnt;
            value /= currPrime;
        }

        if(cnt > 0){
            ans.emplace_back(currPrime, cnt);
        }
    }

    if(value != 1){
        ans.emplace_back(value, 1);
    }

    return ans;
}

void dfsDivisors(int pos, int posCnt){
    if(pos == primeFactors.size()){
        divisors.push_back(currVal);
        return;
    }

    dfsDivisors(pos+1,0);

    //check if can still add to divisors
    if(posCnt < primeFactors[pos].second){
        int prevVal = currVal;
        currVal *= primeFactors[pos].first;
        dfsDivisors(pos, posCnt+1);
        currVal = prevVal;
    }
}

int gcd(int a, int b){
    return (b==0? a : gcd(b, a%b));
}

int main(){
    initPrimes();

    long long value;
    while(cin >> value, value != 0){
        primeFactors = primeFactorize(value);
        divisors.clear();
        currVal = 1;
        dfsDivisors(0,0);

        long long ans{0};
        for(int i=0;i<divisors.size();++i){
            int a {divisors[i]};
            for(int j=0;j<=i;++j){
                int b {divisors[j]};
                int g {gcd(a,b)};

                if( (a/g) * b == value){
                    ++ans;
                }
            }
        }
        cout << value << ' ' << ans << '\n';
    }
}