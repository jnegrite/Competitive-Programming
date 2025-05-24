#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

using l = long long;

l extEuclid(l a, l b, l &x, l &y){
    l xx = y = 0;
    l yy = x = 1;

    l t;
    l q;
    while(b){
        q = a/b;
        t = b; b = a%b; a = t;
        t = xx; xx = x - q*xx; x=t;
        t = yy; yy = y - q*yy; y=t;
    }

    return a;
}

int main(){
    l a, b, x, k, p, q, d, x0, y0;
    int nCases;
    cin >> nCases;
    
    while(nCases--){
        cin >> x >> k;
        a = b = x/k;
        if(x%k != 0){
            ++b;
        }

        d = extEuclid(a,b,p,q);
        l factor {x/d};
        p*=factor;
        q*=factor;

        cout << p << ' ' << q << '\n';
    }
}