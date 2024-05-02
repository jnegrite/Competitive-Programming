#include<iostream>
#include<set>

using namespace std;

int main(){
    set<string> baseWords {};
    set<string> outputWords {};

    //get input
    string s;
    while(cin >> s){
        baseWords.emplace(s);
    }

    for(auto it1=baseWords.begin();it1!=baseWords.end();it1++){
        for(auto it2=it1;it2!=baseWords.end();it2++){
            if(it2==it1){
                continue;
            }

            outputWords.emplace(*it1 + *it2);
            outputWords.emplace(*it2 + *it1);
        }
    }
    
    for(auto it: outputWords){
        cout << it << '\n';
    }
}