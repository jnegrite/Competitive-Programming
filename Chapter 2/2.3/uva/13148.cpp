#include<iostream>
#include<unordered_set>

using namespace std;

long power(long base, int exp){
    if(exp == 1){
        return base;
    } else if(exp%2==0){
        long temp {power(base,exp/2)};
        return temp*temp;
    } else {
        return base * power(base,exp-1);
    }
}

int main() {
    //preprocess;
    unordered_set<long> special {};
    for(int i=1;i<=21;i++){
        special.emplace(power(i,6));
    }

    //actual procedure
    long curr;
    while(cin>>curr,curr != 0){
        if(special.count(curr) != 0){
            cout << "Special\n";
        } else {
            cout << "Ordinary\n";
        }
    }
}