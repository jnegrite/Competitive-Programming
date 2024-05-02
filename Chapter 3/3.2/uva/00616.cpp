
#include<cstdio>

using namespace std;
long nCoconuts;

bool validPeople(long coco,int n){

    //iterations
    for(int i=0;i<n;i++){
        --coco;
        if(coco%n != 0){
            return false;
        }
        coco -= (coco/n);
    }

    return coco%n==0;
}

int main(){
    while(scanf("%ld\n",&nCoconuts),nCoconuts>=0){
        int ans {0};
        for(long i=2;i*i<=nCoconuts+1;i++){
            if(validPeople(nCoconuts,i)){
                ans = i;
            }
        }

        printf("%ld coconuts, ",nCoconuts);
        if(ans==0){
            printf("no solution\n");
        } else {
            printf("%d people and 1 monkey\n",ans);
        }
    }
}