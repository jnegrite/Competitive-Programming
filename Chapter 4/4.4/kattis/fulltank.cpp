#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>

using namespace std;

int nCities;
int nRoads;
int capacity;

bool visited[1000][100] {};
int fuelPrices[1000] {};
vector<vector<pair<int,int>>> paths {};

int main(){
    scanf("%d %d\n",&nCities,&nRoads);
    paths.assign(nCities,{});

    for(int i=0;i<nCities;i++){
        scanf("%d",&fuelPrices[i]);
    }

    int a, b, w;
    while(nRoads--){
        scanf("%d %d %d\n",&a,&b,&w);
        paths[a].emplace_back(b,w);
        paths[b].emplace_back(a,w);
    }

    int nQueries;
    scanf("%d\n",&nQueries);
    while(nQueries--){
        scanf("%d %d %d\n",&capacity,&a,&b);
        memset(visited,false,sizeof(visited));

        priority_queue<tuple<int,int,int>> q {};
        q.emplace(0,a,0);

        int ans {-1};
        while(!q.empty()){
            auto t {q.top()};
            q.pop();

            int currCost {get<0>(t)};
            int currPos {get<1>(t)};
            int currFuel {get<2>(t)};

            if(currPos == b){
                ans = -currCost;
                break;
            }

            //check if already visited
            if(visited[currPos][currFuel]) continue;

            visited[currPos][currFuel] = true;

            //try fueling up
            if(currFuel < capacity){
                q.emplace(currCost-fuelPrices[currPos],currPos,currFuel+1);
            }

            //try moving
            for(auto nxt: paths[currPos]){
                //check if valid fuel
                if (currFuel < nxt.second) continue;

                //check if visited
                if(visited[nxt.first][currFuel-nxt.second]) continue;

                q.emplace(currCost,nxt.first,currFuel-nxt.second);
            }
        }

        if(ans == -1){
            printf("impossible\n");
        } else {
            printf("%d\n",ans);
        }
    }
}
