#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

int main(){
    string s;
    long maxVotes {0};
    unordered_map<string,long> votes {};
    vector<string> winners {};

    //get input
    while(true){
        getline(cin,s);
        
        if(s=="***"){
            break;
        }
        
        auto it = votes.find(s);
        if(it == votes.end()){
            votes[s] = 1;
        } else {
            votes[s]++;
        }

        maxVotes = max(maxVotes,votes[s]);
    }

    for(auto it:votes){
        if(it.second == maxVotes){
            winners.push_back(it.first);
        }
    }

    if(winners.size() == 1){
        cout << winners[0] << '\n';
    } else {
        cout << "Runoff!\n";
    }
}