#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int S;
int nArrows;
int currSum;
int prevUsed;
vector<int> arrows {};
vector<int> usedArrows {};
vector<int> bestConfig {};

bool isBetter(const vector<int> &newer, const vector<int> &older){
    if(older.size() == 0){
        return true;
    } else if(newer.size() != older.size()){
        return newer.size() < older.size();
    }

    for(int i=0;i<newer.size();i++){
        if(newer[i] != older[i]){
            return newer[i] > older[i];
        }
    }
    return false;
}

void backtrack(){
    if(currSum == S){
        //evaluate
        if(isBetter(usedArrows,bestConfig)){
            bestConfig.clear();
            bestConfig.reserve(usedArrows.size());
            for(int i=0;i<usedArrows.size();i++){
                bestConfig.push_back(usedArrows[i]);
            }
        }
        return;
    }

    if(bestConfig.size() != 0 && usedArrows.size() >= bestConfig.size()){
        return;
    }

    for(int i=prevUsed;i<arrows.size();i++){
        int arrow = arrows[i];
        if(currSum + arrow <= S){
            int cachePrev {prevUsed};
            prevUsed = i;
            currSum += arrow;
            usedArrows.push_back(arrow);
            
            backtrack();

            usedArrows.pop_back();
            currSum -= arrow;
            prevUsed = cachePrev;
        }
    }
}

int main(){
    int nCases;
    cin >> nCases;

    for(int tc=1;tc<=nCases;tc++){
        int curr;
        cin >> nArrows >> S;
        arrows.clear();
        for(int i=0;i<nArrows;i++){
            cin >> curr;
            arrows.push_back(curr);
        }
        reverse(arrows.begin(),arrows.end());
        usedArrows.clear();
        bestConfig.clear();
        currSum = 0;
        prevUsed = 0;
        cout << "Case " << tc << ": ";

        backtrack();

        if(bestConfig.size()==0){
            cout << "impossible";
        } else {
            cout << '[' << bestConfig.size() << ']';
            for(int curr: bestConfig){
                cout << ' ' << curr;
            }
        }
        cout << '\n';
    }

}