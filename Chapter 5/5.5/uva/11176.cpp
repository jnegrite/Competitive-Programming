#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

float memo[501][501] {};
bool visited[501][501] {};
double probs[501] {};

int n;
double p;

//expected length of streak given n remaining games and current streak
float dp(int remGames, int currStreak){
    if(remGames <= 0){
        return currStreak;
    }

    float &ans {memo[remGames][currStreak]};

    if (visited[remGames][currStreak]){
        return ans;
    }
    
    visited[remGames][currStreak] = true;
    ans = 0;

    int nextStreak;

    for(int i=0;i<remGames;++i){
        nextStreak = max(currStreak,i);
        ans += probs[i]*(1-p)*max(static_cast<float>(nextStreak),dp(remGames-i-1,nextStreak));
    }

    nextStreak = max(currStreak,remGames);
    //win all the next games
    ans += probs[remGames]*max(static_cast<float>(nextStreak),dp(0,nextStreak));

    return ans;
}

int main(){
    while(cin >> n >> p, n != 0){
        memset(memo,0,sizeof(memo));
        memset(visited,false,sizeof(visited));
        
        probs[0] = 1;
        for(int i=1;i<=n;++i){
            probs[i] = probs[i-1] * p;
        }
        
        cout << fixed << setprecision(6) << dp(n,0) << '\n';
    }
}