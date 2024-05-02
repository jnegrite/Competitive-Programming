#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>

using namespace std;

int main(){
    int numCases;
    string s;
    getline(cin,s);
    numCases = stoi(s);
    for(int tc=1;tc<=numCases;tc++){
        int nA, nB;
        getline(cin,s);
        int pos =s.find(' ');
        nA = stoi(s.substr(0,pos));
        nB = stoi(s.substr(pos + 1));

        vector<string> wordsA {};
        unordered_set<string> outputs {};
        wordsA.clear();
        outputs.clear();
        wordsA.reserve(nA);
        outputs.reserve(nA*nB);

        for(int i=0;i<nA;i++){
            getline(cin,s);
            wordsA.push_back(s);
        }

        for(int i=0;i<nB;i++){
            getline(cin,s);
            for(string sA: wordsA){
                string sTemp = sA+s;
                outputs.emplace(sTemp);
            }
        }

        cout << "Case " << tc << ": " << outputs.size() << '\n';
    }
}