#include<iostream>

using namespace std;

long long getSum(long long from, long long to){
    return ((to - from + 1) * (from + to))>>1;
}

int main(){
    int nCases;
    cin >> nCases;

    long long n, m;
    while(nCases--){
        cin >> n >> m;
        cout << getSum(m-n,m-1) << '\n';
    }
}