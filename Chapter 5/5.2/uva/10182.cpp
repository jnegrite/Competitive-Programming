#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<pair<int,int>> moves {
    {-1,1},
    {-1,0},
    {0,-1},
    {1,-1},
    {1,0},
    {0,1}
};

pair<int,int> getLoc(int pos){
    if(pos == 1){
        return {0,0};
    }

    --pos;

    int completed = pos / 6;

    completed = (sqrt(1 + 8 * completed)-1)/2;
    int rem = pos - 3*completed * (completed+1);
    if(rem==0){
        return {completed,0};
    }

    pair<int,int> ans {completed,1};
    --rem;

    //first path
    int nxtDiff {min(rem, completed)};
    ans.first += nxtDiff*(moves[0].first);
    ans.second += nxtDiff*(moves[0].second);
    rem-=nxtDiff;

    for(int i=1;i<6 && rem>0;++i){
        nxtDiff = min(rem, completed+1);
        ans.first += nxtDiff*(moves[i].first);
        ans.second += nxtDiff*(moves[i].second);
        rem -= nxtDiff;
    }

    return ans;
}

int main(){
    int n;
    while(cin >> n){
        auto ans {getLoc(n)};
        cout << ans.first << ' ' << ans.second << '\n';
    }
}