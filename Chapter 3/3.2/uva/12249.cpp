#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> scenes {};

int main(){
    int nCases;
    cin >> nCases;
    for(int tc=1;tc<=nCases;tc++){
        int nScenes;
        cin >> nScenes;
        string s;

        scenes.clear();
        int minLen {};
        while(nScenes--){
            cin >> s;
            scenes.push_back(s);
            minLen += s.length();
        }
        sort(scenes.begin(),scenes.end());

        do {
            string curr {scenes[0]};
            for(int i=1;i<scenes.size();i++){
                auto currLen {curr.length()};
                auto overlap {min(currLen,scenes[i].length())};
                while(overlap>0){
                    if(scenes[i].substr(0,overlap) == curr.substr(currLen-overlap)){
                        break;
                    }
                    --overlap;
                }
                curr += scenes[i].substr(overlap);               
            }
            if(curr.length() < minLen){
                minLen = curr.length();
            }
        } while(next_permutation(scenes.begin(),scenes.end()));
        cout << "Case " << tc << ": " << minLen << '\n';
    }
}