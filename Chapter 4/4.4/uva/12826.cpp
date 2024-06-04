#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<tuple>
#include<iostream>

using namespace std;
using ii = pair<int,int>;

int rFrom, cFrom, rTo, cTo, rB, cB;
bool visited[8][8] {};

int main(){
    int tc {};

    while(scanf("%d %d %d %d %d %d\n",&rFrom, &cFrom, &rTo, &cTo, &rB, &cB) != EOF){
        memset(visited,false,sizeof(visited));

        rFrom--;
        cFrom--;
        rTo--;
        cTo--;
        visited[rB-1][cB-1] = true;

        queue<tuple<int,int,int>> q {};
        q.emplace(rFrom, cFrom, 0);
        visited[rFrom][cFrom] = true;

        int ans {-1};
        while(!q.empty() && ans==-1){
            auto curr {q.front()};
            q.pop();

            int row {get<0>(curr)};
            int col {get<1>(curr)};
            int currDist {get<2>(curr)};

            if(row == rTo && col == cTo){
                ans = currDist;
                break;
            }

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int tRow {row+i};
                    int tCol {col+j};

                    if(tRow < 0 || tRow >= 8 ||
                        tCol < 0 || tCol >= 8 ||
                        visited[tRow][tCol]) continue;

                    visited[tRow][tCol] = true;
                    q.emplace(tRow,tCol,currDist+1);
                }
            }
        }
        cout << "Case " << ++tc << ": " << ans << '\n';
    }
}


