#include<iostream>
#include<set>

using namespace std;


int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        int nCuts {};
        set<char> baseSet {};
        string s;

        int nWords;
        cin >> nWords;
        while(nWords--){
            cin >> s;

            for(auto au {baseSet.begin()}; au != baseSet.end();){
                //remove if not in s
                if(s.find(*au) == -1){
                    char val {*au};
                    baseSet.erase(au);
                    au = baseSet.upper_bound(val);
                } else {
                    ++au;
                }
            }

            if(baseSet.empty()){
                nCuts++;
                for(char ch: s){
                    baseSet.emplace(ch);
                }
            }
        }
        cout << nCuts-1 << '\n';
    }
}