#include<iostream>
#include<unordered_set>

using namespace std;

using um = unordered_set<long>;

void saveFactor(long value, um &f){
    f.emplace(value);
}

void primeFactorize(long value, long curr, um &f){
    for(long i=curr;i*i<=value;++i){
        if(value%i == 0){
            saveFactor(i,f);
            primeFactorize(value/i,i,f);
            return;
        }
    }
    saveFactor(value,f);
}

int main(){
    long value;
    um factors {};
    while(cin >> value, value!=0){
        factors.clear();
        primeFactorize(value, 2, factors);
        long ans {value};
        if(value == 1){
            ans = 1;
        } else {
            for(auto it: factors){
                ans /= it;
                ans *= (it-1);
            }
        }
        cout << ans << '\n';
    }
}