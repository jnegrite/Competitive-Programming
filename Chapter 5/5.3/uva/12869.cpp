#include<cstdio>

using namespace std;

int main(){
    long long a, b;

    while(scanf("%lld %lld\n",&a,&b), a!=0 || b != 0){
        printf("%lld\n",(b/5) - (a/5) + 1);
    }
}