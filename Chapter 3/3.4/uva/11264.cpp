#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long nCases;
    scanf("%Ld\n",&nCases);
    long long nNumbers;
    while(nCases--){
        scanf("%Ld\n",&nNumbers);
        long long ans {2};
        long long prev{};
        long long curr, next;
        scanf("%Ld %Ld",&prev,&curr);

        for(long long i = 1;i<nNumbers-1;i++){
            scanf("%Ld",&next);
            if(prev + curr < next){
                prev+=curr;
                ans++;
            }
            curr = next;
        }
        printf("%Ld\n",ans);
    }
}