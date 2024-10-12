#include<cstdio>
#include<cmath>
#include<algorithm>
#include<algorithm>

using namespace std;

pair<int,int> locatePoint(long long n){
    long long base {sqrt(n)};
    long long prod {base * base};
    if (prod == n){
        return {base, 2*(base-1) + 1};
    } else {
        return {base+1, n-prod};
    }
}

int main(){
    
    long long a, b;
    while(scanf("%lld %lld\n",&a,&b) != EOF){
        if(a>b){
            swap(a,b);
        }
        
        auto locA {locatePoint(a+1)};
        auto locB {locatePoint(b+1)};

        double dx = ((locA.second-locA.first)-(locB.second-locB.first))/2.0;
        double dy = 0.5*sqrt(3)*abs(locA.first - locB.first);

        if(locA.second%2==1 && locB.second%2==0){
            dy -= sqrt(3)/6;
        } else if (locA.second%2==0 && locB.second%2==1){
            dy += sqrt(3)/6;
        }

        double ans {sqrt(dy*dy + dx*dx)};
        printf("%.3lf\n",ans);
    }
}