#include<iostream>
#include<cstring>

using namespace std;

int nCards;
int cards[50000][2] {};
int matches[100001] {};
bool visited[50000] {};

bool aug(int pos){
    if(visited[pos]) return false;

    visited[pos] = true;
    for(int nxt: cards[pos]){
        if((matches[nxt] == -1) || aug(matches[nxt])){
            matches[nxt] = pos;
            return true;
        }
    }
    return false;
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        cin >> nCards;
        memset(visited,false,sizeof(visited));
        memset(matches,-1,sizeof(matches));
        
        for(int i=0;i<nCards;++i){
            cin >> cards[i][0] >> cards[i][1];
        }

        bool isOk {true};
        for(int i=0;isOk && i<nCards;++i){
            memset(visited,false,sizeof(visited));
            if(!aug(i)){
                isOk = false;
            }
        }

        if(isOk){
            cout << "possible\n";
        } else {
            cout << "impossible\n";
        }
    }
}