#include<iostream>
#include<set>

using namespace std;

set<long long unsigned> values {1};

const long long unsigned upperBound {1LLU<<31};

void propagate(long long unsigned value, bool flag){
    if(!flag){
        long long unsigned m2 {value<<1};
        if(m2 <= upperBound){
            values.emplace(m2);
            propagate(m2,false);
        }
    }

    long long unsigned m3 {value * 3LL};
    if(m3 <= upperBound){
        values.emplace(m3);
        propagate(m3,true); 
    }   
}


int main(){
    propagate(1,false);
    long long unsigned val;

    while(cin >> val,val!=0){
        cout << *values.lower_bound(val) << '\n';
    }
}