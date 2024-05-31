#include<cstdio>
#include<queue>
#include<tuple>

using namespace std;

int rows, cols, weakPoints;
bool visited[101][101] {};
int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

bool inGrid(int row, int col){
    return row > 0 && row <= rows &&
        col > 0 && col <= cols;
}

int main(){
    scanf("%d %d %d\n",&rows,&cols,&weakPoints);
    int a, b;

    queue<tuple<int,int,int>> q {};
    while(weakPoints--){
        scanf("%d %d\n",&a,&b);
        if(visited[a][b]) continue;

        visited[a][b] = true;
        q.push({a,b,1});
    }

    int nDays {0};
    while(!q.empty()){
        auto curr {q.front()};
        q.pop();

        nDays = get<2>(curr);
        int row, col, tRow, tCol;
        row = get<0>(curr);
        col = get<1>(curr);

        for(int i=0;i<4;i++){
            tRow = row + dRow[i];
            tCol = col + dCol[i];
            
            if(!inGrid(tRow,tCol) || visited[tRow][tCol]) continue;

            visited[tRow][tCol] = true;

            q.push({tRow,tCol,get<2>(curr)+1});
        }
    }
    printf("%d\n",nDays);
}