#include<cstdio>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<long, long> m {};
    long nValues;
    long divisor;
    long val, q;
    scanf("%ld %ld\n",&nValues,&divisor);

    while(nValues--){
        scanf("%d",&val);
        q = val/divisor;
        auto it {m.find(q)};
        if(it == m.end()){
            m[q] = 1;
        } else {
            (it->second)++;
        }
    }

    long long ans {};
    for(auto it:m){
        ans += (it.second * (it.second-1))/2;
    }
    printf("%lld\n",ans);
}