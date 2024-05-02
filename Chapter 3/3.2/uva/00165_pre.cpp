#include<cstdio>
#include<unordered_map>
#include<set>
#include<vector>

using namespace std;
unordered_map<int,int> ranges {};
unordered_map<int,vector<int>> bestCoins {};
int coins[9] {};
int h, k;
int currSum {};
int prevIdx;
int currMax {};
set<int> sums {};

void backtrack(int pos){
    if(pos==h){
        sums.emplace(currSum);
        return;
    }

    if(prevIdx==-1){
        backtrack(pos+1);
    }

    for(int idx=prevIdx;idx<k;idx++){
        int savedPrev = prevIdx;
        prevIdx=idx;
        currSum += coins[idx];

        backtrack(pos+1);

        currSum -= coins[idx];
        prevIdx = savedPrev;
    }

}

void testConfigs(int pos){
    if(pos == k){
        prevIdx = -1;
        sums.clear();
        backtrack(0);

        auto prev {sums.begin()};
        auto curr {++(sums.begin())};

        while(curr != sums.end() && (*prev)+1 == (*curr)){
            ++prev;
            ++curr;
        }

        if((*prev) > currMax){
            ranges[10*h + k] = *prev;
            vector<int> temp {};
            for(int i=0;i<k;i++){
                temp.push_back(coins[i]);
            }
            bestCoins[10*h+k]=temp;
            currMax=*prev;
        }
        return;
    }

    if(pos == 0){
        coins[pos] = 1;
        testConfigs(pos+1);
    } else {
        int maxBound {1+ranges[10*h + pos]};
        for(int i=coins[pos-1]+1;i<=maxBound;i++){
            coins[pos] = i;
            testConfigs(pos+1);
        }
    }
}

int main(){

    for(int i=1;i<9;i++){
        ranges[10+i] = i;
        ranges[10*i + 1] = i;
    }

    for(h=1;h<9;h++){
        for(k=1;h+k<=9;k++){
            currMax = 0;
            testConfigs(0);
            printf("{%d,\"",10*h+k);
            for(int c: bestCoins[10*h+k]){
                printf("%3d",c);
            }
            printf(" ->%3ld\"},\n",ranges[10*h+k]);
        }
    }
}