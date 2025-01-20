#include<iostream>
#include<cmath>

using namespace std;

long long leastDiv {-1};

bool isPrime(long long val){
    if(val < 2){
        return false;
    }

    for(long long i=2;i*i<=val;++i){
        if(val%i == 0){
            return false;
        }
    }
    return true;
}

long long lpd(long long val, long long div){
    while(val%div && div*div <= val){
        ++div;
    }

    if(val%div==0){
        if(leastDiv == -1){
            leastDiv = div;
        }
        return max(div, lpd(val/div,div));
    } else {
        return val;
    }
}

int main(){
    long long val;
    while(cin >> val, val!=0){
        leastDiv = -1;

        if(val < 0){
            val *= -1;
        }

        long long ans {lpd(val,2)};

        if(leastDiv == ans || ans == val){
            ans = -1;
        }

        cout << ans << '\n';
    }
}