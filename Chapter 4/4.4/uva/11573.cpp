#include<cstdio>
#include<cstring>
#include<queue>
#include<tuple>

using namespace std;

int rows, cols;
char s[1001] {};

int grid[1000][1000] {};
int dRow[8] {-1,-1,0,1,1, 1, 0,-1};
int dCol[8] { 0, 1,1,1,0,-1,-1,-1};

bool inGrid(int row, int col){
    return row>=0 && row<rows && col>=0 && col<cols;
}

int getDist(int rFrom, int cFrom, int rTo, int cTo){
    bool visited[1000][1000] {};
    
    deque<tuple<int,int,int>> q {};
    q.emplace_back(rFrom,cFrom,0);

    while(!q.empty()) {
        auto curr {q.front()};
        q.pop_front();

        int row {get<0>(curr)};
        int col {get<1>(curr)};
        int currDist {get<2>(curr)};

        if(visited[row][col]) continue;
        
        visited[row][col] = true;
        //printf("Processing %d:%d    %d\n",row,col,currDist);

        if(row==rTo && col==cTo){
            return currDist;
        }

        for(int i=0;i<8;i++){
            int tRow {row+dRow[i]};
            int tCol {col+dCol[i]};

            if(!inGrid(tRow,tCol) || visited[tRow][tCol]) continue;
            
            if(i==grid[row][col]){
                q.emplace_front(tRow,tCol,currDist);
            } else {
                q.emplace_back(tRow,tCol,currDist+1);
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d %d\n",&rows,&cols);

    for(int row=0;row<rows;++row){
        scanf("%s\n",&s);
        for(int col=0;col<cols;col++){
            grid[row][col] = (s[col]-'0');
        }
    }

    int nTrips;
    scanf("%d\n",&nTrips);
    while(nTrips--){
        int rFrom, cFrom, rTo, cTo;
        scanf("%d %d %d %d\n",&rFrom,&cFrom,&rTo,&cTo);
        printf("%d\n",getDist(rFrom-1,cFrom-1,rTo-1,cTo-1));
    }
}