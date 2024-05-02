#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>

using namespace std;

string trim(string s){
    int iFrom = 0;
    int iTo = s.length() - 1;

    while(s.at(iFrom) == ' '){
        iFrom++;
    }

    while(s.at(iTo) == ' '){
        iTo--;
    }

    return s.substr(iFrom, iTo+1);
}

struct RoutingEntry {
    string name {};
    string markers[4] {};

    RoutingEntry(){
    }

    RoutingEntry(string s){
        name = trim(s.substr(0, 10));
        for(int i=0;i<4;i++){
            markers[i] = trim(s.substr(15 * (i+1) - 1,10));
        }
    }

    bool matches(RoutingEntry basis){
        for(int i=0;i<4;i++){
            if(basis.markers[i] != "*" && basis.markers[i] != markers[i]){
                return false;
            }
        }
        return true;
    }
};

struct MTA {
    string name {};
    vector<RoutingEntry> routingTable {};

    MTA() {
    }

    MTA(string _name){
        name = _name;
    };
};

int main(){
    map<string, MTA> mapMTA {};
    string s;
    int scenarioNum {0};
    int numMTA {0};

    while(cin >> numMTA){
        cout << "Scenario # " << ++scenarioNum << '\n';
        while(numMTA--){
            string name;
            int numEntries;

            cin >> name >> numEntries;
            MTA curr = MTA(name);
            while(numEntries--){
                RoutingEntry temp {};
                cin >> temp.name;
                for(int i=0;i<4;i++){
                    cin >> temp.markers[i];
                }
                curr.routingTable.push_back(temp);
            }
            mapMTA[name] = curr;
        }
        
        long numMsgs;
        cin >> numMsgs;

        for(long msgNum=1;msgNum<=numMsgs;msgNum++){

            set<string> visitedLocs {};

            RoutingEntry entry {};
            cin >> entry.name;
            for(int i=0;i<4;i++){
                cin >> entry.markers[i];
            }

            string currLoc {entry.name};
            string decision {""};

            while(decision.length() == 0){
                MTA curr = mapMTA[currLoc];
                RoutingEntry *match {nullptr};
                
                for(auto e: curr.routingTable){
                    if (entry.matches(e)){
                        match = &e;
                        break;
                    }
                }

                //check if no match
                if(match == nullptr){
                    decision = "unable to route at " + currLoc;
                } else if (match->name == currLoc){
                    decision = "delivered to " + currLoc;
                } else if (visitedLocs.find(match->name) != visitedLocs.end()){
                    decision = "circular routing detected by " + (match->name);
                } else {
                    visitedLocs.emplace(currLoc);
                    currLoc = match->name;
                }
            }
            
            cout << msgNum << " -- " << decision << '\n';
        }

        cout << '\n';
    }
}