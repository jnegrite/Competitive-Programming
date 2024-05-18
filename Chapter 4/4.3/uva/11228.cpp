#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>

using namespace std;
using ld = long double;
using ii = pair<ld,int>;
priority_queue<ii> q {};
int nCities;
long locs[1000][2] {};
bool visited[1000] {};
ld totalRoad{};
ld totalRail{};
long threshold {};
int nTally;
int nStates;

long getDist(int i, int j){
    long dx {locs[i][0]-locs[j][0]};
    long dy {locs[i][1]-locs[j][1]};
    return dx*dx + dy*dy;
}

void process(int pos){
    visited[pos] = true;
    nTally++;

    for(int i=0;i<nCities;++i){
        if(!visited[i]){
            long tempDist {getDist(pos,i)};
            q.emplace(-tempDist,i);
        }
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    for(int tc=1;tc<=nCases;++tc){
        memset(visited,false,sizeof(visited));
        while(!q.empty()){
            q.pop();
        }
        
        scanf("%d %ld\n",&nCities,&threshold);
        threshold *= -threshold;

        for(int i=0;i<nCities;++i){
            scanf("%ld %ld\n",&locs[i][0],&locs[i][1]);
        }

        nTally = 0;
        totalRoad=0;
        totalRail=0;
        process(0);
        nStates=1;
        while(nTally<nCities && !q.empty()){
            auto curr {q.top()};
            q.pop();

            if(visited[curr.second]) continue;

            if(curr.first < threshold){
                totalRail += sqrt(-curr.first);
                ++nStates;
            } else {
                totalRoad += sqrt(-curr.first);
            }
            process(curr.second);
        }
        printf("Case #%d: %d %ld %ld\n",tc,nStates,static_cast<long>(round(totalRoad)),static_cast<long>(round(totalRail)));
    }
}