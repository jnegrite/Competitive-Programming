#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<sstream>

using namespace std;

vector<string> words {};
unordered_map<string,int> mapWords {};
vector<vector<int>> paths {};

bool areNeighbors(int i, int j){
    if(words[i].length() != words[j].length()) return false;

    int cntDiff {0};
    for(int k=0;k<words[i].length();++k){
        if(words[i].at(k) != words[j].at(k)){
            if(cntDiff++ > 0){
                return false;
            }
        }
    }

    return cntDiff==1;
}

string s;
int main(){
    int nCases;
    cin >> nCases >> ws;
    while(nCases--){

        words.clear();
        mapWords.clear();
        paths.clear();

        while(getline(cin,s),s!="*"){
            if(mapWords.count(s) != 0) continue;

            mapWords[s] = words.size();
            words.push_back(s);
        }

        //compute paths
        paths.assign(words.size(),{});
        for(int i=0;i<words.size();++i){
            for(int j=i+1;j<words.size();++j){
                if(areNeighbors(i,j)){
                    paths[i].push_back(j);
                    paths[j].push_back(i);
                }
            }
        }

        while(getline(cin,s),s.length()>0){
            auto strIn {stringstream(s)};
            string from, to;
            strIn >> from >> to;
            int idxFrom {mapWords[from]};
            int idxTo {mapWords[to]};

            vector<bool> visited {};
            visited.assign(words.size(),false);
            visited[idxFrom] = true;

            queue<pair<int,int>> q {};
            q.push({idxFrom,0});

            while(!q.empty()){
                auto curr {q.front()};
                q.pop();

                if(curr.first==idxTo){
                    cout << from << ' ' << to << ' ' << curr.second << '\n';
                    break;
                }
                
                for(int nxt:paths[curr.first]){
                    if(visited[nxt]) continue;

                    visited[nxt] = true;
                    q.push({nxt,curr.second+1});
                }
            }           
        }

        if(nCases>0){
            cout << '\n';
        }
    }
}