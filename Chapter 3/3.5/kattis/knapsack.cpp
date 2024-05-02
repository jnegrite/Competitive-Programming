#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

vector<int> usedItems {};

int nObjects;
long df[2000][2] {};
long memo[2000][2000] {};

long dp(int idx, int remWeight){
    if(idx == nObjects || remWeight <= 0){
        return 0;
    }

    long &ans {memo[idx][remWeight]};
    if(ans != -1){
        return ans;
    }

    if(remWeight < df[idx][1]){
        return ans = dp(idx+1,remWeight);
    }

    return ans = max(dp(idx+1,remWeight), df[idx][0] + dp(idx+1,remWeight - df[idx][1]));
}

void extractPath(int idx, int remWeight){
    if(idx == nObjects || remWeight <= 0){
        return;
    }
    
    //case when forced to skip
    if(remWeight - df[idx][1] < 0){
        extractPath(idx+1,remWeight);
        return;
    }

    if(df[idx][0] + dp(idx+1,remWeight - df[idx][1]) > dp(idx+1,remWeight)){
        usedItems.push_back(idx);
        extractPath(idx+1, remWeight-df[idx][1]);
    } else {
        extractPath(idx+1, remWeight);
    }
}

int main(){
    int capacity;


    long cVal, cWeight;

    
    while(scanf("%d %d\n",&capacity,&nObjects)!= EOF){
        for(int i=0;i<nObjects;++i){
            scanf("%ld %ld\n", &df[i][0], &df[i][1]);
        }
        
        memset(memo,-1,sizeof(memo));
        dp(0, capacity);
        
        usedItems.clear();
        extractPath(0, capacity);

        printf("%d\n", usedItems.size());
        if(!usedItems.empty()){
            printf("%d",usedItems[0]);
        }

        for(int i=1;i<usedItems.size();++i){
            printf(" %d",usedItems[i]);
        }
        printf("\n");
    }
}