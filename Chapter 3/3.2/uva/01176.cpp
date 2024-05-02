#include<iostream>

using namespace std;

int main(){
    long players {};
    while(cin >> players){
        int cnt {__builtin_popcount(players)};
        long survivor {(1<<cnt)-1};
        cout << players + survivor << '\n';
    }
}