#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> path {1};
vector<map<int,bool>> edges {};

vector<pair<int,int>> edgeList{
    {1,2},
    {1,3},
    {1,5},
    {2,3},
    {2,5},
    {3,4},
    {3,5},
    {4,5}
};

void dfs(int pos){
    if(path.size()==9){
        for(int val:path){
            cout << val;
        }
        cout << '\n';
        return;
    }

    for(auto it {edges[pos].begin()}; it != edges[pos].end(); ++it){
        if(it->second) continue;

        edges[pos][it->first] = edges[it->first][pos] = true;
        path.push_back(it->first);

        dfs(it->first);

        path.pop_back();
        edges[pos][it->first] = edges[it->first][pos] = false;
    }
}

int main(){
    edges.assign(6,{});
    for(auto &pr:edgeList){
        edges[pr.first][pr.second] = edges[pr.second][pr.first] = false;
    }

    dfs(1);
}