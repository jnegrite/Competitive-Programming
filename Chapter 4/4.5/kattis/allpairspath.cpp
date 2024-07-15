#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    int nPoints, nPaths, nQueries;

    const long long INF {~(1LL<<63)};

    vector<int> loopSeeds {};
    long long dist[150][150] {};
    while(cin >> nPoints >> nPaths >> nQueries, nPoints!=0 || nPaths!=0 || nQueries!=0){
        for(int i=0;i<nPoints;i++){
            for(int j=0;j<nPoints;j++){
                dist[i][j] = ((i==j)? 0LL : INF);
            }
        }
        loopSeeds.clear();

        int a, b;
        long long w;
        for(int i=0;i<nPaths;i++){
            cin >> a >> b >> w;
            dist[a][b] = min(dist[a][b],w);
        }

        //do algo
        for(int k=0;k<nPoints;k++){
            for(int i=0;i<nPoints;i++){
                if(dist[i][k] < -INF) continue;
                for(int j=0;j<nPoints;j++){

                    if(dist[i][k] == INF || dist[k][j] == INF) continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        //check for negative cycles
        for(int i=0;i<nPoints;i++){
            if(dist[i][i] < 0){
                loopSeeds.push_back(i);
            }
        }

        //process queries
        while(nQueries--){
            cin >> a >> b;
            if(dist[a][b] == INF){
                cout << "Impossible\n";
            } else {
                bool hasInf {false};

                for(auto seed: loopSeeds){
                    if((dist[a][seed] != INF) && (dist[seed][b] != INF)){
                        hasInf = true;
                        break;
                    }
                }

                if(hasInf){
                    cout <<"-Infinity\n";
                } else {
                    cout << dist[a][b] << '\n';
                }
            }
        }
        cout << '\n';
    }
}