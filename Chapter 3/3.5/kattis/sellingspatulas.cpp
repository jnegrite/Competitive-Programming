#include<cstdio>
#include<cmath>

using namespace std;
long prices[1000] {};
long times[1000] {};
double tempVal {};

int main(){
    int nValues {};

    while(scanf("%d\n",&nValues), nValues > 0){
        for(int i=0;i<nValues;i++){
            scanf("%ld %lf\n",&times[i], &tempVal);
            prices[i] = round(100 * tempVal);
        }

        long bestProfit {-1000000};
        long currProfit {-1};
        long bestFrom, bestTo, currFrom, currTo;

        for(int i=0;i<nValues;++i){
            
            //adjust based on previous values of
            if(i > 0){
                currProfit -= 8 * (times[i] - times[i-1] - 1); 
            }
            
            //if negative, reset to 0;
            if(i==0 || currProfit <= 0){
                currFrom = currTo = i;
                currProfit = prices[i] - 8;
            } else {
                //add this node to the list of ok
                currTo = i;
                currProfit += prices[i] - 8;
            }

            if(currProfit > bestProfit ||
                (currProfit == bestProfit && (times[currTo]-times[currFrom] < times[bestTo]-times[bestFrom]))) {
                bestProfit = currProfit;
                bestFrom = currFrom;
                bestTo = currTo;
            }
        }
        if(bestProfit <= 0){
            printf("no profit\n");
        } else {
            printf("%ld.%02d %ld %ld\n", bestProfit/100, bestProfit%100, times[bestFrom], times[bestTo]);
        }
    }
}