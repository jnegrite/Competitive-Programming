#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>

using namespace std;

unordered_map<char,int> mapNode {};
vector<set<char>> paths {};
vector<bool> visited {};
vector<int> sorted {};
vector<int> numPaths {};
int nIntersections {};
int nRoads {};
int currEnd {};

int getCode(char ch){
    auto it (mapNode.find(ch));
    if(it != mapNode.end()){
        return it->second;
    }

    auto ans {mapNode.size()};
    return mapNode[ch] = ans;
}

void topsort(int pos){
    if(visited[pos]) return;

    visited[pos] = true;
    for(char nxt: paths[pos]){
        topsort(getCode(nxt));
    }
    sorted.push_back(pos);
}

void processCounts(){
    numPaths.assign(nIntersections,0);
    for(int pos: sorted){
        if(paths[pos].size() == 0){
            numPaths[pos] = 1;
        } else {
            for(auto nxt: paths[pos]){
                numPaths[pos] += numPaths[getCode(nxt)];
            }
        }
    }
}

int countPaths(string s){
    int ans {0}; 
    for(int i=0;i<(s.length()-1);i++){
        char currCh {s.at(i)};
        char nxtCh {s.at(i+1)};
        auto &nxtPaths {paths[getCode(currCh)]};
        for(auto nxt {nxtPaths.begin()};nxt!=nxtPaths.end();++nxt){
            if(*nxt == nxtCh){
                break;
            }
            ans += numPaths[getCode(*nxt)];
        }
    }
    return ++ans;
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        mapNode.clear();
        paths.clear();
        sorted.clear();
        numPaths.clear();
        currEnd = -1;

        cin >> nIntersections >> nRoads;
        paths.assign(nIntersections,{});
        visited.assign(nIntersections,false);
        numPaths.assign(nIntersections,0);

        string s;
        int id1, id2;
        while(nRoads--){
            cin >> s;
            id1 = getCode(s.at(0));
            id2 = getCode(s.at(1));

            paths[id1].emplace(s.at(1));
        }
        for(int i=0;i<nIntersections;++i){
            topsort(i);
        }

        int nQueries;
        cin >> nQueries;
        processCounts();
        while(nQueries--){
            cin >> s;
            cout << s << ": " << countPaths(s) << '\n';
        }
    }
}