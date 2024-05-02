#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<regex>

using namespace std;

map<string,string> dictFrom {};
map<string,string> dictTo {};
string s;
string key, value;
vector<set<string>> changedKeys {{},{},{}};
string prefixes {"+-*"};
regex regExp("([a-z]+):(-?\\d+)");

void generateDict(const string &s, map<string,string> &dict){
    smatch match;
    auto strBegin {s.begin()};
    while(regex_search(strBegin,s.end(),match,regExp)){
        dict[match[1]] = match[2];
        strBegin = match.suffix().first;
    }
}

int main(){
    int numCases;
    getline(cin,s);
    numCases = stoi(s);

    for(int tc=0;tc<numCases;tc++){
        dictFrom.clear();
        dictTo.clear();

        for(int i=0;i<3;i++){
            changedKeys[i].clear();
        }
        
        getline(cin,s);
        generateDict(s,dictFrom);
        getline(cin,s);
        generateDict(s,dictTo);

        auto itFrom {dictFrom.begin()};
        auto itTo {dictTo.begin()};

        while(itFrom != dictFrom.end() || itTo != dictTo.end()){
            if(itFrom != dictFrom.end()){
                if(itTo == dictTo.end() || itFrom->first < itTo->first){
                    changedKeys[1].emplace(itFrom->first);
                    itFrom++;
                } else if (itFrom->first > itTo->first){
                    changedKeys[0].emplace(itTo->first);
                    itTo++;
                } else {
                    if(itFrom->second != itTo->second){
                        changedKeys[2].emplace(itFrom->first);
                    }
                    itFrom++;
                    itTo++;
                }
            } else {
                changedKeys[0].emplace(itTo->first);
                itTo++;
            }
        }

        //printing out
        bool didPrint {false};
        for(int i=0;i<3;i++){
            if(!changedKeys[i].empty()){
                cout << prefixes.at(i);
                for(auto it{changedKeys[i].begin()};it!=changedKeys[i].end();it++){
                    if(it != changedKeys[i].begin()){
                        cout << ',';
                    }
                    cout << *it;
                }
                cout << '\n';
                didPrint = true;
            }
        }
        if(!didPrint){
            cout << "No changes\n";
        }

        cout << '\n';

    }
}