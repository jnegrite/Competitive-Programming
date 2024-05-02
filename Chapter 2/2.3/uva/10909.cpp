#include<cstdio>
#include<malloc.h>

using namespace std;

long *arr;

bool isLucky(long);

long getLucky(long pos){
    if(arr[pos]!=0){
        return arr[pos];
    }
    
    long testVal {getLucky(pos-1)+1};
    while(!isLucky(testVal)){
        testVal+=2;
    }
    arr[pos] = testVal;
    return testVal;
}

bool isLucky(long num){
    if(num%2==0){
        return false;
    }

    long residual {num - num/2};
    long factorPos {2};
    long factor;
    while(factor=getLucky(factorPos), factor <= residual){
        if(residual%factor == 0){
            return false;
        }
        residual -= (residual/factor);
        factorPos++;
    }
    arr[residual] = num;
    return true;
}


int main(){
    arr = (long*)calloc(1000001,sizeof(long));
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 7;

    long num;
    while(scanf("%ld\n",&num)!=EOF){
        if(num%2!=0){
            printf("%ld is not the sum of two luckies!\n",num);
        } else {
            long seedNum {num/2};
            bool didFind {false};
            
            if(seedNum%2==0){
                seedNum--;
            }
            while(seedNum != 0){
                if(isLucky(seedNum) && isLucky(num-seedNum)){
                    printf("%ld is the sum of %ld and %ld.\n",num,seedNum,num-seedNum);
                    didFind = true;
                    break;
                }
                seedNum-=2;
            }

            if(!didFind){
                printf("%ld is not the sum of two luckies!\n",num);
            }
        }
    }
}