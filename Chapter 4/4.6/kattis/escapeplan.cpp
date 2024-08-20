#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

using ld = long double;

int nRobots;
int nHoles;

vector<pair<ld,ld>> robots {};
vector<pair<ld,ld>> holes {};
vector<bool> visited {};
vector<int> match {};

vector<vector<vector<int>>> paths {};

int categorize(int robot, int hole){
    auto &objR {robots[robot]};
    auto &objH {holes[hole]};

    ld dx {objR.first-objH.first};
    ld dy {objR.second-objH.second};

    ld dist {sqrt(dx*dx + dy*dy)};
    
    if(dist < 50.0){
        return 0;
    } else if (dist < 100.0){
        return 1;
    } else if(dist< 200.0) {
        return 2;
    } else {
        return -1;
    }
}

int aug(int L, int dist){
    if(visited[L]) return 0;

    visited[L] = true;
    for(int group=0;group<=dist;++group){
        for(int nxt:paths[L][group]){
            if((match[nxt] == -1) || aug(match[nxt],dist)){
                match[nxt] = L;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int tc {};
    while(cin >> nRobots, nRobots > 0){
        robots.assign(nRobots,{0,0});
        paths.assign(nRobots,{{},{},{}});

        for(int i=0;i<nRobots;++i){
            cin >> robots[i].first >> robots[i].second;
        }

        cin >> nHoles;
        holes.assign(nHoles,{0,0});
        for(int i=0;i<nHoles;++i){
            cin >> holes[i].first >> holes[i].second;
        }

        visited.assign(nRobots,false);
        match.assign(nHoles,-1);

        //get maps
        int cat {};
        for(int i=0;i<nRobots;++i){
            for(int j=0;j<nHoles;++j){
                cat = categorize(i,j);
                if(cat >= 0){
                    paths[i][cat].push_back(j);
                }
            }
        }

        int ans[3] {};
        int seconds[3] {5,10,20};
        
        //loop each time period
        for(int i=0;i<3;++i){
            int ctr {};
            match.assign(nHoles,-1);
            for(int robot=0;robot<nRobots;++robot){
                visited.assign(nRobots,false);
                ctr += aug(robot, i);
            }
            ans[i] = ctr;
        }
        
        cout << "Scenario " << ++tc << '\n';
        for(int i=0;i<3;++i){
            cout << "In " << seconds[i] << " seconds " << ans[i] << " robot(s) can escape\n";
        }
        cout << '\n';
    }
}