#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

#define INF (~(1<<31))
vector<string> cities {};
unordered_map<string,int> mapCities {};
vector<vector<pair<int,int>>> paths {};
unordered_map<int,int> ans {};
vector<int> dist {};
int nCities;

int getId(string s){
    auto it {mapCities.find(s)};

    if(it != mapCities.end()){
        return it->second;
    }

    int ans = mapCities[s] = cities.size();
    cities.push_back(s);

    return ans;
}

int main(){
    int nScenarios;
    cin >> nScenarios;

    for(int tc=1;tc<=nScenarios;tc++){
        cities.clear();
        mapCities.clear();
        cin >> nCities;

        string s1, s2;
        for(int i=0;i<nCities;i++){
            cin >> s1;
            getId(s1);
        }

        int cost;
        int nFlights {};
        cin >> nFlights;

        int id1, id2;
        paths.assign(nCities,{});
        while(nFlights--){
            cin >> s1 >> s2 >> cost;
            id1 = getId(s1);
            id2 = getId(s2);
            paths[id1].emplace_back(id2,cost);
        }

        dist.assign(nCities,INF);
        dist[0] = 0;

        int currIter = 0;
        ans.clear();
        
        cout << "Scenario #" << tc << '\n';
        int nQueries {};
        cin >> nQueries;
        while(nQueries--){
            cin >> id1;

            while(currIter<=id1){
                for(int i=nCities-1;i>=0;i--){
                    if(dist[i] == INF) continue;

                    for(auto nxt: paths[i]){
                        dist[nxt.first] = min(dist[nxt.first],dist[i]+nxt.second);
                    }
                }
                ans[currIter++] = dist[nCities-1];
            }

            if(ans[id1] == INF){
                cout << "No satisfactory flights\n";
            } else {
                cout << "Total cost of flight(s) is $" << ans[id1] << '\n';
            }
        }
        if(tc!=nScenarios){
            cout << '\n';
        }
    }
}