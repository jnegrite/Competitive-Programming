#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    while(cin >> n, n>0){
        cout << floor(log2(n)) << '\n';
    }
}