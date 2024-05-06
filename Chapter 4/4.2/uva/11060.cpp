#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

int nBeverages;
vector<string> beverages {};
vector<vector<int>> rel {};
vector<int> inCounts {};
unordered_map<string, int> mapBeverages {};
string s;
string a, b;
int idxA, idxB;

int main(){
    int tc {};

    while(cin >> nBeverages){
        //get data
        beverages.clear();
        mapBeverages.clear();
        beverages.assign(nBeverages,"");
        rel.assign(nBeverages,{});
        inCounts.assign(nBeverages,0);

        for(int i=0;i<nBeverages;++i){
            cin >> beverages[i];
            mapBeverages[beverages[i]] = i;
        }

        //process counts
        int nRels;
        cin >> nRels;
        while(nRels--){
            cin >> a >> b;
            idxA = mapBeverages[a];
            idxB = mapBeverages[b];
            rel[idxA].push_back(idxB);
            inCounts[idxB]++;
        }

        cout << "Case #" << ++tc << ": Dilbert should drink beverages in this order:";

        //get seed data
        priority_queue<int, vector<int>, greater<int>> pq {};
        for(int i=0;i<nBeverages;++i){
            if(inCounts[i] == 0){
                pq.emplace(i);
            }
        }

        //process
        while(!pq.empty()){
            int curr {pq.top()};
            pq.pop();

            cout << ' ' << beverages[curr];
            for(int nxt: rel[curr]){
                if((--inCounts[nxt]) == 0){
                    pq.emplace(nxt);
                }
            }
        }
        cout << ".\n\n";
    }
}