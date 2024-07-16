#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<unordered_set>

using namespace std;

int nJunctions, nRoads;
int dist[100][100] {};
vector<vector<unordered_set<int>>> parents {};
vector<vector<pair<int,int>>> paths {};

int searchFrom, searchTo;
int searchAns;

void retryPath(int from, int to){
    for(int mid: parents[from][to]){
        

        int tmpDist; 
        for(auto nxt: paths[mid]){
            tmpDist = dist[searchFrom][mid] + nxt.second + dist[nxt.first][searchTo];
            
            if(tmpDist <= dist[searchFrom][searchTo]) continue;

            if(searchAns == -1 || (tmpDist < searchAns)){
                searchAns = tmpDist;
            }
        }

        if(mid == from || mid==to) continue;

        retryPath(from, mid);
        retryPath(mid, to);
    }
}

int main(){
    int tc {};
    while(cin >> nJunctions >> nRoads){
        parents.clear();
        parents.reserve(nJunctions);
        paths.assign(nJunctions,{});
        for(int i=0;i<nJunctions;i++){
            for(int j=0;j<nJunctions;j++){
                if(i==j){
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = -1;
                }
            }
            vector<unordered_set<int>> sub {};
            sub.assign(nJunctions,{i});
            parents.push_back(sub);
        }

        int a, b, w;
        while(nRoads--){
            cin >> a >> b >> w;
            paths[a].emplace_back(b,w);
            paths[b].emplace_back(a,w);
            dist[a][b] = dist[b][a] = w;
            parents[a][b].emplace(a);
            parents[b][a].emplace(b);
        }

        //do algo
        for(int k=0;k<nJunctions;k++){
            for(int i=0;i<nJunctions;i++){
                if(dist[i][k] == -1) continue;

                for(int j=0;j<nJunctions;j++){
                    if(dist[k][j] == -1) continue;

                    int tmp {dist[i][k] + dist[k][j]};
                    int &target {dist[i][j]};

                    if((target==-1) || (tmp < target)){
                        target = tmp;
                        parents[i][j].clear();
                        parents[i][j].emplace(k);
                    } else if (tmp==target){
                        parents[i][j].emplace(k);
                    }
                }
            }
        }

        cout << "Set #" << ++tc << '\n';
        
        int nQueries;
        cin >> nQueries;
        while(nQueries--){
            cin >> searchFrom >> searchTo;
            searchAns = -1;

            if(dist[searchFrom][searchTo] != -1){
                retryPath(searchFrom, searchTo);
            }

            if(searchAns==-1){
                cout << "?\n";
            } else {
                cout << searchAns << '\n';
            }
        }
    }
}