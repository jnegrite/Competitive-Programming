#include<iostream>
#include<vector>
#include<cstring>

#define LSOne(x) ((x) & -(x))

using namespace std;

string curr;
vector<int> paths {};
int initArsenal {};
int N;

long long memo[17][1<<17] {};
int memoArsenal[1<<17] {};

//converts string representation to mask
int stringToMask(string s){
    int ans {};
    for(int i=0;i<=N;i++){
        if(s.at(i) == '1'){
            ans |= (1<<i);
        }
    }
    return ans;
}

void propagateArsenal(int idx){
    if(idx == 0){
        return;
    }

    int masks {idx};
    while(masks != 0){
        int flag {LSOne(masks)};
        int target {__builtin_ctz(flag)};
        int nxtIdx {idx - flag};

        if(memoArsenal[nxtIdx] == -1){
            memoArsenal[nxtIdx] = memoArsenal[idx] | paths[target];
            propagateArsenal(nxtIdx);
        }
        masks -= flag;
    }
}

long long dp(int pos, int mask){
    if(mask==0){
        return 1;
    }

    auto &curr {memo[pos][mask]};

    if(curr != -1){
        return curr;
    }

    curr = 0; 
    int tMask {mask & memoArsenal[mask]};
    while(tMask!=0){
        int flag {LSOne(tMask)};
        int target {__builtin_ctz(flag)};
        curr += dp(target, mask ^ flag);
        tMask -= flag;
    }

    return curr;
}

int main(){
    int nCases;
    cin >> nCases;

    for(int tc=1;tc<=nCases;++tc){
        //clear
        paths.clear();
        cin >> N;


        //row maps
        for(int i=0;i<=N;++i){
            cin >> curr;
            paths.push_back(stringToMask("0"+curr));
        }

        //initialize arsenal map
        memset(memoArsenal,-1,sizeof(memoArsenal));
        memoArsenal[(1<<(N+1))-1] = 0;
        propagateArsenal((1<<(N+1))-1);

        //do dp
        memset(memo,-1,sizeof(memo));
        cout << "Case " << tc << ": " << dp(0,(1<<(N+1))-2) << "\n";

    }   

}