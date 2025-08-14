#include<iostream>

using namespace std;

long long memo[1000001] {};

int main(){
    for(long long v{3};v <=1000000;++v){
        memo[v] = memo[v-2] + ((v-3)*(v-2)/2);
    }

    long long curr {};
    while(cin >> curr, curr >= 3){
        cout << memo[curr] << '\n';
    }
}