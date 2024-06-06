#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int gridSize;
bool visited[41][41][3] {};

bool inGrid(int row, int col){
    return row > 0 && row <= gridSize && col > 0 && col <= gridSize;
}

void generateMoves(int row, int col, int prevCode, vector<tuple<int,int,int>> &vp){
    const static int dRow[12] {-2,-2,-1,-1,1,1,2,2,-2,-2,2,2};
    const static int dCol[12] {-1,1,-2,2,-2,2,-1,1,-2,2,-2,2};

    vp.clear();

    //normal moves
    int tRow, tCol;
    int idFrom, idTo;

    switch(prevCode){
        case 0:
            idFrom = 8;
            idTo = 12;
            break;
        case 1:
            idFrom = 0;
            idTo = 8;
            break;
        default:
            idFrom = 0;
            idTo = 12;
    }
    for(int i=idFrom;i<idTo;++i){
        tRow = row + dRow[i];
        tCol = col + dCol[i];
        if(inGrid(tRow,tCol) && !visited[tRow][tCol][i<8?0:1]){
            vp.emplace_back(tRow,tCol,(i<8?0:1));
        }
    }

    if(prevCode != 2){
        tRow = (gridSize+1-row);
        tCol = (gridSize+1-col);

        if(!visited[tRow][col][2]){
            vp.emplace_back(tRow,col,2);
        }
        if(!visited[row][tCol][2]){
            vp.emplace_back(row,tCol,2);
        }
    }
}

int main(){
    while(scanf("%d\n",&gridSize),gridSize>0){
        memset(visited,false,sizeof(visited));
        gridSize<<=1;

        int rFrom, cFrom;
        int rTo, cTo;
        int row, col, code, dist;

        queue<tuple<int,int,int,int>> q {};

        scanf("%d %d\n",&rFrom,&cFrom);
        scanf("%d %d\n",&rTo,&cTo);
        while(scanf("%d %d\n",&row,&col),row!=0||col!=0){
            for(int i=0;i<3;i++){
                visited[row][col][i] = true;
            }
        }

        //prepare the queue
        q.emplace(rFrom,cFrom,-1,0);
        for(int i=0;i<3;i++){
            visited[rFrom][cFrom][i] = true;
        }

        vector<tuple<int,int,int>> nxtPoints {};
        
        int ans {-1};
        if(rFrom==rTo && cFrom==cTo){
            ans=0;
        } else if(visited[rTo][cTo][0]){
            ans=-2;
        }

        while(!q.empty() && ans ==-1){
            auto t {q.front()};
            q.pop();

            row = get<0>(t);
            col = get<1>(t);
            code = get<2>(t);
            dist = get<3>(t);
            
            generateMoves(row,col,code,nxtPoints);

            for(auto nxt:nxtPoints){
                visited[get<0>(nxt)][get<1>(nxt)][get<2>(nxt)] = true;

                if(get<0>(nxt)==rTo && get<1>(nxt)==cTo){
                    ans = dist+1;
                    break;
                }
                q.emplace(get<0>(nxt),get<1>(nxt),get<2>(nxt),dist+1);
            }
        }

        if(ans < 0){
            printf("Solution doesn't exist\n");
        } else {
            printf("Result : %d\n",ans);
        }
    }
}