#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<vector<int>> moves {
    {},
    {2,4},
    {3,5},
    {6},
    {5,7},
    {6,8},
    {9},
    {8},
    {9,0},
    {}
};

int currValue {};
int currPos {};
int target {};
set<int> values {};

void backtrack(){

    if(currValue > 200){
        return;
    }
    values.emplace(currValue);

    //try to press only if ok
    if(currPos != 0 || currValue != 0){
        currValue *= 10;
        currValue += currPos;
        backtrack();
        currValue /= 10;
    }

    int cachePos {currPos};
    for(int v: moves[cachePos]){
        currPos = v;
        backtrack();
    }

    currPos = cachePos;
}

int main(){
    int nCases;
    cin >> nCases;

    currPos = 1;
    backtrack();

    int curr;
    while(nCases--){
        cin >> curr;
        int nearest {200};
        int bestDist {200};
        auto it = values.lower_bound(curr);

        if(it != values.end() && abs(curr-*it) < bestDist){
            bestDist = abs(curr-*it);
            nearest = *it;
        }

        if(it != values.begin()){
            --it;
            if(abs(curr-*it) < bestDist){
                bestDist = abs(curr-*it);
                nearest = *it;
            }
        }
        cout << nearest << '\n';
    }
}