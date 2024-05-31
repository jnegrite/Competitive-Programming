#include<cstdio>
#include<cstring>
#include<queue>
#include<tuple>

using namespace std;

bool visited[1000][1000] {};
int rows, cols;
int rFrom, cFrom, rTo, cTo;
int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

bool inGrid(int row, int col){
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

int main(){

    while(scanf("%d %d\n",&rows,&cols),rows!=0 || cols!=0){
        memset(visited,false,sizeof(visited));

        int nRows, nCols, row, col;
        scanf("%d\n",&nRows);

        while(nRows--){
            scanf("%d %d",&row,&nCols);
            while(nCols--){
                scanf("%d",&col);
                visited[row][col] = true;
            }
        }

        scanf("%d %d %d %d\n",&rFrom,&cFrom,&rTo,&cTo);

        queue<tuple<int,int,int>> q {};
        visited[rFrom][cFrom] = true;
        
        int ans {-1};
        if(rFrom==rTo && cFrom==cTo){
            ans = 0;
        } else {
            q.push({rFrom,cFrom,0});
            while(!q.empty() && ans < 0){
                auto curr {q.front()};
                q.pop();

                row = get<0>(curr);
                col = get<1>(curr);

                for(int i=0;i<4;++i){
                    int tRow {row + dRow[i]};
                    int tCol {col + dCol[i]};

                    if(!inGrid(tRow,tCol)) continue;
                    if(visited[tRow][tCol]) continue;

                    visited[tRow][tCol] = true;

                    if(tRow == rTo && tCol == cTo){
                        ans = get<2>(curr)+1;
                        break;
                    }

                    q.emplace(tRow,tCol,get<2>(curr)+1);
                }
            }
        }
        printf("%d\n",ans);
    }
}
