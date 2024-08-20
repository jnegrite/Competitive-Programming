#include<iostream>
#include<vector>

using namespace std;

int nPeople;
vector<bool> visited {};
vector<int> match{};
vector<vector<int>> paths {};

bool aug(int L){
    if(visited[L]) return false;

    visited[L] = true;

    for(int nxt: paths[L]){
        if((match[nxt] == -1) || aug(match[nxt])){
            match[nxt] = L;
            return true;
        }
    }

    return false;
}

int main(){
    int nLinks;
    cin >> nPeople >> nLinks;
    
    paths.assign(nPeople,{});
    match.assign(nPeople,-1);

    int a, b;
    while(nLinks--){
        cin >> a >> b;
        paths[a].push_back(b);
    }

    bool isOk {true};
    for(int i=0;isOk && i<nPeople;++i){
        visited.assign(nPeople,false);
        if(!aug(i)){
            isOk = false;
        }
    }

    if(isOk){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}