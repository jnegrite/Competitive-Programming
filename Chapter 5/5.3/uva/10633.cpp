#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

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
    l val, a, b, x0, y0, x1, y1, n1, n2, n11;
    extEuclid(9,1,x0,y0);

    while(scanf("%lld\n",&val), val != 0){
        x1 = x0 * val;
        y1 = y0 * val;

        vector<l> ans {};

        n1 = static_cast<l>(ceill(static_cast<long double>(-x1)/1));
        n1 = max(n1,static_cast<l>(ceill(static_cast<long double>(y1-10)/9))); 
        
        n2 = static_cast<l>(floorl(static_cast<long double>(y1)/9));

        for(l n=n1;n<=n2;++n){
            l x {x1 + n};
            l y {y1 - 9*n};

            if(x > 0 && y >=0 && y < 10){
                ans.push_back(x*10 + y);
            }
        }

        sort(ans.begin(),ans.end());
        printf("%Ld",ans[0]);
        for(int i=1;i<ans.size();++i){
            printf(" %ld", ans[i]);
        }
        printf("\n");
    }
}