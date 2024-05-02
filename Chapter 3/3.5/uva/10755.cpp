#include<iostream>

using namespace std;

long grid[21][21][21] {};

int main(){
    int nCases;

    scanf("%d\n",&nCases);
    for(int tc=0;tc<nCases;++tc){
        int A, B, C;
        scanf("%d %d %d\n", &A, &B, &C);
        for(int a=1;a<=A;++a){
            auto &sliceA {grid[a]}; 
            for(int b=1;b<=B;++b){
                auto &sliceB {sliceA[b]};
                for(int c=1;c<=C;++c){
                    scanf("%ld",&sliceB[c]);

                    if(c > 1){
                        sliceB[c] += sliceB[c-1];
                    }

                    if(b > 1){
                        const auto &prevB {sliceA[b-1]};
                        sliceB[c] += prevB[c];

                        if(c>1){
                            sliceB[c] -= prevB[c-1];
                        }
                    }
                }
            }
        }

        //process
        long maxAns {grid[1][1][1]};
        for(int bFrom=0;bFrom<B;++bFrom){
            for(int bTo=bFrom+1;bTo<=B;++bTo){
                for(int cFrom=0;cFrom<C;++cFrom){
                    for(int cTo=cFrom+1;cTo<=C;++cTo){
                        long currSum {0};

                        for(int a=1;a<=A;a++){
                            const auto sliceA {grid[a]};
                            currSum += sliceA[bTo][cTo] - sliceA[bTo][cFrom]
                                - sliceA[bFrom][cTo] + sliceA[bFrom][cFrom];

                            if(currSum > maxAns){
                                maxAns = currSum;
                            }

                            if(currSum < 0){
                                currSum = 0;
                            }
                        }
                    }
                }
            }
        }

        if(tc>0){
            printf("\n");
        }
        printf("%ld\n",maxAns);
    }
}