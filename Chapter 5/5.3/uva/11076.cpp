#include<iostream>
#include<cstring>

using namespace std;

long long factorial[13] {};
long long multipliers[13] {};
int digitCounts[10] = {};

void initMultipliers(){
    long long currMult{1};
    multipliers[0] = multipliers[1] = 1;

    for(int i=2;i<=12;++i){
        currMult *= 10;
        multipliers[i] = multipliers[i-1] + currMult;
    }
}

int main(){
    factorial[0] = 1;
    for(int i=1;i<=12;++i){
        factorial[i] = factorial[i-1] * i;
    }

    initMultipliers();

    int nValues;
    long long sumValues;
    int val;

    while(cin >> nValues, nValues != 0){
        sumValues = 0;
        memset(digitCounts,0,sizeof(digitCounts));

        for(int i=0;i<nValues;++i){
            cin >> val;
            ++digitCounts[val];    
            sumValues += val;
        }

        long long finFactorial{factorial[nValues-1]};
        long long denom {1};
        for(int i=0;i<10;++i){
            int nIter {digitCounts[i]};
            for(int j=nIter;j>1;--j){
                if(finFactorial%j == 0){
                    finFactorial/=j;
                } else if(sumValues%j == 0) {
                    sumValues /= j;
                } else {
                    denom *= j;
                }
            }
        }
        cout << (sumValues * multipliers[nValues] * finFactorial)/denom << '\n';
    }
}