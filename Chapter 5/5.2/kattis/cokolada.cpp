#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    int minPow = ceil(log2(n));
    int minSize {1 << minPow};

    int nCuts = __builtin_ctz(n);
    cout << minSize << ' ' << (minPow - nCuts) << '\n';
}