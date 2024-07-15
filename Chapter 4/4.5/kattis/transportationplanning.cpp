#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

int nPoints;
vector<pair<double,double>> points {};

double distBase[100][100] {};
double distBaseSolved[100][100] {};
double dist[100][100] {};

void perfAlgo(int k){
    for(int i=0;i<nPoints;i++){
        if(dist[i][k] < 0) continue;
        for(int j=0;j<nPoints;j++){
            if(dist[k][j] < 0) continue;

            double posDist {dist[i][k] + dist[k][j]};
            if((dist[i][j] < 0) || (dist[i][j] > posDist)){
                dist[i][j] = posDist;
            }
        }
    }
}

double getScore(){    
    double ans {0};
    for(int i=0;i<nPoints;i++){
        for(int j=i+1;j<nPoints;j++){
            ans += dist[i][j];
        }
    }
    return ans;
}

int main(){
    while(scanf("%d\n",&nPoints), nPoints!=0){
        for(int i=0;i<nPoints;i++){
            for(int j=0;j<nPoints;j++){
                distBase[i][j] = (i==j? 0 : -1);
            }
        }
        points.clear();

        double a, b;
        for(int i=0;i<nPoints;i++){
            scanf("%lf %lf\n",&a,&b);
            points.emplace_back(a,b);
        }

        //get linked paths
        int nPaths;
        scanf("%d\n",&nPaths);
        int p1, p2;
        double currDist, dx, dy;
        while(nPaths--){
            scanf("%d %d\n",&p1,&p2);
            dx = points[p1].first - points[p2].first;
            dy = points[p1].second - points[p2].second;
            currDist = sqrt(dx*dx + dy*dy);
            distBase[p1][p2] = distBase[p2][p1] = currDist;
        }

        //check base
        memcpy(dist, distBase,sizeof(distBase));
        //perform algorithm
        for(int k=0;k<nPoints;k++){
            perfAlgo(k);
        }
        memcpy(distBaseSolved,dist,sizeof(dist));

        double baseDist {getScore()};
        double bestDist {baseDist};
        pair<int,int> bestPair {-1,-1};

        for(int i=0;i<nPoints;i++){
            for(int j=i+1;j<nPoints;j++){
                if(distBase[i][j] != -1) continue;

                memcpy(dist, distBaseSolved,sizeof(distBaseSolved));
                dx = points[i].first - points[j].first;
                dy = points[i].second - points[j].second;
                currDist = sqrt(dx*dx + dy*dy);
                dist[i][j] = dist[j][i] = currDist;

                perfAlgo(i);
                perfAlgo(j);
                
                double tempScore {getScore()};
                if(tempScore < bestDist){
                    bestDist = tempScore;
                    bestPair = {i,j};
                }
            }
        }

        if(bestPair.first == -1 && bestPair.second == -1){
            printf("no addition reduces %.6lf\n",bestDist);
        } else {
            printf("adding %d %d reduces %.6lf to %.6lf\n",bestPair.first,bestPair.second,baseDist,bestDist);
        }
    }
}