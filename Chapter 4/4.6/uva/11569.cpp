#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<cstring>

using namespace std;

int getVal(char ch){
    if(ch < 'A' || ch > 'Z'){
        return 0;
    } else {
        return (ch - 'A') + 1;
    }
}

set<int> knownVals {};
vector<int> vVals {};
int prevVal {};
int maxLen {};

int memo[26][26] {};

int dp(int pos, int rem){
    if(rem == 0){
        return 1;
    }
    if(pos == vVals.size()){
        return 0;
    }

    auto &curr {memo[pos][rem]};
    if(curr != -1){
        return curr;
    }

    curr = 0;
    for(int i=pos+1;i<=vVals.size();++i){
        if(i==vVals.size() || 
            (vVals[pos]*5 <= vVals[i]*4)){
            curr += dp(i,rem-1);
        }
    }
    return curr;
}

int main(){
    int nCases;
    string s;
    getline(cin, s);
    nCases = stoi(s);
    while(nCases--){
        memset(memo,-1,sizeof(memo));
        knownVals.clear();
        vVals.clear();
        getline(cin,s);

        for(char ch:s){
            int val {getVal(ch)};
            if(val > 0){
                knownVals.emplace(val);
            }
        }

        vVals.reserve(knownVals.size());
        prevVal = 0;
        maxLen = 0;
        for(auto it {knownVals.begin()};it!=knownVals.end();++it){
            vVals.push_back(*it);
            if(prevVal*5 <= ((*it) * 4)){
                ++maxLen;
                prevVal = *it;
            }
        }
        int ans {0};
        if(maxLen != 0){
            for(int i=0;i<=vVals.size()-maxLen;++i){
                ans += dp(i,maxLen);
            }
        }
        cout << maxLen << ' ' << ans << '\n';
    }
}