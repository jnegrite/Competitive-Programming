#include<cstdio>
#include<vector>
#include<unordered_set>
#include<malloc.h>
#include<algorithm>

using namespace std;

unordered_set<long> uniqueWeights {};
vector<vector<long>> weights {{},{}};
vector<long> vWeights {};

bool isValid(long weight){
    for(auto row: weights){
        long prev = -1;
        for(long v: row){
            if(v <= weight){

            } else if (prev == -1){
                prev = v;
            } else if (v == prev){
                prev = -1;
            } else {
                return false;
            }
        }

        if(prev != -1){
            return false;
        }
    }
    return true;
}

int main(){
    long nWeights;
    scanf("%ld\n",&nWeights);
    
    vWeights.reserve(1+nWeights);
    vWeights.push_back(0);
    
    long curr;
    for(int row=0;row<2;++row){
        weights[row].reserve(nWeights);
        for(long i=0;i<nWeights;++i){
            scanf("%ld",&curr);
            weights[row].push_back(curr);
            if(uniqueWeights.count(curr)==0){
                vWeights.push_back(curr);
                uniqueWeights.emplace(curr);
            }
        }
    }

    sort(vWeights.begin(),vWeights.end());

    long low {0};
    long high {nWeights};
    long mid;
    while(low<high){
        mid = (low+high)>>1;
        if(isValid(vWeights[mid])){
            high = mid;
        } else {
            low = mid+1;
        }
    }
    printf("%ld\n",vWeights[low]);
}