#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<iomanip>

using namespace std;

using ld = long double;
using ii = pair<ld,int>;

int nIslands;
ld loc[750][2] {};
bool visited[750] {};
priority_queue<ii> q {};
ld totalDist {};
int nPoints {};

ld getDist(int i, int j){
    ld dx {loc[i][0]-loc[j][0]};
    ld dy {loc[i][1]-loc[j][1]};
    return sqrt(dx*dx + dy*dy);
}

void process(int pos){
    visited[pos] = true;
    nPoints++;

    //add to lists
    for(int i=0;i<nIslands;++i){
        if(!visited[i]){
            q.emplace(-getDist(pos,i),i);
        }
    }
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        memset(visited,false,sizeof(visited));
        while(!q.empty()){
            q.pop();
        }

        cin >> nIslands;
        for(int i=0;i<nIslands;i++){
            cin >> loc[i][0] >> loc[i][1];
            for(int j=0;j<i;++j){
                
            }
        }

        //prims
        nPoints = 0;
        totalDist = 0;
        process(0);
        while(nPoints<nIslands){
            auto curr {q.top()};
            q.pop();

            if(visited[curr.second]) continue;

            totalDist -= curr.first;
            process(curr.second);
        }
        cout << fixed << setprecision(6) << totalDist << endl; 
    }
}