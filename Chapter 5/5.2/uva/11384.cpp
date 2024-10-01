#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        cout << 1 + floor(log2(n)) << '\n';
    }
}