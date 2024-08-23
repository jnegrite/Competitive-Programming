#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int nIntersections;
int nRoads;

vector<vector<int>> paths {};
vector<bool> visited {};

int main(){
    while(cin >> nIntersections >> nRoads){
        paths.clear();
        paths.assign(nIntersections,{});
        visited.assign(nIntersections,false);
        int seed {nIntersections};

        int a, b;
        bool isOk {true};
        if(nRoads==0){
            isOk = false;
        }

        while(isOk && nRoads--){
            cin >> a >> b;
            paths[a].push_back(b);
            paths[b].push_back(a);
            seed = min(seed,a);
        }

        int nZero {};

        //check number of roads per intersection
        for(int i=0;isOk && i<nIntersections;++i){
            if(paths[i].size()%2){
                isOk = false;
            }

            if(paths[i].empty()){
                ++nZero;
            }
        }

        //check if connected
        if(isOk){
            queue<int> q {};
            q.push(seed);
            visited[seed] = true;
            int nVisited {1};

            while(!q.empty()){
                int curr {q.front()};
                q.pop();
                for(int nxt: paths[curr]){
                    if(!visited[nxt]){
                        ++nVisited;
                        q.push(nxt);
                        visited[nxt] = true;
                    }
                }
            }

            if(nZero + nVisited<nIntersections){
                isOk = false;
            }
        }

        if(!isOk){
            cout << "Not ";
        }

        cout << "Possible\n";
    }
}