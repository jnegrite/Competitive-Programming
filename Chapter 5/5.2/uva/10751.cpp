#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    int nCases;

    scanf("%d\n",&nCases);

    int gridSize {};
    while(nCases--){
        double ans {0};

        scanf("%d\n",&gridSize);

        if(gridSize==1){
            ans = 0;
        } else {
            int nDiags = (gridSize-2);
            nDiags *= nDiags;

            ans = (gridSize * gridSize + (sqrt(2)-1) * nDiags);

        }
        
        printf("%.03lf\n", ans);

        if(nCases){
            printf("\n");
        }
    }
}