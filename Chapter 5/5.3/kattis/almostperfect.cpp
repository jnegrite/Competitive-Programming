#include<iostream>

using namespace std;

string process(long long val){
    long long currSum {1};
    long long upper {val+2};

    for(int i=2;i*i<=val && currSum <= upper; ++i){
        if(val%i == 0){
            if(i*i == val){
                currSum += i;
            } else {
                currSum += i + (val/i);
            }
        }
    }

    long long diff {llabs(currSum - val)};

    string ans {};
    switch(diff){
        case 0:
            return "";
        case 1: case 2:
            return " almost";
        default:
            return " not";
    }
}

int main(){
    long long n;
    long long currSum;
    while(cin >> n){
        cout << n << process(n) << " perfect\n";
    }
}