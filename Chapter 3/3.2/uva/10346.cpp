#include<iostream>

using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k){
        int total{n};

        int butts {n};

        while(butts >= k){
            int newCig = butts/k;
            total += newCig;
            butts%=k;
            butts+=newCig;
        }
        cout << total << '\n';
    }
}