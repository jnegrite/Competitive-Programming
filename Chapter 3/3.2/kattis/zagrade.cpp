#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<string>
#include<algorithm>

using namespace std;
string sMain;
vector<pair<int,int>> brackets {};

set<string> outputs {};
int nSelected;
set<int> forDeletion {};

void backtrack(int pos){
    if(pos == brackets.size()){
        if(nSelected != 0){
            int prev {0};
            string temp {};
            for(auto it {forDeletion.begin()};it!=forDeletion.end();it++){
                int marker {*it};
                temp += sMain.substr(prev,marker-prev);
                prev = marker+1;
            }
            outputs.emplace(temp);
        }
        return;
    }

    //add to for removal
    pair<int,int> curr {brackets[pos]};
    forDeletion.insert(curr.first);
    forDeletion.insert(curr.second);
    ++nSelected;

    backtrack(pos+1);

    --nSelected;
    forDeletion.erase(curr.first);
    forDeletion.erase(curr.second);

    backtrack(pos+1);
}




int main(){
    getline(cin,sMain);
    stack<int> openBrackets {};

    for(int i=0;i<sMain.length();++i){
        switch(sMain.at(i)){
            case '(':
                openBrackets.push(i);
                break;
            case ')':
                brackets.push_back(pair<int,int>{openBrackets.top(),i});
                openBrackets.pop();
                break;
        }
    }

    forDeletion.emplace(sMain.length());
    backtrack(0);

    for(auto it{outputs.begin()}; it!=outputs.end();it++){
        cout << *it << '\n';
    }
}