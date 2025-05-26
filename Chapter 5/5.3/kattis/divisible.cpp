#include<iostream>
#include<cstring>
#include<malloc.h>

using namespace std;

int main(){
    long d, nDivisors;

    long divisors[50000] {};
    long *cnt;
    
    cnt = (long*)calloc(1000000,sizeof(long));

    int nCases;
    cin >> nCases;
    while(nCases--){
        memset(divisors, 0, sizeof(divisors));
        cnt = (long*)calloc(1000000,sizeof(long));
        cnt[0] = 1;

        long long ans {0};
        cin >> d >> nDivisors;
        long long currSum {0};
        long long value;
        for(long i=0;i< nDivisors;++i){
            cin >> value;
            currSum += (value%d);
            currSum %= d;

            ans += (cnt[currSum]++);
        }
        cout << ans << '\n';
    }
}