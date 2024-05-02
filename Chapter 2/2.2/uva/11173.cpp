#include<iostream>

using namespace std;

int main(){
    long tc {};
    int n, k;

    cin >> tc;
    while(tc--){
        cin >> n >> k;
        cout << (k ^ (k>>1)) << '\n';
    }
}