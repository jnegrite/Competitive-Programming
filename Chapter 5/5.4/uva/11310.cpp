#include<iostream>
#include<cstring>

using namespace std;

long long memo[41] {};

long long dp(long long pos){
    if(pos < 0){
        return 0;
    }
    if(pos <= 1){
        return 1;
    }

    auto &curr {memo[pos]};
    if(curr != -1){
        return curr;
    }

    curr = dp(pos-1) + 4 * dp(pos-2) + 2*dp(pos-3);

    return curr;
}

int main(){
    memset(memo,-1,sizeof(memo));

    long long nCases, val;
    cin >> nCases;
    while(nCases--){
        cin >> val;
        cout << dp(val) << '\n';
    }
}