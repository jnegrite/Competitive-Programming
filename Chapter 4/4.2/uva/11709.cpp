#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<stack>



using namespace std;

string s, s1 ,s2;
int id1, id2;
int nPeople;
int nRelations;

vector<string> names {};
unordered_map<string, int> mapNames {};
vector<vector<int>> paths {};
vector<vector<int>> pathsRev {};
vector<bool> visited {};
stack<int> ts {};

void kosaraju(int pos, bool forwards){
    visited[pos] = true;
    auto &curr {forwards ? paths[pos] : pathsRev[pos]};

    for(int &nxt:curr){
        if(!visited[nxt]){
            kosaraju(nxt,forwards);
        }
    }

    if(forwards){
        ts.push(pos);
    }
}

int main(){
    while(getline(cin,s),s!="0 0"){
        auto pos {s.find(' ')};
        nPeople = stoi(s.substr(0,pos));
        nRelations = stoi(s.substr(pos+1));

        names.clear();
        names.reserve(nPeople);
        mapNames.clear();
        paths.assign(nPeople,{});
        pathsRev.assign(nPeople,{});
        for(int i=0;i<nPeople;++i){
            getline(cin,s);
            mapNames[s] = names.size();
            names.push_back(s);
        }

        while(nRelations--){
            getline(cin,s1);
            getline(cin,s2);
            id1 = mapNames[s1];
            id2 = mapNames[s2];

            paths[id1].push_back(id2);
            pathsRev[id2].push_back(id1);
        }

        //fowards
        visited.assign(nPeople,false);
        for(int i=0;i<nPeople;++i){
            if(!visited[i]){
                kosaraju(i,true);
            }
        }

        //backwards
        visited.assign(nPeople,false);
        int nSCC {};
        while(!ts.empty()){
            if(!visited[ts.top()]){
                ++nSCC;
                kosaraju(ts.top(),false);
            }
            ts.pop();
        }

        cout << nSCC << '\n';
    }
    
}