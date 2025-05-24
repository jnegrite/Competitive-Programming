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

l computeCost(l x0, l y0, l a, l b, l ca, l cb, l d, l nTest){
    l x {x0 + (b/d) * nTest};
    l y {y0 - (a/d) * nTest};
    return ca * x + cb * y;
}

int main(){
    l n;
    l a, b, x0, y0, d;
    l ca, cb;
    l x1, y1, x2, y2;
    l n1, n2;

    while(scanf("%lld\n",&n), n != 0){
        scanf("%lld %lld\n",&ca,&a);
        scanf("%lld %lld\n",&cb,&b);
        d = extEuclid(a,b,x0,y0);
        
        if(n%d != 0){
            printf("failed\n");
            continue;
        }

        l factor {n/d};

        x0 *= factor;
        y0 *= factor;
        
        l t;
        t = b/d;
        n1 = static_cast<l>(ceill(static_cast<long double>(-x0)/t));
        
        t = a/d;
        n2 = static_cast<l>(floorl(static_cast<long double>(y0)/t));

        l x, y;

        if(n1 > n2){
            printf("failed\n");
            continue;
        }

        l c1 {computeCost(x0,y0,a,b,ca,cb,d,n1)};
        l c2 {computeCost(x0,y0,a,b,ca,cb,d,n2)};
        l nActual {(c1 < c2) ? n1 : n2};

        x = x0 + (b/d) * nActual;
        y = y0 - (a/d) * nActual;

        printf("%lld %lld\n",x,y);
    }
}