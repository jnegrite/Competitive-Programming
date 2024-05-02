#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int nColors;
vector<string> colors {};
unordered_map<string,int> mappings {};
vector<unordered_set<int>> uglies {};
vector<int> currPainting {};
vector<int> bestPainting {};
vector<bool> isUsed {};
int nPaintings {0};
int prevColor {-1};

void backtrack(int pos){
    if(pos == nColors){
        ++nPaintings;

        if(bestPainting.size() == 0){
            for(int v:currPainting){
                bestPainting.push_back(v);
            }
        }
        return;
    }

    for(int i=0;i<nColors;i++){
        if(!isUsed[i] && ((prevColor == -1) || (uglies[prevColor].count(i) == 0))){
            int cachePrev {prevColor};
            isUsed[i] = true;
            currPainting.push_back(i);
            prevColor = i;
            
            backtrack(pos+1);

            currPainting.pop_back();
            isUsed[i] = false;
            prevColor = cachePrev;
        }
    }
}

int main(){
    int nCases;
    cin >> nCases;
    string a, b;

    while(nCases--){
        cin >> nColors;
        colors.clear();
        mappings.clear();
        uglies.clear();
        isUsed.clear();
        isUsed.assign(nColors,false);
        currPainting.clear();
        bestPainting.clear();
        nPaintings = 0;
        for(int i=0;i<nColors;i++){
            cin >> a;
            colors.push_back(a);
            mappings[a] = i;
            uglies.push_back(unordered_set<int> {});
        }

        int nUglies;
        cin >> nUglies;
        while(nUglies--){
            cin >> a >> b;
            uglies[mappings[a]].emplace(mappings[b]);
            uglies[mappings[b]].emplace(mappings[a]);
        }

        backtrack(0);

        cout << nPaintings << '\n';

        cout << colors[bestPainting[0]];
        for(int i=1;i<nColors;i++){
            cout << ' ' << colors[bestPainting[i]];
        }
        cout << '\n';
    }
}