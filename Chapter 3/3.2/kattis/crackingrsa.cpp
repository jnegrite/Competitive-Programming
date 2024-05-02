#include<iostream>

using namespace std;

void getFactor(const long val, long &p, long &q){
    for(p=2;;p++){
        if(val % p == 0){
            q = val/p;
            return;
        }
    }
}


int main(){
    int nCases;
    long n, e;
    long p, q;
    long d;

    cin >> nCases;
    while(nCases--){
        cin >> n >> e;
        
        getFactor(n,p,q);
        long totient {(p-1)*(q-1)};
        
        for(long k=1;;k++){
            if((k*totient +1)%e == 0){
                d = (k*totient +1)/e;
                break;
            }
        }
        cout << d << '\n';
    }
}