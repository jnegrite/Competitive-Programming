#include<iostream>

using namespace std;

long josephus(long n, long k){
    if(n==1){
        return 0;
    }

    return (josephus(n-1,k) + k)%n;
}

int main(){
    long t, k;
    cin >> t >> k;
    cout << josephus(t,k) <<'\n';
}