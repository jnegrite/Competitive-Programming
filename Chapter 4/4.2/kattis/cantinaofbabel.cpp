#include<iostream>
#include<sstream>
#include<unordered_map>
#include<vector>
#include<stack>

using namespace std;
using vi = vector<int>;

int nCharacters {};
vector<pair<vi,vi>> languages {};
unordered_map<string,int> langMap {};
vector<vi> paths {};
vector<vi> pathsRev {};
vector<bool> visited {};
stack<int> ts {};
int ctr {};

int getIdx(const string &s){
    auto it {langMap.find(s)};
    if(it != langMap.end()){
        return it->second;
    }

    int ans = languages.size();
    langMap[s] = ans;
    languages.push_back({});
    return ans;
}

int findSCC(int pos, bool forward){
    visited[pos] = true;
    vi &curr {forward?paths[pos]:pathsRev[pos]};
    int ans {1};
    for(int &nxt:curr){
        if(!visited[nxt]){
            ans += findSCC(nxt,forward);
        }
    }

    if(forward){
        ts.push(pos);
    }
    return ans;
}

string s;
int main(){
    cin >> nCharacters >> ws;
    for(int i=0;i<nCharacters;++i){
        getline(cin,s);
        auto strIn {stringstream(s)};
        //name
        strIn >> s;

        //languages 
        vector<string> currLangs {};
        while(strIn >> s){
            currLangs.push_back(s);
        }

        //process understood languages
        for(string s:currLangs){
            int idx {getIdx(s)};
            languages[idx].second.push_back(i);
        }

        //process spoken languages
        int idx{getIdx(currLangs[0])};
        languages[idx].first.push_back(i);
    }
    
    paths.assign(nCharacters,{});
    pathsRev.assign(nCharacters,{});

    for(auto &curr:languages){
        for(int &from:curr.first){
            for(int &to:curr.second){
                if(from!=to){
                    paths[from].push_back(to);
                    pathsRev[to].push_back(from);
                }
            }
        }
    }

    //do findSCC, forward
    visited.assign(nCharacters,false);
    for(int i=0;i<nCharacters;++i){
        if(!visited[i]){
            findSCC(i,true);
        }
    }

    //backwards {}
    int temp {0};
    visited.assign(nCharacters,false);
    while(!ts.empty()){
        int nxt {ts.top()};
        ts.pop();

        if(!visited[nxt]){
            temp = max(temp,findSCC(nxt,false));
        }
    }
    cout << nCharacters - temp << '\n';
}