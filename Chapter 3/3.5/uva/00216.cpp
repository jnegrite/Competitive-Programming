#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>

#define INF 1000000000

#define LSOne(x) ((x) & -(x))

using namespace std;

int points[8][2] {};
int nPoints;
double dist[8][8] {};

double memo[8][(1<<9)] {};

double getDistance(int i, int j){
    double dx {abs(points[i][0] - points[j][0])};
    double dy {abs(points[i][1] - points[j][1])};

    return sqrt(dx*dx + dy *dy);
}

double dp(int pos, int mask){
    if(mask==0){
        return 0;
    }

    auto &curr {memo[pos][mask]};
    int tMask {mask};

    curr = INF;
    while(tMask != 0){
        int flag {LSOne(tMask)};
        int target {__builtin_ctz(flag)};
        curr = min(curr, dist[pos][target] + dp(target, mask ^ flag));
        tMask -= flag;
    }
    return curr;
}

void traceBack(int pos, int mask){
    
    if(mask==0){
        return;
    }
    int bestTarget {-1};
    double bestDist {INF};
    int tMask {mask};
    
    while(tMask != 0){
        int flag {LSOne(tMask)};
        int target {__builtin_ctz(flag)};
        double testDist {dist[pos][target] + dp(target, mask ^ flag)};
        if(testDist < bestDist){
            bestDist = testDist;
            bestTarget = target;
        }
        tMask -= flag;
    }

    printf(
        "Cable requirement to connect (%d,%d) to (%d,%d) is %0.2lf feet.\n",
        points[pos][0], points[pos][1],
        points[bestTarget][0], points[bestTarget][1],
        16 + dist[pos][bestTarget]
    );
    traceBack(bestTarget, mask ^ (1<<bestTarget));
}

int main(){
    int tc {};
    while(scanf("%d\n",&nPoints),nPoints!=0){
        //get data
        for(int i=0;i<nPoints;i++){
            scanf("%d %d\n",&points[i][0],&points[i][1]);
        }

        //compute distances;
        for(int i=0;i<nPoints;++i){
            dist[i][i] = 0;
            for(int j=i+1;j<nPoints;++j){
                dist[i][j] = dist[j][i] = getDistance(i,j); 
            }
        }

        double bestDist {INF};
        int baseMask {(1<<(nPoints))-1};
        int bestStart {-1};
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<nPoints;i++){
            int newMask {baseMask - (1<<i)};
            double currDist {dp(i,newMask)};
            if(currDist < bestDist){
                bestDist = currDist;
                bestStart=i;
            }
        }

        bestDist += (16* (nPoints-1));
        printf("**********************************************************\n");
        printf("Network #%d\n",++tc);
        traceBack(bestStart,(baseMask-(1<<bestStart)));
        printf("Number of feet of cable required is %.02lf.\n",bestDist);
    }
}