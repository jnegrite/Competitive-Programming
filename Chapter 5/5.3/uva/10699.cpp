#include<cstdio>
#include<vector>
#include<bitset>

using namespace std;

const long MAXVAL {1000000};

vector<long> primes {};
bitset<MAXVAL+1> isPrime {};

int countPrimeFactors(long value){
    long ans {0};
    for(int pos=0;pos<primes.size();++pos){
        long &val {primes.at(pos)};
        
        if(value < val){
            break;
        }

        if(value%val == 0){
            ++ans;
            while(value%val == 0){
                value/=val;
            }
        }
    }
    if(value != 1){
        ++ans;
    }
    return ans;
}

int main(){
    isPrime.set();
    for(long i=4;i<=MAXVAL;i+=2){
        isPrime.reset(i);
    }

    primes.push_back(2);

    for(long long i=3;i<=MAXVAL;++i){
        if(!isPrime.test(i)){
            continue;
        }

        primes.push_back(i);
        long long increment {i<<1};
        for(long long j=i*i;j<MAXVAL;j+=increment){
            isPrime.reset(j);
        }
    }

    long value;
    while(scanf("%ld\n",&value), value != 0){
        printf("%ld : %d\n",value, countPrimeFactors(value));
    }
}