#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int memo[27][27][500];

int dp(int startingLetter, int availPos, int length){
    if(length <= 0){
        return 0;
    }

    if(availPos == 1){
        if(length <= 26 && length > startingLetter){
            return 1;
        } else {
            return 0;
        }
    }

    auto &curr {memo[startingLetter][availPos][length]};
    if(curr != -1){
        return curr;
    }

    curr = 0;
    for(int letter {startingLetter+1}; letter <= 26; letter++){
        curr += dp(letter,availPos-1,length-letter);
    }

    return curr;
}

int main(){
    int l, s;
    int tc {};
    memset(memo,-1,sizeof(memo));

    while(scanf("%d %d\n",&l,&s), l!=0 || s!=0){
        l = min(26,l);
        int ans {};
        if( s> 500){
            ans = 0;
        } else {
            ans = dp(0,l,s);
        }
        printf("Case %d: %d\n",++tc,ans);
    }
}