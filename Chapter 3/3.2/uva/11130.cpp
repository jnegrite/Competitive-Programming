#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    long long a, b, xa, xb;
    long double v, A, s;
    long double xv, xA, xs;
    constexpr double pi = 3.14159265358979323846;

    scanf("%lld %lld %llf %llf %llf\n",&a,&b,&v,&A,&s);
    while(scanf("%lld %lld %llf %llf %llf\n",&xa,&xb,&xv,&xA,&xs)!=EOF){
    
        const long double totalDist {v*s/2.0};

        long dX = long((a/2.0 + totalDist * cos(pi * A/180.0))/a);
        long dY = long((b/2.0 + totalDist * sin(pi * A/180.0))/b);

        printf("%ld %ld\n",dX,dY);
        
        a = xa;
        b = xb;
        v = xv;
        A = xA;
        s = xs;
    }
}