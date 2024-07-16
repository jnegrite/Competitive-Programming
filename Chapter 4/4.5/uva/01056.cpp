#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
unordered_map<string,int> mapPersons {};
int dist[50][50] {};
int nPeople, nRelations;

int getId(string s){
    auto it {mapPersons.find(s)};
    if(it!=mapPersons.end()){
        return it->second;
    }

    auto val {mapPersons.size()};
    mapPersons[s] = val;
    return val;
}

int main(){
    int tc {0};
    while(cin >> nPeople >> nRelations, nPeople != 0 || nRelations != 0){
        for(int i=0;i<nPeople;i++){
            for(int j=0;j<nPeople;j++){
                dist[i][j] = (i==j?0:-1);
            }
        }

        mapPersons.clear();
        
        string a, b;
        int idA, idB;
        while(nRelations--){
            cin >> a >> b;
            idA = getId(a);
            idB = getId(b);

            if(a!=b){
                dist[idA][idB] = dist[idB][idA] = 1;
            }
        }

        //algo
        for(int k=0;k<nPeople;k++){
            for(int i=0;i<nPeople;i++){
                if(dist[i][k] == -1) continue;
                for(int j=0;j<nPeople;j++){
                    if(dist[k][j] == -1) continue;
                    int tempDist {dist[i][k] + dist[k][j]};

                    if(dist[i][j] == -1 || (tempDist < dist[i][j])){
                        dist[i][j] = tempDist;
                    }
                }
            }
        }

        //evaluate
        int ans {-1};
        bool disconnected = false;
        for(int i=0;!disconnected && i<nPeople;i++){
            for(int j=i+1;!disconnected && j<nPeople;j++){
                if(dist[i][j] == -1){
                    disconnected=true;
                    break;
                }
                ans = max(ans, dist[i][j]);
            }
        }

        cout << "Network " << ++tc << ": ";

        if(disconnected){
            cout << "DISCONNECTED\n";
        } else {
            cout << ans << '\n';
        }
        cout << '\n';

    }
}