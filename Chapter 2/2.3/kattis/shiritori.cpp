#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    long nWords;
    unordered_set<string> seenWords {};
    string prev, curr;

    cin >> nWords;
    int loser {0};
    cin >> prev;
    seenWords.emplace(prev);

    for(int i=1;loser==0 && i<nWords;i++){
        cin >> curr;
        if(curr.at(0) != prev.at(prev.length()-1) || seenWords.count(curr) != 0){
            loser=1+(i%2);
        }
        seenWords.emplace(curr);
        prev = curr;
    }

    if(loser==0){
        cout << "Fair Game\n";
    } else {
        cout << "Player " << loser << " lost\n";
    }
}