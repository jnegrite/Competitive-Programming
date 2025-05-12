#include<iostream>
#include<bitset>
#include<vector>
#include<unordered_map>
#include<cmath>

using namespace std;

const long long MAXVAL {1000000};

vector<long long> primes {};
vector<vector<int>> cycles {
    {0},
    {1},
    {6,2,4,8},
    {1,3,9,7},
    {6,4},
    {5},
    {6},
    {1,7,9,3},
    {6,8,4,2},
    {1,9},
};

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

int getExp(long long value, int base){
    return static_cast<int>(log(value)/log(base));
}

int getMultiplier(int pos, int occ){
    pos %= 10;
    return cycles[pos][occ%cycles[pos].size()];
}

int getLastDigit(long long value){
    int pow2 {getExp(value,2)};
    int pow3 {getExp(value,3)};
    int pow5 {getExp(value,5)};
    
    int ans {1};
    if(pow2 > pow5){
        ans *= getMultiplier(2,pow2-pow5);
    }
    pow3 = getExp(value,3);

    if(pow3 != 0){
        ans *= getMultiplier(3,pow3);
    }

    for(long i=3;i<primes.size() && primes[i] <= value; ++i){
        ans *= getMultiplier(primes[i],getExp(value,primes[i]));
        ans %= 10;
    }
    return ans%10;
}

int main(){
    generatePrimes();
    
    long long v;
    while(cin >> v, v != 0){
        int ans {0};
        switch(v){
            case 1:
                ans = 1;
                break;
            case 2:
                ans = 2;
                break;
            case 3:
                ans = 6;
                break;
            case 4:
                ans = 2;
                break;
            default:
                ans = getLastDigit(v);
        }
        cout << ans << '\n';
    }
}