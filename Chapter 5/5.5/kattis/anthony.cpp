#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

int iAnthony, iCora;
double memo[2002][1001] {};
bool visited[2002][1001] {};

double p[2001] {};

double dp(int roundNumber, int anthony, int cora){
    if(anthony == 0){
        return 0;
    }

    if(cora <= 0){
        return 1;
    }

    double &ans {memo[roundNumber][anthony]};
    if(visited[roundNumber][anthony]){
        return ans;
    }

    visited[roundNumber][anthony] = true;
    ans = (p[roundNumber]) * dp(roundNumber+1,anthony,cora-1) + (1-p[roundNumber]) * dp(roundNumber+1,anthony-1,cora);

    return ans;
}

int main(){
    cin >> iAnthony >> iCora;
    int lastIdx {iAnthony+iCora-1};

    for(int i=0;i<=lastIdx;++i){
        cin >> p[i];
    }
    
    memset(memo, 0, sizeof(memo));
    memset(visited, false, sizeof(visited));

    cout << fixed << setprecision(7) << dp(0,iAnthony,iCora) << '\n';

}