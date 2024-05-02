#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int counts[51] {};
int nBuckets;
int stickLength;

bool backtrack(int maxLen, int currSize, int bucketNum){
    if(currSize == stickLength){
        if(bucketNum+1 == nBuckets){
            return true;
        }
        return backtrack(50,0,bucketNum+1);
    }

    
    if(currSize==0){
        int i {50};
        while(counts[i] == 0){
            --i;
        }

        return backtrack(i,i,bucketNum);
    }

    for(int i=min(maxLen,stickLength-currSize);i>0;i--){
        if(counts[i] == 0){
            --counts[i];
            currSize+=i;

            if(currSize==stickLength){
                if(backtrack(maxLen,0,bucketNum+1)){
                    return true;
                }
            } else {
                if(backtrack(50,currSize,bucketNum)){
                    return true;
                }
            }

            currSize-=i;
            ++counts[i];
        }
    }
    return false;
}

int main(){
    int nValues{};
    while(scanf("%d\n",&nValues),nValues > 0){
        memset(counts,0,sizeof(counts));
        int curr;
        int total {};
        int minLength {50};
        int maxLength {0};
        for(int i=0;i<nValues;i++){
            scanf("%d",&curr);
            ++counts[curr];
            total += curr;
            if(curr<minLength){
                minLength = curr;
            }
            if(curr>maxLength){
                maxLength = curr;
            }
        }

        int ans {total};

        for(stickLength=maxLength;stickLength <= (total>>1);stickLength++){
            if(total%stickLength != 0){
                continue;
            }

            nBuckets = total/stickLength;

            if(backtrack(50,0,0)){
                ans = stickLength;
                break;
            }
        }

        printf("%d\n",ans);
    }
}