#include<iostream>
#include<sstream>
#include<unordered_map>
#include<sstream>
#include<vector>
#include<queue>

using namespace std;

unordered_map<char, int> mapTask {};

int getId(char ch){
    auto it {mapTask.find(ch)};
    if(it!=mapTask.end()){
        return it->second;
    }

    auto ans {mapTask.size()};
    return mapTask[ch] = ans;
}

int main(){
    int nCases;
    string s;
    vector<int> dependencies {};
    vector<int> durations {};
    vector<int> dist {};
    vector<vector<int>> paths {};

    cin >> nCases >> ws;
    
    while(nCases--){
        mapTask.clear();

        vector<string> tasks {};
        while(getline(cin,s), s.length() != 0){
            tasks.push_back(s);
        }

        dependencies.assign(tasks.size(),0);
        durations.assign(tasks.size(),0);
        dist.assign(tasks.size(),0);
        paths.assign(tasks.size(),{});
        
        queue<int> q {};

        for(string s: tasks){
            char ch;
            int duration;
            string deps;

            auto strIn {stringstream(s)};
            strIn >> ch >> duration >> deps;
            int pos {getId(ch)};

            durations[pos] = duration;
            if(deps.length() == 0){
                q.push(pos);
            } else {
                dependencies[pos] = deps.length();
                for(char ch:deps){
                    paths[getId(ch)].push_back(pos);
                }
            }
        }

        //process
        int finVal {0};
        while(!q.empty()){
            int curr {q.front()};
            q.pop();

            finVal = max(finVal,(dist[curr] += durations[curr]));
            for(int nxt: paths[curr]){
                dist[nxt] = max(dist[nxt], dist[curr]);
                if(--dependencies[nxt] == 0){
                    q.push(nxt);
                }
            }
        }
        cout << finVal << '\n';

        if(nCases > 0){
            cout << '\n';
        }
    }    
}