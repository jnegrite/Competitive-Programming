#include<iostream>

using namespace std;

int main(){
    long long a, b;

    while(cin >> a >> b){
        long long lastVal = a-b;
        long long ans {1};
        for(long long v=a; v > lastVal;--v){
            long long t {v};
            while(t%10 == 0){
                t /= 10;
            }

            ans *= t;
            while(ans % 10 == 0){
                ans /= 10;
            }

            ans %= 1000000000;
        }
        cout << ans % 10 << '\n';
    }
}