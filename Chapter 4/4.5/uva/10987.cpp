#include<iostream>
#include<cstring>
#include<vector>
#include<tuple>

using namespace std;

int dist[100][100] {};

int main(){
    int nCases;
    int nPoints;
    cin >> nCases;

    for(int tc=1;tc<=nCases;tc++){
        memset(dist,0,sizeof(dist));
        cin >> nPoints;
        for(int i=1;i<nPoints;i++){
            for(int j=0;j<i;j++){
                cin >> dist[i][j];
                dist[j][i] = dist[i][j];
            }
        }


        for(int k=0;k<nPoints;k++){
            for(int i=0;i<nPoints;i++){
                if(i==k) continue;
                if(dist[i][k] == -1) continue;

                for(int j=0;j<nPoints;j++){
                    if(j==k || j==i) continue;
                    if(dist[k][j] == -1 || dist[i][j] == -1) continue;

                    int dDirect {dist[i][j]};
                    int dRoute {dist[i][k] + dist[k][j]};
                
                    if(dRoute == dDirect){
                        dist[i][j] = -1;
                    }
                }
            }
        }

        //evaluate if network is ok
        bool isOk {true};
        vector<tuple<int,int,int>> cables {};

        for(int i=0;isOk && i<nPoints;i++){
            for(int j=i+1;isOk && j<nPoints;j++){
                if(dist[i][j] == -1) continue;

                bool valid {true};

                for(int k=0;valid && k<nPoints;k++){
                    if(dist[i][k]==-1 || dist[k][j] == -1) continue;
                    if(i==k && k==j) continue;

                    if(dist[i][k] + dist[j][k] < dist[i][j]){
                        valid = false;
                    }
                }

                if(valid){
                    cables.emplace_back(i,j,dist[i][j]);
                } else {
                    isOk = false;
                }
            }
        }

        cout << "Case #" << tc << ":\n";
        
        if(!isOk){
            cout << "Need better measurements.\n";
        } else {
            cout << cables.size() << '\n';
            for(auto t:cables){
                cout << (get<0>(t)+1) << ' ' << (get<1>(t)+1) << ' ' << (get<2>(t)) << '\n';
            }
        }

        cout << '\n';
    }
}