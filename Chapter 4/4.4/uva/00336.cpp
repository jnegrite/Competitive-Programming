#include<cstdio>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<vector<int>> paths {};
vector<bool> visited {};

vector<int> points {};
unordered_map<int,int> mapPoints {};


int getIdx(int val){
    auto it {mapPoints.find(val)};
    if(it != mapPoints.end()){
        return it->second;
    }

    int ans = mapPoints[val] = points.size();
    points.push_back(val);
    paths.push_back({});
    return ans;
}

int main(){
    int nRoads;
    int tc {};

    while(scanf("%d\n",&nRoads),nRoads>0){
        int a, b;
        int idxA, idxB;

        points.clear();
        paths.clear();
        mapPoints.clear();

        while(nRoads--){
            scanf("%d %d\n",&a,&b);
            idxA = getIdx(a);
            idxB = getIdx(b);

            paths[idxA].push_back(idxB);
            paths[idxB].push_back(idxA);
        }

        //do simulations
        while(scanf("%d %d\n",&a,&b),a!=0||b!=0){
            int nVisited = 1;
            visited.assign(points.size(),false);
            visited[getIdx(a)] = true;
            queue<pair<int,int>> q {};
            q.push({getIdx(a),b});

            while(!q.empty()){
                auto curr {q.front()};
                q.pop();

                if(curr.second == 0) continue;

                for(auto nxt: paths[curr.first]){
                    if(!visited[nxt]){
                        visited[nxt] = true;
                        nVisited++;

                        q.push({nxt,curr.second-1});
                    }
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++tc,points.size()-nVisited,a,b);
        }
    }
}