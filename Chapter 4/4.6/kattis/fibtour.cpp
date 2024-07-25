#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using ll = long long;
using namespace std;

unordered_map<ll,ll> nextFib {};
vector<ll> mansions {};
vector<unordered_set<int>> paths {};
vector<int> dist {};

void generateFib(){
    ll prev {1LL};
    ll curr {1};
    ll nxt {};

    ll maxVal {1000000000000000000LL};
    while(curr <= maxVal){
        nxt = prev + curr;
        nextFib[curr] = nxt;
        prev = curr;
        curr = nxt;
    }
}

int getMaxPath(int pos){
    auto &curr {dist[pos]};
    if(curr != -1){
        return curr;
    }
    
    ll val {mansions[pos]};
    auto it {nextFib.find(val)};
    curr = 0;
    
    if(it != nextFib.end()){
        bool hasOne {false};
        int maxNext {};
        for(auto &nxt:paths[pos]){
            if (val == 1 && mansions[nxt]==1) {
                hasOne = true;
            } else {
                maxNext = max(maxNext, getMaxPath(nxt));
            }
        }
        curr = 1 + maxNext;

        if(hasOne){
            ++curr;
        }
    }
    return curr;
}

int main(){
    generateFib();
    int nMansions, nRoads;
    cin >> nMansions >> nRoads;
   

    mansions.assign(nMansions+1,0);
    paths.assign(nMansions+1,{});
    dist.assign(nMansions+1,-1);

    for(int i=1;i<=nMansions;++i){
        cin >> mansions[i];
    }

    int p1, p2;
    while(nRoads--){
        cin >> p1 >> p2;
        ll v1 {mansions[p1]};
        ll v2 {mansions[p2]};

        //check if both 1
        if(v1==1 && v2==1){
            paths[p1].emplace(p2);
            paths[p2].emplace(p1);
        } else {
            auto it1 {nextFib.find(v1)};
            auto it2 {nextFib.find(v2)};

            if(it1 != nextFib.end() && (it1->second == v2)){
                paths[p1].emplace(p2);
            } else if(it2 != nextFib.end() && (it2->second == v1)){
                paths[p2].emplace(p1);
            }
        }
    }

    int maxDist {0};
    //evaluate per mansion
    for(int pos=1;pos<=nMansions;pos++){
        maxDist = max(maxDist, getMaxPath(pos));
    }

    cout << maxDist << '\n';
}