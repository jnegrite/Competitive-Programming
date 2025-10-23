#include<iostream>
#include<cstring>

using namespace std;

int memo[31] {};

int dp(int pos){
    if(pos%2){
        return 0;
    }

    if(pos == 0){
        return 1;
    }

    auto &curr {memo[pos]};
    if(curr != -1){
        return curr;
    }

    curr = 3 * dp(pos-2);
    for(int i=4;i<=pos;i+=2){
        curr += 2 * dp(pos-i);
    }

    return curr;
}

int main(){
    memset(memo,-1,sizeof(memo));

    int val;
    while(cin >> val, val != -1){
        cout << dp(val) << '\n';
    }
}
