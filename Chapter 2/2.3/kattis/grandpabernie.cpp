#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    long nTrips;
    cin >> nTrips;
    
    string s;
    int year;
    unordered_map<string,vector<int>> trips {};
    for(long i=0;i<nTrips;i++){
        cin >> s >> year;
        if(trips.count(s) == 0){
            vector<int> temp {};
            trips[s] = temp;
        }

        trips[s].push_back(year);
    }

    for(auto it=trips.begin();it!=trips.end();it++){
        sort(it->second.begin(),it->second.end());
    }

    long nQueries;
    cin >> nQueries;
    long idx;
    while(nQueries--){
        cin >> s >> idx;
        cout << trips[s][idx-1] << '\n';
    }
}