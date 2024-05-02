#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int nCases;
    int n, h;
    char combinations[17] {};
    scanf("%d\n",&nCases);

    for(int tc=0;tc<nCases;tc++){
        if(tc>0){
            printf("\n");
        }

        scanf("%d %d\n",&n,&h);
        combinations[n] = '\0';

        for(int i=0;i<n-h;i++){
            combinations[i] = '0';
        }

        for(int i=n-h;i<n;i++){
            combinations[i] = '1';
        }

        do {
            printf("%s\n",combinations);
        } while (next_permutation(combinations,combinations+n));

    }

}