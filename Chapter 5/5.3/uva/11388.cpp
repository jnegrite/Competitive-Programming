#include<iostream>

using namespace std;

int main(){
    int nCases;
    int a, b;
    cin >> nCases;
    
    while(nCases--){
        cin >> a >> b;
        if( b%a != 0){
            cout << "-1\n";
        } else {
            cout << a << ' ' << b << '\n';
        }
    }
}