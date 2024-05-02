#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<iostream>

using namespace std;

vector<map<int,long>> costs {};

int change[100001] {};
bool visitedPoints[51] {};
long paths[52][3] {};
int nPaths {};
const long INF = 200000L;

bool findPath(int from, int to){
    if(from == to){
        paths[nPaths][0] = to;
        return true;
    }
    
    auto currMap {costs[from]};
    visitedPoints[from] = true;
    for(auto it {currMap.begin()};it!=currMap.end();++it){
        int nxtPt {it->first};

        if(visitedPoints[nxtPt] == 0 && findPath(nxtPt,to)){
            paths[nPaths][1] = from;
            paths[nPaths][2] = costs[paths[nPaths][0]][from];
            paths[++nPaths][0] = from;
            return true;
        }
    }
    return false;
}

int dp(long cost){
    if (cost < 0){
        return INF;
    }

    if(cost==0){
        return 0;
    }

    auto &curr {change[cost]};
    if(curr != -1){
        return curr;
    }

    curr = INF;
    for(int i=1;i<nPaths;i++){
        curr=min(curr,dp(cost-paths[i][2]));
    }

    if(curr==INF){
        return curr;
    } else {
        return ++curr;
    }
}

int main(){
    int nCases;
    int d1, d2, c;
    scanf("%d\n",&nCases);
    for(int tc=0;tc<nCases;tc++){
        int nUnika;
        long nRoads;
        scanf("%d %ld\n",&nUnika,&nRoads);
        costs.assign(nUnika+1,{});
        while(nRoads--){
            scanf("%d %d %d\n",&d1,&d2,&c);
            costs[d1][d2] = c;
            costs[d2][d1] = c;
        }
        int nQueries;
        scanf("%d\n",&nQueries);

        if(tc > 0){
            printf("\n");
        }
        while(nQueries--){
            scanf("%d %d %d\n",&d1,&d2,&c);
            nPaths = 0;
            memset(visitedPoints,false,sizeof(visitedPoints));
            findPath(d1,d2);
            long basePath {};
            for(int i=0;i<nPaths;++i){
                basePath += paths[i][2];
            }
            long remAlloc(c-basePath);
            memset(change,-1,sizeof(change));
            long minPath;
            if(remAlloc % 2 == 1){
                minPath = -2;
            } else {
                minPath = dp(remAlloc>>1);
                if(minPath>=INF){
                    minPath == -2;
                } else {
                    minPath = (2*minPath) + nPaths;
                }
            }

            if(minPath == -2 || minPath >= INF){
                printf("No\n");
            } else {
                printf("Yes %d\n",minPath);
            }
        }
    }
}