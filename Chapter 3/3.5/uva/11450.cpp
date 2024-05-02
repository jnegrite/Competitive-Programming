#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAX_M {201};
const int MAX_C {21};
int m, c, curr;

int memo[MAX_C][MAX_M] {};
vector<vector<int>> garments {};

int dp(int g, int b){
    if(b<0){
        return -2;
    }

    if(g == c){
        return m - b;
    }

    auto ans {memo[g][b]};
    if(ans != -1){
        return ans;
    }

    for(auto px:garments[g]){
        ans = max(ans,dp(g+1,b-px));
    }

    return memo[g][b] = ans;
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        
        cin >> m >> c;
        memset(memo,-1,sizeof(memo));
        
        garments.clear();
        garments.assign(c,{});
        for(int g=0;g<c;++g){
            int k;
            cin >> k;
            while(k--){
                cin >> curr;
                garments[g].push_back(curr);
            }
        }

        //do dp
        int ans {dp(0,m)};
        if(ans < 0){
            cout << "no solution\n";
        } else {
            cout << ans << '\n';
        }
    }
}