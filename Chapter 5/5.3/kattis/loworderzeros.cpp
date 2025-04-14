#include<iostream>
#include<vector>

using namespace std;
int cycle[4] {6,2,4,8};

int factorial(int value){
    if(value == 0){
        return 1;
    } else {
        return value * factorial(value-1);
    }
}


int lastNonZero(long long value){
    if(value < 5){
        return factorial(value);
    }
    
    long long a {value/5};
    long long b {value%5};

    long long ans {lastNonZero(a) * lastNonZero(b)};

    if(a > 0){
        ans *= cycle[a%4];
    }
    return ans%10;
}

int main(){
    long long value;
    while(cin >> value, value != 0){
        cout << lastNonZero(value) << '\n';
    }
}