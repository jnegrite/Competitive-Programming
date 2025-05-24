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

l mod(l a, l m){
    return ((a%m) + m) % m;
}

l modInverse(l b, l m){
    l x, y, d;
    d = extEuclid(b,m,x,y);

    if(d != 1){
        return -1;
    }

    return mod(x,m);
}

int main(){
    l n, t;
    string op; 
    l a, b;

    while(cin >> n >> t, n != 0 || t != 0){
        while(t--){
            cin >> a >> op >> b;

            switch(op.at(0)){
                case '+':
                    cout << mod(mod(a,n)+mod(b,n),n);
                    break;
                case '-':
                    cout << mod(mod(a,n)-mod(b,n),n);
                    break;
                case '*':
                    cout << mod(mod(a,n)*mod(b,n),n);
                    break;
                case '/':
                    l inv {modInverse(b,n)};
                    if (inv == -1){
                        cout << -1;
                    } else {
                        cout << mod(mod(a,n)*mod(inv,n),n);
                    }
                    break;
            }
            cout << '\n';
        }
    }
}