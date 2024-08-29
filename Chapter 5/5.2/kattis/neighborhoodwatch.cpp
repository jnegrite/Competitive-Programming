#include<iostream>

using namespace std;

int main(){
    long long prevSafe {0};
    int nHouses, nSafeHouses;

    cin >> nHouses >> nSafeHouses;

    long long ans {};
    long long curr;
    while(nSafeHouses--){
        cin >> curr;
        ans += (curr - prevSafe) * prevSafe;
        prevSafe = curr;
    }

    ans += (1 + nHouses-prevSafe) * prevSafe;

    cout << ans << '\n';
}