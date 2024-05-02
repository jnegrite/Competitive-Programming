#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

struct Word{
    string word {};
    long freq {};

    Word(string _word, long _freq){
        word = _word;
        freq = _freq;
    }

    bool operator<(const Word o){
        if(freq != o.freq){
            return freq > o.freq;
        } else {
            return word < o.word;
        }
    }
};

int main(){
    string s;
    getline(cin,s);

    long numLines {stol(s)};
    unordered_set<string> names {};
    unordered_map<string,unordered_set<string>> users {};
    unordered_map<string,long> hits {};
    string name, curr;

    //get data summary
    while(numLines--){
        getline(cin,s);
        auto strIn {stringstream(s)};
        strIn >> name;
        names.emplace(name);
        while(strIn >> curr){
            if(hits.count(curr) == 0){
                unordered_set<string> temp {};
                users[curr] = temp;
                hits[curr] = 0;
            }

            users[curr].emplace(name);
            hits[curr]++;
        }
    }

    //process
    vector<Word> topWords {};
    for(auto it=users.begin();it!=users.end();it++){
        if(it->second.size() == names.size()){
            Word curr {it->first,hits[it->first]};
            topWords.push_back(curr);
        }
    }

    if(topWords.empty()){
        cout << "ALL CLEAR\n";
    } else {
        sort(topWords.begin(),topWords.end());
        for(Word w:topWords){
            cout << w.word << '\n';
        }
    }


}

