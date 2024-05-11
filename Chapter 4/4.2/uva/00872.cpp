#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
bool didPrint {false};
vector<char> buffer {};

vector<vector<int>> paths {};
vector<char> chars {};
vector<bool> visited {};
unordered_map<char,int> charMap {};
vector<int> dependencies {};

void backtrack(){
    if(buffer.size() == chars.size()){
        didPrint = true;
        cout << buffer[0];

        for(int i=1;i<buffer.size();++i){
            cout << ' ' << buffer[i];
        }
        cout << '\n';
        return;
    }

    for(int pos=0;pos<chars.size();pos++){
        if(!visited[pos] && dependencies[pos] == 0){
            //simulate pushing into buffer
            buffer.push_back(chars[pos]);
            visited[pos] = true;

            for(int nxt: paths[pos]){
                dependencies[nxt]--;
            }

            backtrack();

            for(int nxt: paths[pos]){
                dependencies[nxt]++;
            }
            visited[pos] = false;
            buffer.pop_back();
        }
    }
}

int main(){
    int nCases;
    string s;
    getline(cin,s);
    nCases = stoi(s);

    while(nCases--){
        getline(cin,s);
        
        //check which letters to use
        chars.clear();
        charMap.clear();
        getline(cin,s);
        for(int i=0;i<s.length();i+=2){
            chars.push_back(s.at(i));
        }
        sort(chars.begin(),chars.end());
        for(int i=0;i<chars.size();++i){
            charMap[chars[i]] = i;
        }
        visited.assign(chars.size(),false);
        dependencies.assign(chars.size(),0);

        //get paths
        paths.assign(26,{});
        getline(cin,s);
        auto strIn {stringstream(s)};
        while(strIn >> s){
            int v1 {charMap[s.at(0)]};
            int v2 {charMap[s.at(2)]};
            paths[v1].push_back(v2);
            dependencies[v2]++;
        }

        didPrint = false;
        backtrack();

        if(!didPrint){
            cout << "NO\n";
        }

        if(nCases > 0){
            cout << '\n';
        }
    }
}