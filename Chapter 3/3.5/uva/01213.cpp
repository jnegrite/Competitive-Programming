#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

vector<int> primes {};

void generatePrimes(){
    primes.clear();
    bool isPrime[1121] {};
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<=1120;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=(i<<1);j<=1120;j+=i){
                isPrime[j] = false;
            }
        }
    }
}

long memo[1121][1121][15] {};

long dp(int remSum, int pos, int remItems){
    if(pos == primes.size() || remSum < primes[pos] || remItems == 0){
        return 0;
    }

    if(remSum == primes[pos] && remItems == 1){
        return 1;
    }

    auto &curr {memo[remSum][pos][remItems]};

    if(curr != -1){
        return curr;
    }

    return curr = dp(remSum,pos+1,remItems) + dp(remSum - primes[pos],pos+1,remItems-1);
} 

int main(){
    generatePrimes();
    memset(memo,-1,sizeof(memo));

    int n, k;
    while(scanf("%d %d\n",&n,&k),n!=0||k!=0){
        printf("%ld\n",dp(n,0,k));
    }

}


