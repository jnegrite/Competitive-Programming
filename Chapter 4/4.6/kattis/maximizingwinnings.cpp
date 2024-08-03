#include<iostream>
#include<cstring>

using namespace std;

int nRooms, nTurns;
int memoMax[5000][50] {};
int memoMin[5000][50] {};
int costs[50][50] {};

pair<int,int> dp(int pos, int room){
    if(pos == nTurns){
        return {0, 0};
    }

    auto &currMax {memoMax[pos][room]};
    auto &currMin {memoMin[pos][room]};

    if(currMax != -1){
        return {currMin, currMax};
    }

    pair<int,int> baseDP {dp(pos+1,0)};

    currMin = costs[room][0] + baseDP.first;
    currMax = costs[room][0] + baseDP.second;

    for(int i=1;i<nRooms;++i){
        baseDP = dp(pos+1,i);
        currMin = min(currMin,costs[room][i] + baseDP.first);
        currMax = max(currMax,costs[room][i] + baseDP.second);
    }

    return {currMin,currMax};
}

int main(){
    while(cin >> nRooms, nRooms > 0){
        for(int i=0;i<nRooms;++i){
            for(int j=0;j<nRooms;++j){
                cin >> costs[i][j];
            }
        }
        cin >> nTurns;

        memset(memoMax,-1,sizeof(memoMax));
        memset(memoMin,-1,sizeof(memoMin));

        auto ans {dp(0,0)};

        cout << ans.second << ' ' << ans.first << '\n';
    }
}