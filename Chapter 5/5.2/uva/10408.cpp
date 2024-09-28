#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

struct Fraction {
    int numer;
    int denom;

    bool operator<(const Fraction &o) const {
        return numer * o.denom < denom * o.numer;
    }
};

vector<unordered_set<int>> primeFactors {};

vector<vector<Fraction>> values {};

void generateBase(int base){
    //one numerator
    for(int i=1;i<=base;++i){
        values[base].push_back({1,i});
    }

    //other
    for(int i=2;i<=base;++i){
        auto &currFactors {primeFactors[i]};
        for(int j=i+1;j<=base;++j){
            bool pairPrime {true};
            auto &otherFactors {primeFactors[j]};

            for(int factor: currFactors){
                if(otherFactors.find(factor) != otherFactors.end()){
                    pairPrime = false;
                    break;
                }    
            }

            if(pairPrime){
                values[base].push_back({i,j});
            }
        }
    }

    sort(values[base].begin(),values[base].end());
}

int main(){
    
    primeFactors.assign(1001,{});
    values.assign(1001,{});

    for(int i=1;i<=1000;++i){
        int currVal {i};
        int currFactor {2};

        while(currFactor <= currVal){
            if((currVal%currFactor) == 0){
                primeFactors[i].emplace(currFactor);
                currVal /= currFactor;
            } else {
                ++currFactor;
            }
        }
    }

    int n, k;
    while(cin >> n >> k){
        if(values[n].size() == 0){
            generateBase(n);
        }

        Fraction f {values[n][k-1]};
        cout << f.numer << '/' << f.denom << '\n';
    }
}