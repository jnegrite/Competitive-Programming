#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;
const int MAXVAL = 1299709;

bool isPrime[MAXVAL + 1] {};
vector<long> primes {2};

int main(){
    //generate the sieve
    memset(isPrime,true,sizeof(isPrime));
    for(long long i=3;i<=MAXVAL;i+=2){
        if(!isPrime[i]){
            continue;
        } else {
            primes.push_back(i);
        }

        int increment {i<<1};
        for(long long j=i*i;j<=MAXVAL;j+=increment){
            isPrime[j] = false;
        }
    }

    sort(primes.begin(), primes.end());

    int val;
    while(cin >> val, val != 0){
        auto it = lower_bound(primes.begin(),primes.end(),val);
        int ans = 0;
        if(*it != val){
            if(it != primes.begin()){
                int nxtVal = *(it--);
                int prevVal = *it;
                ans = nxtVal - prevVal;
            }
        }
        
        cout << ans << '\n';
    }
}