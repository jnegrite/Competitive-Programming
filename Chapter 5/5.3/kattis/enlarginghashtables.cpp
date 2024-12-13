#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
const long MAXVAL = 40000;

bool isPrime[MAXVAL + 1] {};
vector<long> primes {2};

bool checkPrime(long val){
    if(val <= MAXVAL){
        return isPrime[val];
    }

    for(long p: primes){
        if(val%p == 0){
            return false;
        }
    }
    return true;
}

int getNextPrime(long value){
    auto it {lower_bound(primes.begin(), primes.end(), value)};
    if(it != primes.end() && *it == value){
        ++it;
    }

    if(it != primes.end()){
        return *it;
    }

    ++value;
    while(!checkPrime(value)){
        ++value;
    }
    return value;
}

int main(){
    //generate the sieve
    memset(isPrime,true,sizeof(isPrime));
    
    //handle 2
    for(long long i=4;i<=MAXVAL;i+=2){
        isPrime[i] = false;
    }

    for(long long i=3;i<=MAXVAL;i+=2){
        if(!isPrime[i]){
            continue;
        } else {
            primes.push_back(i);
        }

        long long increment {i<<1};
        for(long long j=i*i;j<=MAXVAL;j+=increment){
            isPrime[j] = false;
        }
    }

    long val;
    while(cin >> val, val != 0){
        cout << getNextPrime(val<<1);
        if(!checkPrime(val)){
            cout << " (" << val << " is not prime)";
        }
        cout <<'\n';
    }

}
