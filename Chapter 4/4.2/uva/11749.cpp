#include<cstdio>
#include<vector>

#define NEGINF -2147483648
using namespace std;
using ii = pair<int,int>;

int nCities;
int bestRoad;
int a, b, c;
vector<vector<ii>> paths {};
vector<int> highRoad {};
vector<bool> visited {};

int dfs(int pos){
    int ans = 1;
    visited[pos] = true;
    for(ii &pr: paths[pos]){
        if(!visited[pr.first] && pr.second == bestRoad){
            ans += dfs(pr.first);
        }
    }
    return ans;
}

int main(){
    int nRoads;

    while(scanf("%d %d\n",&nCities,&nRoads),nCities!=0 || nRoads!=0){
        bestRoad = NEGINF;
        paths.assign(nCities+1,{});
        highRoad.assign(nCities+1,NEGINF);
        visited.assign(nCities+1,false);
        int ans;

        while(nRoads--){
            scanf("%d %d %d\n", &a, &b, &c);

            paths[a].push_back({b,c});
            paths[b].push_back({a,c});
            bestRoad = max(bestRoad,c);
            highRoad[a] = max(highRoad[a],c);
            highRoad[b] = max(highRoad[b],c);
        }

        ans = 1;
        for(int i=1;i<=nCities;++i){
            if(!visited[i] && highRoad[i] == bestRoad){
                ans = max(ans,dfs(i));
            }
        }

        printf("%d\n",ans);
    }
}