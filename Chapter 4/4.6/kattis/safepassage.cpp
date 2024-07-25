#include<iostream>
#include<cstring>
#include<bitset>

#define LSOne(x) ((x) & (-x))

using ui = unsigned int;
using namespace std;

int nPoints {};
int values[15] {};
int memo[2][1<<15] {};
int state[2][1<<15] {};
ui mainMask {};

int dp(int pos, ui currMask){
    if(pos == 1 && currMask == 0){
        return 0;
    }

    switch(state[pos][currMask]){
        case 0:
            return -1;
        case 1:
            return memo[pos][currMask];
    }
    
    auto &curr {memo[pos][currMask]};
    if(curr != -1){
        return curr;
    }

    state[pos][currMask] = 0;
    
    ui maskToUse {currMask};
    if(pos==1){
        maskToUse = (mainMask & (~currMask));
    }

    curr = -1;
    if(maskToUse == 0u){
        curr = -2;
    } else {
        ui subMask {maskToUse};
        while(subMask != 0u){
            //extract last bit
            ui m1 {LSOne(subMask)};
            int pos1 {__builtin_ctz(m1)};

            if(pos==1){
                //try solo
                int v1 {dp(0, currMask + m1)};
                if (v1 >= 0){
                    int tempTime {values[pos1] + v1};   
                    if((curr<0) || (tempTime < curr)){
                        curr = values[pos1] + v1;
                    }
                }
            } else {
                //try with a friend
                ui subsubMask {subMask ^ m1};
                while(subsubMask != 0u){
                    ui m2 {LSOne(subsubMask)};
                    int pos2 {__builtin_ctz(m2)};
                    int v2 {dp(1,currMask-(m1+m2))};

                    if(v2 >= 0) {
                        int speed {max(values[pos1],values[pos2])};
                        int tempTime {speed + v2};

                        if((curr<0) ||  (tempTime < curr)){
                            curr=tempTime;
                        }
                    }
                    subsubMask -= m2;
                }
            }
            subMask -= m1;
        }
    }
    state[pos][currMask] = 1;
    return curr;
}

int main(){
    cin >> nPoints;
    memset(memo,-1,sizeof(memo));
    memset(state,-1,sizeof(state));
    mainMask = (1u<<nPoints)-1u;
    for(int i=0;i<nPoints;++i){
        cin >> values[i];
    }
    cout  << dp(0,mainMask);
}