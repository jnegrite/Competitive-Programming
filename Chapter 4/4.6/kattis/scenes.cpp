#include<iostream>
#include<cstring>

using namespace std;

int totalLength, width, height;
int memo[100][10001] {};
const int mod {1000000007};

int dp(int pos, int rem){
    if(pos == width){
        return 1;
    }

    auto &curr {memo[pos][rem]};
    if(curr != -1){
        return curr;
    }

    curr = 0;
    int maxVal {min(height,rem)};
    for(int i=0;i<=maxVal;++i){
        curr += dp(pos+1,rem-i);
        curr %= mod;
    }
    return curr;
}

int main(){
    memset(memo,-1,sizeof(memo));
    cin >> totalLength >> width >> height;

    int ans {dp(0, totalLength)};
    ans -= (1+min(height,totalLength/width));
    cout << ans << '\n';
}