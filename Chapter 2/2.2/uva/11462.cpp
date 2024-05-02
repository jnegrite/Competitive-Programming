#include<cstdio>

using namespace std;

int main(){
    long numPeople {};
    int num {};
    while(scanf("%ld",&numPeople),numPeople>0){
        long ages[101] {};
        while(numPeople--){
            scanf("%d",&num);
            ages[num]++;
        }

        bool isFirst {true};
        for(int i=0;i<=100;i++){
            while(ages[i]){
                ages[i]--;
                if(isFirst){
                    isFirst = false;
                } else {
                    printf(" ");
                }
                printf("%d",i);
            }
        }
        printf("\n");
    }
}