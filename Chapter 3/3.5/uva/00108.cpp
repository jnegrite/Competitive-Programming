#include<cstdio>
#include<cmath>



int n;
int grid[100][100] {};

int main(){
    
    while(scanf("%d\n",&n) != EOF){
        long bestSum {-127*100*100};
        long currSum {};
        
        for(int row=0;row<n;++row){
            auto &refRow {grid[row]};
            for(int col=0;col<n;++col){
                scanf("%d",&refRow[col]);
                if(col > 0){
                    refRow[col] += refRow[col-1];
                }
            }
        }

        for(int left{0};left<n;++left){
            for(int right{left};right<n;++right){
                currSum = 0;

                for(int row=0;row<n;++row){
                    currSum += grid[row][right];
                    if(left>0){
                        currSum -= grid[row][left-1];
                    }

                    if(currSum > bestSum){
                        bestSum = currSum;
                    }

                    if(currSum < 0){
                        currSum = 0;
                    }

                }
            }
        }
        printf("%ld\n",bestSum);
    }
}
