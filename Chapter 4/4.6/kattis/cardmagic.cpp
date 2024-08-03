#include<iostream>
#include<cstring>

using namespace std;

int nDecks;
int nCards;
int nTarget;

int memo[100][50001] {};

int dp(int pos, int rem){
    if(pos == nDecks-1){
        if(rem > 0 && rem <= nCards){
            return 1;
        } else {
            return 0;
        }
    }

    if(rem <= 0){
        return 0;
    }

    auto &curr {memo[pos][rem]};
    if(curr != -1){
        return curr;
    }

    curr = 0;
    for(int i=1;i<=min(rem,nCards);++i){
        curr += dp(pos+1,rem-i);
        curr %= 1000000009;
    }

    return curr;
}


int main(){
    cin >> nDecks >> nCards >> nTarget;
    memset(memo,-1,sizeof(memo));

    cout << dp(0,nTarget) << '\n';
}