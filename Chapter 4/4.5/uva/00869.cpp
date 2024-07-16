#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>

using namespace std;

unordered_map<string,int> places {};
vector<vector<pair<int,int>>> paths {};
int dist[2][1000][1000] {};

int getId(string s){
    auto it {places.find(s)};
    if (it!=places.end()){
        return it->second;
    }

    auto val {places.size()};
    return places[s] = val;
}

int main(){
    int nCases;
    cin >> nCases;

    while(nCases--){
        places.clear();
        paths = {{},{}};

        for(int reps=0;reps<2;reps++){
            string sA, sB;
            int a, b;
            int nFlights;
            cin >> nFlights;
            while(nFlights--){
                cin >> sA >> sB;
                a = getId(sA);
                b = getId(sB);

                paths[reps].emplace_back(a,b);
            }    
        }

        memset(dist,-1,sizeof(dist));
        for(int i=0;i<places.size();i++){
            dist[0][i][i] = dist[1][i][i] = 0;
        }


        for(int reps=0;reps<2;reps++){
            for(auto pr:paths[reps]){
                int p1 {pr.first}, p2 {pr.second};
                dist[reps][pr.first][pr.second] = dist[reps][pr.second][pr.first] = 1;
            }
        }

        //algo
        for(int reps=0;reps<2;reps++){
            for(int k=0;k<places.size();k++){
                for(int i=0;i<places.size();i++){
                    if(dist[reps][i][k] == -1) continue;

                    for(int j=0;j<places.size();j++){
                        if(dist[reps][k][j] == -1) continue;

                        int tempDist {dist[reps][i][k] + dist[reps][k][j]};

                        auto &target {dist[reps][i][j]};
                        if(target == -1 || tempDist < target){
                            target = tempDist;
                        }
                    }
                }
            }
        }

        //check if same
        bool isSame {true};
        for(int i=0;isSame && i<places.size();i++){
            for(int j=i+1;isSame && j<places.size();j++){
                if((dist[0][i][j]==-1) != (dist[1][i][j]==-1)){
                    isSame = false;
                }
            }
        }

        cout << (isSame? "YES\n" : "NO\n");

        if(nCases > 0){
            cout << '\n';
        }
    }
}