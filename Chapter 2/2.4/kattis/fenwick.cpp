#include<cstdio>
#include<vector>
#define LSOne(x) ((x) & (-x))

using namespace std;

typedef long long ll;

long nValues, nOps;
char op;
ll v1, v2;
vector<ll> ft;

int main(){
    scanf("%lld %lld\n",&nValues,&nOps);
    ft.assign(nValues+2,0);
    while(nOps--){
        scanf("%c",&op);
        if(op=='+'){
            scanf("%lld %lld\n",&v1,&v2);
            v1++;
            while(v1 <= nValues){
                ft[v1] += v2;
                v1 += LSOne(v1);
            }
        } else if (op=='?'){
            scanf("%lld\n",&v1);
            ll total {};
            while(v1 > 0){
                total += ft[v1];
                v1 -= LSOne(v1);
            }
            printf("%lld\n",total);
        }
    }
}