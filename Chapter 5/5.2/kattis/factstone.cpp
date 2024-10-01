#include<iostream>
#include<cmath>
#include<map>

using namespace std;

map<long long, long long> mapValues {};

int main(){
    int targetYear {1960};
    long double targetSize {4.00};
    long long currPower {1};
    long double currSubtotal {0};

    while(targetYear <= 2160){
        //test current sum
        currSubtotal += log2(currPower);
        if(currSubtotal > targetSize){
            //increment
            mapValues[targetYear] = currPower-1;
            targetYear += 10;
            targetSize *= 2;
        }
        ++currPower;
    }

    while(cin >> targetYear, targetYear > 0){
        auto it {mapValues.lower_bound(targetYear)};

        if (it->first > targetYear){
            --it;
        }

        cout << it->second << '\n';
    }
}