#include<iostream>

using namespace std;

long josephus(long n, long k){
    if(n==1){
        return 0;
    } else {
        return (josephus(n-1,k) + k)%n;
    }
}

int main(){
    int nCases;
    long n, k;
    cin >> nCases;
    for(int tc=1;tc<=nCases;tc++){
        cin >> n >> k;
        printf("Case %d: %ld\n",tc,1+josephus(n,k));
    }
}