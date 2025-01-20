#include<iostream>
#include<map>

using namespace std;

map<long, int> factors {};

void saveFactor(int factor){
    auto it {factors.find(factor)};
    if(it == factors.end()){
        factors[factor] = 1;
    } else {
        ++(it->second);
    }
}

void getFactors(long long val, long long fromExp){
    for(long long i=fromExp;i*i<=val;++i){
        if(val%i == 0){
            saveFactor(i);
            getFactors(val/i,i);
            return;
        }
    }
    
    saveFactor(val);
}

int main(){
    long n;

    while(cin >> n){
        factors.clear();

        if(n<0){
            factors[-1] = 1;
            n *= -1;
        }
        getFactors(n,2);

        for(auto it {factors.begin()}; it != factors.end(); ++it){
            if(it != factors.begin()){
                cout << ' ';
            }
            cout << it->first;
            if(it->second > 1){
                cout << '^' << it->second;
            }
        }
        cout << '\n';
    }
}