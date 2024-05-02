#include<iostream>
#include<cstdio>

using namespace std;

using repr = pair<int, int>;
const long mask10 {(1<<10)-1};

repr getRepr(long val){
    repr output {};
    int curr;
    int encoding{0};
    for(int i=0;i<5;i++){
        curr = val%10;
        if((encoding & (1<<curr)) != 0){
            return repr{i,0};
        }
        encoding |= (1<<curr);
        val/=10;
    }
    return repr{-1,encoding};
}

int main(){
    int N;
    bool isFirst{true};

    while(scanf("%d\n",&N),N!=0){
        if(isFirst){
            isFirst=false;
        } else {
            printf("\n");
        }
        long endNum {98765/N + 1};
        bool hasAns{false};
        for(long denom{(1234/N)*N};denom <= endNum;denom++){
            repr rD {getRepr(denom)};
            if(rD.first == -1){
                long numerator = denom * N;
                repr rN {getRepr(numerator)};
                if(rN.first == -1 && (rD.second + rN.second == mask10)){
                    hasAns = true;
                    printf("%05d / %05d = %d\n",numerator,denom,N);
                }
            }
        }

        if(!hasAns){
            printf("There are no solutions for %d.\n",N);
        }


    }
}