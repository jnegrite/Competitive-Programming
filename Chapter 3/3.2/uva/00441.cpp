#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int k;
    int S[13];
    bool firstTest {true};
    while(scanf("%d",&k),k!=0){
        if(firstTest){
            firstTest = false;
        } else {
            printf("\n");
        }

        for(int i=0;i<k;i++){
            scanf("%d",&S[i]);
        }

        int markers[13] {};
        for(int i=6;i<k;i++){
            markers[i] = 1;
        }

        do{
            bool isFirst{true};
            for(int i=0;i<k;i++){
                if(markers[i]==0){
                    if(isFirst){
                        isFirst = false;
                    } else {
                        printf(" ");
                    }
                    printf("%d",S[i]);
                }
            }
            printf("\n");
        } while(next_permutation(markers,markers+k));
    }
}