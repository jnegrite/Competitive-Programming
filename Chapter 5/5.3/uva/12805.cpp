#include<iostream>
#include<map>

using namespace std;

int signs[100001] {};

void addFactor(long value, map<long, int> &f){
    auto it {f.find(value)};

    if(it == f.end()){
        f[value] = 1;
    } else {
        f[value] = it->second + 1;
    }
}


void primeFactorize(long value, long start, map<long, int> &f){
    for(long i=start; i*i <= value; ++i){
        if(value%i == 0){
            addFactor(i,f);
            primeFactorize(value/i,i,f);
            return;
        }
    }
    addFactor(value,f);
}

int getSign(long pos){
    if(signs[pos] != 0){
        return signs[pos];
    }

    if(pos == 2){
        return signs[pos] = 1;
    } else {
        map<long, int> f {};
        primeFactorize(pos,2,f);

        if(f.size() == 1 && (f.begin()->second == 1)){
            // is prime
            if((pos+1)%4 == 0){
                signs[pos] = 1;
            } else {
                signs[pos] = -1;
            }
            return signs[pos];
        } else {
            int currSign {1};
            for(auto it: f){
                if((it.second%2 == 1) && (getSign(it.first)==-1)){
                    currSign *= -1;
                }
            }
            return signs[pos] = currSign;
        }
    }
}

int main(){
    int nCases;
    long val;
    cin >> nCases;
    while(nCases--){
        cin >> val;
        cout << (getSign(val) == -1 ? "-" : "+") << '\n';
    }
}