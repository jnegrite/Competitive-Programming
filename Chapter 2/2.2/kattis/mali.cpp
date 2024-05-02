#include<cstdio>
#include<cmath>

using namespace std;

long numRounds{};
int a, b;
long countsA[101] {};
long countsB[101] {}; 
int main(){
    scanf("%ld\n",&numRounds);
    for(long i=0;i<numRounds;i++){
        scanf("%d %d\n",&a,&b);
        countsA[a]++;
        countsB[b]++;

        long countsA2[101] {};
        long countsB2[101] {};

        //cooy values
        for(int i=0;i<=100;i++){
            countsA2[i] = countsA[i];
            countsB2[i] = countsB[i];
        }

        //evalate
        int idxA = 1;
        int idxB = 100;
        int maxSum {0};
        int minSub {}; 
        while(idxA <= 100){
            //
            while(idxA<=100 &&countsA2[idxA]==0){
                idxA++;
            }
            if(idxA > 100){
                break;
            }

            while(countsB2[idxB] == 0){
                idxB--;
            }
            minSub = countsA2[idxA]<countsB2[idxB] ? countsA2[idxA] : countsB2[idxB];
            if(idxA + idxB > maxSum){
                maxSum = idxA + idxB;
            }
            countsA2[idxA] -= minSub;
            countsB2[idxB] -= minSub;
        }
        printf("%d\n",maxSum);
    }
}