#include<iostream>
#include<set>
#include<cmath>

using namespace std;

void decompose(long long value, multiset<long long> &primeFactors){
    long long valSqrt = sqrt(value) + 1;
    long long currMax;

    if(primeFactors.empty()){
        currMax = 2;
    } else {
        currMax = *primeFactors.rbegin();
    }

    for(long long it = currMax; it<=valSqrt;it++){
        if(value % it == 0){
            primeFactors.emplace(it);
            decompose(value/it,primeFactors);
            return;
        }
    }
    primeFactors.emplace(value);
}

void generateCombinations(multiset<long long>::iterator currIter,
                    multiset<long long> &srcSet,
                    long long currValue,
                    set<long long> &answers){
    
    if(currIter == srcSet.end()){
        answers.emplace(currValue);
        return;
    }

    //not use the value
    auto itNext = ++currIter;
    currIter--;
    generateCombinations(itNext,srcSet,currValue,answers);

    //use this value
    long long multiplier {*currIter};
    currValue *= multiplier;
    generateCombinations(itNext,srcSet,currValue,answers);
    currValue /= multiplier;
}

int main(){
    long long value;
    cin >> value;
    multiset<long long> factors {};
    decompose(value,factors);

    set<long long> answers {1};
    long long currValue {1LL};

    auto it = factors.begin();
    generateCombinations(it,factors,currValue,answers);

    for(auto it=answers.begin();it!=answers.end();it++){
        if(it != answers.begin()){
            cout << ' ';
        }
        cout << (*it)-1;
    }
    cout << '\n';
}