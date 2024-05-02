#include<iostream>

using namespace std;

int main(){
    long numCases;
    long n, k;
    cin >> numCases;
    for(int tc=1;tc<=numCases;tc++){
        cin >> n >> k;
        bool isOn {__builtin_ctz(k+1) >= n};
        cout << "Case #" << tc << ": " << (isOn?"ON":"OFF") << '\n';
    }
}