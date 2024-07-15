#include<iostream>
using namespace std;


int main(){
    int nCases;
    int nBuildings, nRoads;
    int dist[100][100] {};
    int a, b;
    cin >> nCases;



    for(int tc=1;tc<=nCases;tc++){
        cin >> nBuildings;

        for(int i=0;i<nBuildings;i++){
            for(int j=0;j<nBuildings;j++){
                dist[i][j] = (i==j?0: 1000);
            }
        }

        cin >> nRoads;
        while(nRoads--){
            cin >> a >> b;
            dist[a][b] = dist[b][a] = 1;
        }

        for(int k=0;k<nBuildings;k++){
            for(int i=0;i<nBuildings;i++){
                for(int j=0;j<nBuildings;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }

        cin >> a >> b;
        int maxDist {0};
        for(int i=0;i<nBuildings;i++){
            maxDist = max(maxDist, dist[a][i] + dist[i][b]);
        }

        cout << "Case " << tc << ": " << maxDist << '\n';
    }
}