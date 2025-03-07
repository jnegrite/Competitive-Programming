#include<cstdio>
#include<vector>
#include<bitset>

using namespace std;
const long MAXVAL = 2000000;
vector<long> numDivisors {};
vector<long> numPrimeDivisors {};

int main(){
    numDivisors.assign(MAXVAL+1,1);
    numPrimeDivisors.assign(MAXVAL+1,0);

    for(long i=2;i<=MAXVAL;++i){
        bool isPrime {numDivisors[i] == 1};
        for(long j=i;j<=MAXVAL;j+=i){
            numDivisors[j]++;

            if(isPrime){
                numPrimeDivisors[j]++;
            }
        }

    }

    long nCases;
    long value;
    scanf("%ld",&nCases);
    while(nCases--){
        scanf("%ld",&value);
        printf("%ld\n",numDivisors[value]-numPrimeDivisors[value]);
    }
}