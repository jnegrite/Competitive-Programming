#include<iostream>
#include<vector>
#include<bitset>
#include<cmath>

using namespace std;
const long MAXVAL = 20000;

bitset<MAXVAL+1> isPrime {};

int main(){
    //generate the sieve
    isPrime.set();

    isPrime.reset(1);
    isPrime.reset(0);

    for(long long i=4;i<=MAXVAL;i+=2){
        isPrime.reset(i);
    }

    for(long long i=3;i<=MAXVAL;i+=2){
        if(!isPrime.test(i)){
            continue;
        }
        long long increment {i<<1};
        for(long long j=i*i;j<=MAXVAL;j+=increment){
            isPrime.reset(j);
        }
    }

    int nCases;
    long nFlowers;
    long double maxDist;
    
    cin >> nCases;
    while(nCases--){
        long ans {0};
        long double tempDist {};

        int x {}, y {}, px {}, py {};
        cin >> nFlowers >> maxDist;

        px = py = 0;
        for(long i=1;i<=nFlowers;++i){
            cin >> x >> y;
            
            if(tempDist > maxDist){
                continue;
            }

            long long dx {x-px};
            long long dy {y-py};
            tempDist += sqrtl(dx*dx + dy*dy);

            if(tempDist <= maxDist){
                if(isPrime.test(i)){
                    ans = i;    
                }
            }
            
            px = x;
            py = y;
        }

        cout << ans << '\n';
    }
}