#include<cstdio>

int main(){
    long val;
    while(scanf("%ld\n",&val) != EOF){
        long ans {1};
        long curr {1};

        while(curr % val != 0){
            curr = (curr*10+1)%val;
            ++ans;
        }
        printf("%ld\n",ans);
    }
}