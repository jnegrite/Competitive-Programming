#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

int nLanguages, nTranslations;
vector<string> languages {};
unordered_map<string,int> mapLanguages {};
vector<vector<pair<int,int>>> paths {};

int main(){
    cin >> nLanguages >> nTranslations;
    languages.assign(nLanguages,"");
    paths.assign(nLanguages+1, {});
    
    for(int i=0;i<nLanguages;i++){
        cin >> languages[i];
        mapLanguages[languages[i]] = i;
    }
    mapLanguages["English"] = nLanguages;
    languages.push_back("English");

    //get translations
    string s1, s2;
    int cost;
    int idxA, idxB;
    for(int i=0;i<nTranslations;i++){
        cin >> s1 >> s2 >> cost;
        idxA = mapLanguages[s1];
        idxB = mapLanguages[s2];

        paths[idxA].emplace_back(idxB,cost);
        paths[idxB].emplace_back(idxA,cost);
    }

    //get priority_queue
    //tuple<effective cost, node>
    vector<bool> visited {};
    visited.assign(languages.size(),false);

    priority_queue<tuple<int,int,int>> q{};

    //add seed node
    q.push({0,0,mapLanguages["English"]});

    int totalCost {};
    while(!q.empty()){
        auto curr {q.top()};
        q.pop();

        //skip if visited
        int jumps {get<0>(curr)};
        int cost {get<1>(curr)};
        int node {get<2>(curr)};

        if(visited[node]) continue;

        visited[node] = true; 

        //check if one of the targets
        totalCost -= cost;

        //process next nodes
        for(auto nxt: paths[node]){
            int nxtNode {nxt.first};

            if(visited[nxtNode]) continue;
            
            q.push({jumps-1,-nxt.second,nxt.first});
        }
    }

    bool hasUnvisited {false};
    for(int i=0;i<nLanguages;i++){
        if(!visited[i]){
            hasUnvisited = true;
        }
    }

    if(hasUnvisited){
        cout << "Impossible\n";
    } else {
        cout << totalCost << '\n';
    }

}