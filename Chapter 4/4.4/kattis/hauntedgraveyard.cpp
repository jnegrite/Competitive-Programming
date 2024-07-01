#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;


const int INF {1000000000};
const int NINF {-INF};

int rows, cols, nCells;
int grid[30][30][3] {};
bool visited[30][30] {};

int dist[30][30]{};

int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

bool inGrid(int row, int col){
    return row>=0 && row<rows && col>=0 && col<cols;
}

bool process(int row, int col){
    if(!visited[row][col]) return false;

    int tRow, tCol, tDist;
    bool didUpdate {false};

    if((row==(rows-1)) && (col == (cols-1))){
        return false;
    }

    if (grid[row][col][0] >= 0){
        tRow = grid[row][col][0];
        tCol = grid[row][col][1];
        tDist = dist[row][col] + grid[row][col][2];

        if(!visited[tRow][tCol] || tDist < dist[tRow][tCol]){
            didUpdate = true;
            visited[tRow][tCol] = true;
            dist[tRow][tCol] = tDist;
        }
    } else {
        tDist = dist[row][col]+1;
        for(int i=0;i<4;i++){
            tRow = row + dRow[i];
            tCol = col + dCol[i];

            if(!inGrid(tRow,tCol) || grid[tRow][tCol][0] == -2) continue;

            if(!visited[tRow][tCol] || tDist < dist[tRow][tCol]){
                didUpdate = true;
                visited[tRow][tCol] = true;
                dist[tRow][tCol] = tDist;
            }
        }
    }

    return didUpdate;
}

int main(){
    while(scanf("%d %d\n", &cols, &rows), rows!=0 || cols!=0){
        memset(grid,-1,sizeof(grid));
        memset(visited,false,sizeof(visited));
        memset(dist,INF,sizeof(dist));
        
        nCells = rows * cols;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                dist[i][j] = INF;
            }
        }
        dist[0][0] = 0;


        int nGravestones;
        scanf("%d\n",&nGravestones);
        int r1, c1;
        while(nGravestones--){
            scanf("%d %d\n",&c1,&r1);
            grid[r1][c1][0] = -2;
        }

        int r2, c2, t, nPortals;
        scanf("%d\n",&nPortals);
        while(nPortals--){
            scanf("%d %d %d %d %d\n",&c1,&r1,&c2,&r2,&t);
            auto &target {grid[r1][c1]};
            target[0] = r2;
            target[1] = c2;
            target[2] = t;
        }

        int reps;
        visited[0][0] = true;
        for(reps=0;reps<nCells;reps++){
            bool didUpdate = false;
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    if(process(i,j)){
                        didUpdate = true;
                    }
                }
            }

            if(!didUpdate) break;
        }

        if(reps == nCells){
            printf("Never\n");
        } else if (!visited[rows-1][cols-1]){
            printf("Impossible\n");
        } else {
            printf("%d\n",dist[rows-1][cols-1]);
        }
    }
}