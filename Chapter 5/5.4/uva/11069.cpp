#include<iostream>
#include<cstring>

using namespace std;

long long memo[77] {};

long long dp(int pos){

    if(pos <= 0){
        return 0;
    }

    auto &curr {memo[pos]};

    if(curr != -1){
        return curr;
    }

    curr = 0;
    if(pos <= 2){
        curr = 1;
    }

    curr += dp(pos-2) + dp(pos-3);
    return curr;

}

int main(){
    memset(memo,-1,sizeof(memo));

    int val;
    while(cin >> val){
        long long ans {dp(val)};

        if(val > 1){
            ans += dp(val-1);
        }

        cout << ans << '\n';
    }
}