#include<iostream>
using namespace std;

using ll = long long;

pair<ll, ll> generateNumbers(ll value){
    int digitCounts[10] {};
    
    while(value != 0){
        ++digitCounts[value%10];
        value /= 10;
    }

    //generate max
    ll maxVal {};
    ll tmpCounts[10] {};
    for(int i=0;i<=9;++i){
        tmpCounts[i] = digitCounts[i];
    }

    for(int i=9;i>=0; --i){
        while(tmpCounts[i] > 0){
            maxVal *= 10;
            maxVal += i;
            --tmpCounts[i];
        }
    }

    //generate min

    ll minVal {};
    for(int i=0;i<=9;++i){
        tmpCounts[i] = digitCounts[i];
    }
    
    //find first non-zero
    for(int i=1;i<=9;++i){
        if(tmpCounts[i] != 0){
            minVal = i;
            --tmpCounts[i];
            break;
        }
    }

    //process normally
    for(int i=0;i<=9;++i){
        while(tmpCounts[i] != 0){
            minVal *= 10;
            minVal += i;
            --tmpCounts[i];
        }
    }

    return {minVal, maxVal};
}

int main(){
    ll value;
    while(cin >> value){
        auto pr {generateNumbers(value)};
        auto diff {pr.second - pr.first};

        cout << pr.second << " - " << pr.first << " = " << diff << " = 9 * " << diff/9 << '\n'; 
    }
}