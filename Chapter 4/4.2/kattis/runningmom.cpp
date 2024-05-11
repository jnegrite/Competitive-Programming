#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

enum State {
    UNVISITED,
    EXPLORED,
    VISITED
};

vector<string> cities {};
unordered_map<string,int> mapCities {};
vector<vector<int>> paths {};
vector<State> states {};
vector<bool> isSafe {};
string origin, dest;
int idxO, idxD;

int getIdx(const string &s){
    auto it {mapCities.find(s)};
    if(it != mapCities.end()){
        return it->second;
    }

    mapCities[s] = cities.size();
    cities.push_back(s);
    paths.push_back({});
    return mapCities[s];
}

bool cyclecheck(int pos){
    states[pos] = EXPLORED;
    int ans {false};
    for(int nxt: paths[pos]){
        if(states[nxt] == UNVISITED){
            if(cyclecheck(nxt)){
                ans = true;
            }
        } else if (states[nxt] == EXPLORED){
            ans = true;
        } else if (states[nxt] == VISITED && isSafe[nxt]){
            ans = true;
        }
    }
    states[pos] = VISITED;
    return isSafe[pos] = ans;
}

int main(){
    int nFlights;
    cin >> nFlights;
    
    //get flight details
    while(nFlights--){
        cin >> origin >> dest;
        idxO = getIdx(origin);
        idxD = getIdx(dest);

        paths[idxO].push_back(idxD);
    }

    //do simulation
    states.assign(cities.size(),UNVISITED);
    isSafe.assign(cities.size(),false);

    for(int i=0;i<cities.size();i++){
        if(states[i] == UNVISITED){
            cyclecheck(i);
        }
    }

    while(cin >> dest){
        idxD = getIdx(dest);
        cout << dest << ' ' << (isSafe[idxD]?"safe":"trapped") << '\n';
    }
}