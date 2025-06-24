#include<iostream>

using namespace std;

int main(){
    int curr;
    int fib[47][2] {};

    fib[0][0] = fib[1][1] = 1;

    int buttonPress;
    cin >> buttonPress;

    for(int i=2;i<=buttonPress;++i){
        for(int j=0;j<2;++j){
            fib[i][j] = fib[i-1][j] + fib[i-2][j];
        }
    }

    cout << fib[buttonPress][0] << ' ' << fib[buttonPress][1] << '\n';
}