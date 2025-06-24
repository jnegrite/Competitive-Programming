#include<iostream>
#include<cstring>

using namespace std;

long long memo[10002][2] {};

long long dp(int len, int lastDigit){
    
    long long &curr{memo[len][lastDigit]};

    if(curr != -1){
        return curr;
    }
    
    if(len == 0){
        curr = 1;
    } else {
        curr = dp(len-1, 0);

        if(lastDigit == 0){
            curr += dp(len-1,1);
            curr %= 1000000007;
        }
    }

    return curr;
}

int main(){
    int nCases;

    cin >> nCases;

    int val;

    memset(memo,-1,sizeof(memo));

    while(nCases--){
        cin >> val;
        cout << dp(val,0) << '\n';
    }
}