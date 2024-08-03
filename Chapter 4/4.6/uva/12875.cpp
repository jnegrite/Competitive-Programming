#include<iostream>
#include<cstring>

using namespace std;

int nCities, nConcerts;
int memo[50][100] {};
bool visited[50][100] {};
int travelCost[100][100] {};
int concertProfit[100][50] {};

int dp(int concert, int city){
    if(concert == nConcerts-1){
        return concertProfit[city][concert];
    }

    bool &flag {visited[concert][city]};
    auto &curr {memo[concert][city]};
    if(flag){
        return curr;
    }

    flag = true;

    curr = dp(concert+1,0) - travelCost[city][0];

    for(int i=1;i<nCities;++i){
        curr = max(curr, dp(concert+1,i) - travelCost[city][i]);
    }

    curr += concertProfit[city][concert];
    return curr;
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        memset(memo,-1,sizeof(memo));
        memset(visited,false,sizeof(visited));

        cin >> nCities >> nConcerts;

        for(int i=0;i<nCities;++i){
            for(int j=0;j<nConcerts;++j){
                cin >> concertProfit[i][j];
            }
        }

        for(int i=0;i<nCities;++i){
            for(int j=0;j<nCities;++j){
                cin >> travelCost[i][j];
            }
        }

        int ans {dp(0,0)};
        for(int i=0;i<nCities;++i){
            ans = max(ans,dp(0,i));
        }
        cout << ans << '\n';

    }
}