#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

vector<set<int>> paths {};
vector<bool> isUsed {};
vector<bool> visited {};
vector<int> ts {};

void record(const string &s){
    for(char ch: s){
        isUsed[ch-'A']=true;
    }
}

void eval(const string &prev, const string &curr){
    if(prev.length() < curr.length() && curr.substr(0,prev.length())==prev){
        return;
    }

    for(int i=0;i<prev.length();++i){
        if(prev.at(i) != curr.at(i)){
            paths[prev.at(i)-'A'].emplace(curr.at(i)-'A');
            return;
        }
    }
}

void topsort(int pos){
    visited[pos] = true;
    for(auto it {paths[pos].begin()}; it != paths[pos].end(); ++it){
        if(!visited[*it]){
            topsort(*it);
        }
    }
    ts.push_back(pos);
}

int main(){
    paths.assign(26,{});
    isUsed.assign(26,false);
    visited.assign(26,false);

    //get input data
    string prev, curr;
    cin >> prev;
    record(prev);
    while(cin >> curr, curr!= "#"){
        record(curr);
        eval(prev,curr);
        prev = curr;
    }

    //do topsort
    for(int i=0;i<26;++i){
        if(isUsed[i] && !visited[i]){
            topsort(i);
        }
    }
    reverse(ts.begin(),ts.end());
    for(auto pos:ts){
        cout << static_cast<char>('A' + pos);
    }
    cout << '\n';
}