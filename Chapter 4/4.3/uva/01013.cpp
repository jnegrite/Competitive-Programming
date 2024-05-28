#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int nIslands;
int nProcessed;
int locs[50][3] {};
bool visited[50] {};
double totalInhabitants {};
double totalTime {};

priority_queue<pair<double,int>> q {};

int getDist2(int i, int j){
    int dx {locs[i][0] - locs[j][0]};
    int dy {locs[i][1] - locs[j][1]};

    return dx*dx + dy*dy;
}

void process(int pos, int maxDist){
    visited[pos] = true;
    totalTime += (sqrt(maxDist) * locs[pos][2]);
    
    for(int i=0;i<nIslands;++i){
        if(!visited[i]){
            q.emplace(-max(maxDist,getDist2(pos,i)),i);
        }
    }
}

int main(){
    int tc {};
    while(scanf("%d\n",&nIslands),nIslands!=0){
        totalInhabitants = 0;
        totalTime = 0;
        nProcessed = 0;

        while(!q.empty()){
            q.pop();
        }

        for(int i=0;i<nIslands;++i){
            scanf("%d %d %d\n",&locs[i][0],&locs[i][1],&locs[i][2]);
            visited[i] = false;
            totalInhabitants+=locs[i][2];
        }

        process(0,0);
        //process q
        while(nProcessed<nIslands && !q.empty()){
            auto curr {q.top()};
            q.pop();

            if(visited[curr.second]) continue;

            ++nProcessed;
            process(curr.second,-curr.first);
        }

        printf("Island Group: %d Average %.02lf\n\n",++tc,totalTime/totalInhabitants);
    }
}