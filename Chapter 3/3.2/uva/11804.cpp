#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

#define LSOne(x) ((x) & (-x))

using namespace std;

vector<string> names {};
unordered_map<string,pair<int,int>> abilities {};

int maxAttack {};
int maxDefense {};
int currAttack {};
int currDefense {};

int bestConfig {};
int currConfig {};

void printSolution(){
    vector<vector<string>> ans {{},{}};

    for(int i=0;i<10;i++){
        ans[(bestConfig & (1<<i)) == 0].push_back(names[i]);
    }

    for(int g=0;g<2;g++){
        vector<string> &curr {ans[g]};
        cout << '(' << curr[0];
        for(int i=1;i<5;i++){
            cout << ", " << curr[i];
        }
        cout << ")\n";
    }
}

void backtrack(int pos){

    if(pos == 10){
        if(currAttack > maxAttack || 
                (currAttack == maxAttack && currDefense > maxDefense)){
            bestConfig = currConfig;
            maxAttack = currAttack;
            maxDefense = currDefense;
        }
        return;
    }

    //try putting into attack
    int inAttack {__builtin_popcount(currConfig)};
    int inDefense {pos-inAttack};
    string player {names[pos]};

    if(inAttack < 5){
        currAttack += abilities[player].first;
        currConfig ^= (1<<pos);

        backtrack(pos+1);

        currConfig ^= (1<<pos);
        currAttack -= abilities[player].first;   
    }

    if(inDefense < 5){
        currDefense += abilities[player].second;
        
        backtrack(pos+1);

        currDefense -= abilities[player].second;
    }
}

int main(){
    int nCases;
    cin >> nCases;

    string name;
    int attack;
    int defense;

    for(int tc=1;tc<=nCases;tc++){

        names.clear();
        abilities.clear();
        
        //get data
        for(int i=0;i<10;i++){
            cin >> name >> attack >> defense;
            names.push_back(name);
            abilities[name] = pair<int,int>{attack,defense};
        }
        sort(names.begin(),names.end());

        maxAttack = maxDefense = currAttack = currDefense = 0;
        bestConfig = currConfig = 0;

        backtrack(0);

        cout << "Case " << tc << ":\n";
        printSolution();
    }
}
