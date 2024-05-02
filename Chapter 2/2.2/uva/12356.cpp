#include<cstdio>

using namespace std;

int main(){
    long S, B;
    long from, to;
    

    while(true){
        scanf("%ld %ld\n",&S, &B);
        if(S==0 && B==0){
            break;
        }

        long left[100001] {};
        long right[100001] {};

        for(int i=1;i<=S;i++){
            left[i] = i-1;
            right[i] = i+1;
        }

        left[1] = -1;
        right[S] = -1;

        while(B--){
            scanf("%ld %ld\n", &from, &to);
            left[right[to]] = left[from];
            right[left[from]] = right[to];

            if(left[from] == -1){
                printf("* ");
            } else {
                printf("%ld ",left[from]);
            }

            if(right[to] == -1){
                printf("*\n");
            } else {
                printf("%ld\n",right[to]);
            }
        }
        printf("-\n");
    }
}