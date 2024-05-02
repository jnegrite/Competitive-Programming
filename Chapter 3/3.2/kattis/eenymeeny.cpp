#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    int k{0};
    auto strIn {stringstream(s)};
    string temp;
    while(strIn>>temp){
        k++;
    }

    int nPlayers;
    getline(cin,s);
    nPlayers = stoi(s);
    queue<int> q {};
    vector<string> players{};
    vector<vector<int>> groups {{},{}};

    int currGroup {0};
    for(int i=0;i<nPlayers;i++){
        getline(cin,s);
        players.push_back(s);
        q.push(i);
    }

    //simulate
    while(!q.empty()){
        for(int i=1;i<k;i++){
            q.push(q.front());
            q.pop();
        }

        //place
        groups[currGroup].push_back(q.front());
        q.pop();
        currGroup ^= 1;
    }

    for(int i=0;i<2;i++){
        cout << groups[i].size() << '\n';
        for(auto p:groups[i]){
            cout << players[p] << '\n';
        }
    }
}