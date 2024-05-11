#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

vector<string> items {};
unordered_map<string,int> mapItems {};
vector<vector<int>> paths {};

stack<int> ts {};
vector<bool> visited {};

int getNum(string s){
    auto it {mapItems.find(s)};
    if(it == mapItems.end()){
        mapItems[s] = items.size();
        items.push_back(s);
        paths.push_back({});
        return  mapItems[s];
    } else {
        return it->second;
    }
}

void topsort(int pos){
    visited[pos] = true;
    for(auto nxt: paths[pos]){
        if(!visited[nxt]){
            topsort(nxt);
        }
    }
    ts.push(pos);
}

int main(){
    int nItems;
    cin >> nItems >> ws;
    string s;
    while(nItems--){
        getline(cin,s);
        auto strIn {stringstream(s)};
        //get first line
        strIn >> s;
        s = s.substr(0,s.length()-1);
        int idxTo {getNum(s)};
        while(strIn >> s){
            int idxFrom {getNum(s)};
            paths[idxFrom].push_back(idxTo);
        }
    }

    visited.assign(items.size(),false);
    cin >> s;
    topsort(mapItems[s]);
    while(!ts.empty()){
        cout << items[ts.top()] << '\n';
        ts.pop();
    }

}