#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<set>
#include<stack>

using namespace std;

vector<string> stations {};
unordered_map<string,int> mapStations {};
vector<set<int>> paths {};
vector<bool> visited {};
stack<int> finPath {};
int startIdx;
int endIdx;


int getNum(const string &s){
    auto it {mapStations.find(s)};
    if(it!=mapStations.end()){
        return it->second;
    }

    int ans = mapStations[s] = stations.size();
    stations.push_back(s);
    paths.push_back({});
    visited.push_back(false);
    return ans;
}

bool process(int pos){
    if(visited[pos]){
        return false;
    }

    if(pos == endIdx){
        return true;
    }
    visited[pos] = true;
    for(auto it{paths[pos].begin()};it!=paths[pos].end();++it){
        if(process(*it)){
            finPath.push(pos);
            return true;
        }
    }
    return false;
}

int main(){
    int nMaps{};
    string s;
    getline(cin,s);
    nMaps = stoi(s);

    while(nMaps--){
        getline(cin,s);
        auto strIn {stringstream(s)};
        string sFrom;
        int idxFrom, idxTo;
        strIn >> sFrom;
        idxFrom = getNum(sFrom);
        while(strIn >> s){
            idxTo = getNum(s);
            paths[idxFrom].emplace(idxTo);
            paths[idxTo].emplace(idxFrom);
        }
    }

    cin >> s;
    startIdx = getNum(s);
    cin >> s;
    endIdx = getNum(s);
    
    if(process(startIdx)){
        while(!finPath.empty()){
            cout << stations[finPath.top()] << ' ';
            finPath.pop();
        }
        cout << stations[endIdx] << '\n';
    } else {
        printf("no route found\n");
    }
}