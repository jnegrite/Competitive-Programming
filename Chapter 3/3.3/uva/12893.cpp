#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<long long, long long> mapping {};

long long getValue(long long val){
    auto it {mapping.find(val)};

    if(it!=mapping.end()){
        return it->second;
    }

    long long prevVal {getValue(val/2)};
    prevVal += val%2;

    mapping[val] = prevVal;
    return prevVal;
}

int main(){
    mapping[0] = 0;
    int nCases;
    cin >> nCases;
    long long curr;
    while(nCases--){
        cin >> curr;
        cout << getValue(curr) << '\n';
    }
}