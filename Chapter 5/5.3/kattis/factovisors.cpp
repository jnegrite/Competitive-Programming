#include<iostream>
#include<bitset>
#include<vector>
#include<unordered_map>

using namespace std;

const long long MAXVAL {50000};

vector<long long> primes {};

void generatePrimes(){
    primes.clear();
    
    bitset<MAXVAL+1> isPrime {};
    isPrime.set();

    for(long long i=2;i<=MAXVAL;++i){
        if(isPrime.test(i)){
            primes.push_back(i);

            for(long long j=i*i;j<=MAXVAL;j+=i){
                isPrime.reset(j);
            }
        }
    }
}


unordered_map<long long, long long> primeFactorize(long long value){
    unordered_map<long long, long long> ans {};

    long long pos {0};
    while(true){
        if(pos >= primes.size()){
            break;
        }
        long long currVal {primes[pos]};
        if(currVal*currVal> value){
            break;
        }
        long long reps {0};
        while(value%currVal == 0){
            ++reps;
            value /= currVal;
        }

        if(reps > 0){
            ans[currVal] = reps;
        }
        ++pos;
    }

    if(value != 1 || ans.size() == 0){
        ans[value] = 1;
    }
    return ans;
}

bool hasEnoughFactors(long long factorialTo, long long base, long long needed){
    long long currDiv {factorialTo/base};
    if(currDiv == 0){
        return false;
    }

    if(currDiv >= needed){
        return true;
    }

    return hasEnoughFactors(currDiv, base, needed-currDiv);
}

int main(){
    generatePrimes();

    long long n, m;
    while(cin >> n >> m){
        bool isOk {true};
        if(m == 0){
            isOk = false;
        } else if(n == 0){
            isOk = (m == 1);
        } else if (m != 1){
            auto pf {primeFactorize(m <= 0 ? 1 : m)};
            for(auto pr:pf){
                if(!hasEnoughFactors(n,pr.first,pr.second)){
                    isOk = false;
                    break;
                }
            }
        }

        cout << m << (isOk?" divides ":" does not divide ") << n << "!\n";
    }
}