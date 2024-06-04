#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int nStations;
int nLines;
int prevStation, currStation;
vector<vector<int>> paths {};
vector<int> lineCounts {};

int getTotalDist(int pos){
    int ans {0};

    vector<bool> visited {};
    visited.assign(nStations+1,false);
    visited[pos] = true;
    queue<pair<int,int>> q {};
    q.emplace(pos,0);

    while(!q.empty()){
        auto curr {q.front()};
        q.pop();

        int currPos {curr.first};
        int currDist {curr.second};

        if(lineCounts[currPos] > 1){
            ans += currDist;
        }

        for(auto nxt: paths[currPos]){
            if(visited[nxt]) continue;

            visited[nxt] = true;
            q.emplace(nxt,currDist+1);
        }
    }

    return ans;
}

int main(){
    int nCases;
    cin >> nCases;

    while(nCases--){
        cin >> nStations >> nLines;

        paths.assign(nStations+1,{});
        lineCounts.assign(nStations+1,0);
        while(nLines--){
            cin >> prevStation;
            lineCounts[prevStation]++;

            while(cin >> currStation, currStation!=0){
                lineCounts[currStation]++;

                paths[prevStation].push_back(currStation);
                paths[currStation].push_back(prevStation);
            
                prevStation = currStation;
            }
        }

        //evaluate
        int ans {-1};
        int bestLoc {1};
        for(int i=1;i<=nStations;++i){
            if(lineCounts[i] > 1){
                int stDist {getTotalDist(i)};
                if(ans==-1 || (stDist < ans)){
                    ans= stDist;
                    bestLoc = i; 
                }
            }
        }

        cout << "Krochanska is in: " << bestLoc << '\n';
    }
}