#include<iostream>
#include<map>
#include<queue>

using namespace std;

string cmd;
long a, b;

int main(){
    long nCommands;
    cin >> nCommands;

    map<long,priority_queue<long>> energyLevels {};

    while(nCommands--){
        cin >> cmd;
        if(cmd == "add"){
            cin >> a >> b;
            if(energyLevels.count(a) == 0){
                priority_queue<long> temp {};
                energyLevels[a] = temp;
            }
            energyLevels[a].emplace(b);
        } else if (cmd == "query"){
            cin >> a;
            
            long totalPoints {};
            while(true){
                auto it {energyLevels.upper_bound(a)};
                if(it == energyLevels.begin()){
                    break;
                } else {
                    --it;
                }

                totalPoints += it->second.top();
                it->second.pop();
                a-=it->first;

                if(it->second.empty()){
                    energyLevels.erase(it->first);
                }
            }

            cout << totalPoints << '\n';
        }
    }
}