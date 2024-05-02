#include<iostream>
#include<bit>
#include<malloc.h>
using namespace std;

int main(){
    unsigned int numItems {};
    int *values;
    int *potencies;
    while(cin >> numItems){
        numItems = 1 << numItems;

        values = (int*)malloc(numItems * sizeof(int));
        potencies = (int*)calloc(numItems,sizeof(int));

        for(unsigned int i=0;i<numItems;i++){
            cin >> values[i];         
            for(unsigned int j=0;j<i;j++){
                if(__builtin_popcount(i ^ j)==1){
                    potencies[i] += values[j];
                    potencies[j] += values[i];
                }
            }
        }

        int maxSum{};
        for(unsigned int i=0;i<numItems;i++){
            for(unsigned int j=0;j<i;j++){
                if(__builtin_popcount(i ^ j)==1){
                    int potSum {potencies[i] + potencies[j]};
                    if(potSum > maxSum){
                        maxSum = potSum;
                    }
                }
            }
        }

        free(values);
        free(potencies);

        cout << maxSum << '\n';
    }
}