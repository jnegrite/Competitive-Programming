#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int nJack, nJill;
int wordsJack[500][26] {};
int wordsJill[500][26] {};

vector<vector<int>> paths {};
vector<int> match {};
vector<bool> visited {};

bool canSolve(int a, int b){
    auto &tA {wordsJack[a]};
    auto &tB {wordsJill[b]};

    for(int i=0;i<26;++i){
        if(tA[i] < tB[i]) return false;
    }
    return true;
}

int aug(int L){
    if(visited[L]) return 0;

    visited[L] = true;
    for(int nxt: paths[L]){
        if((match[nxt] == -1) || aug(match[nxt])){
            match[nxt] = L;
            return 1;
        }
    }
    return 0;
}

int main(){
    string s;
    while(cin >> nJack >> nJill){
        memset(wordsJack,0,sizeof(wordsJack));
        memset(wordsJill,0,sizeof(wordsJill));

        for(int i=0;i<nJack;++i){
            cin >> s;
            auto &target {wordsJack[i]};
            for(char ch:s){
                ++target[ch-'a'];
            }            
        }

        for(int i=0;i<nJill;++i){
            cin >> s;
            auto &target {wordsJill[i]};
            for(char ch:s){
                ++target[ch-'a'];
            }            
        }

        paths.assign(nJack,{});
        match.assign(nJill,-1);

        for(int i=0;i<nJack;++i){
            for(int j=0;j<nJill;++j){
                if(canSolve(i,j)){
                    paths[i].push_back(j);
                }
            }
        }

        int ans {};
        for(int i=0;i<nJack;++i){
            visited.assign(nJack,false);
            ans += aug(i);
        }
        cout << ans << '\n';
    }
}