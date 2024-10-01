#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int p;
    long double log2_10 {log2(10)};
    long long lower, upper;
    long double log2p, log2p1;
     
    int t;
    while(cin >> p){
        log2p = log2(p);
        log2p1 = log2(p+1);

        int ans {-1};
        t = to_string(p).length()+1;

        while(ans == -1 && t <= 1000000){
            long double addend {t * log2_10};
            lower = ceil(log2p + addend);
            upper = floor(log2p1 + addend);

            if(lower == upper){
                ans = lower;
            }

            ++t;
        }

        if(ans == -1){
            cout << "no power of 2\n";
        } else {
            cout << ans << '\n';
        }
    }
}