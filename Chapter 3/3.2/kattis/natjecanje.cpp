#include<iostream>
#include<iostream>

using namespace std;

int reserves[11] {};
int nTeams;
int nDamaged;
int nReserve;
int curr;

int minDamaged {};
int currDamaged {};
void backtrack(int pos){
    if(pos == nTeams){
        if (currDamaged < minDamaged){
            minDamaged = currDamaged;
        }
        return;
    }

    backtrack(pos+1);

    //if available to swap
    if(reserves[pos] != 0 && reserves[pos] + reserves[pos+1] == 0){
        int cachePos {reserves[pos]};
        currDamaged--;
        reserves[pos] = reserves[pos+1] = 0;
        backtrack(pos+1);
        reserves[pos] = cachePos;
        reserves[pos+1] = 0-cachePos;
        currDamaged++;
    }
}

int main(){
    cin >> nTeams >> nDamaged >> nReserve;

    for(int i=1;i<=nTeams;i++){
        reserves[i] = 0;
    }

    while(nDamaged--){
        cin >> curr;
        reserves[curr]--;
    }

    while(nReserve--){
        cin >> curr;
        reserves[curr]++;
    }

    currDamaged = 0;
    for(int i=1;i<=nTeams;i++){
        if(reserves[i]==-1){
            currDamaged++;
        }
    }
    minDamaged = currDamaged;

    backtrack(1);
    cout << minDamaged << '\n';

}