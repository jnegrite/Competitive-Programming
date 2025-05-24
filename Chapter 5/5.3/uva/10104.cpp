#include<cstdio>

using namespace std;

using l = long;

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
    l a, b, x, y, d;

    while(scanf("%ld %ld\n",&a,&b) != EOF){
        d = extEuclid(a,b,x,y);
        printf("%ld %ld %ld\n",x,y,d);
    }
}