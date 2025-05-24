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
    l k, x, c, n, d, x0, y0;
    
    l nCases;

    cin >> nCases;

    while(nCases--){
        cin >> k >> c;
        d = extEuclid(c, k, x0, y0);

        if (d != 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        l n1 {};
        n1 = static_cast<l>(ceill(static_cast<long double>(-x0+1)/k));
        n1 = max(n1, static_cast<l>(ceill(static_cast<long double>(y0+1)/c)));

        l nAns {x0 + k * n1};

        if (nAns > 1000000000){
            cout << "IMPOSSIBLE\n";
        } else {
            cout << nAns << '\n';
        }
    }
}