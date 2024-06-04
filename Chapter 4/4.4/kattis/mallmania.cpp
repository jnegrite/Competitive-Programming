#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<tuple>

using namespace std;

int grid[2001][2001] {};
bool visited[2001][2001] {};

int dX[4] {-1,0,1,0};
int dY[4] {0,1,0,-1};

void trace(int x1, int y1, int x2, int y2, int code){
    if(x1==x2){
        if(y1>y2){
            swap(y1,y2);
        }

        for(int y=y1;y<=y2;y++){
            grid[x1][y] = code;
        }
    } else if(y1==y2){
        if(x1>x2){
            swap(x1,x2);
        }

        for(int x=x1;x<=x2;x++){
            grid[x][y1] = code;
        }
    }
}

bool inGrid(int x, int y){
    return x>=0 && x<=2000 && y>=0 && y<=2000;
}

int main(){
    int n1, n2;
    int x, y;
    int x1, y1;

    vector<pair<int,int>> points {};

    while(scanf("%d\n",&n1), n1!=0){
        memset(grid,0,sizeof(grid));
        memset(visited,false,sizeof(visited));
        points.clear();
        for(int i=0;i<n1;i++){
            scanf("%d %d",&x,&y);
            points.emplace_back(x,y);
        }

        //process
        for(int i=1;i<n1;i++){
            int j=i-1;
            trace(points[j].first,points[j].second,points[i].first,points[i].second,-1);
        }
        x1 = points[0].first;
        y1 = points[0].second;
        trace(points[0].first,points[0].second,points[n1-1].first,points[n1-1].second,-1);

        //second set of points
        points.clear();
        scanf("%d\n",&n1);
        for(int i=0;i<n1;i++){
            scanf("%d %d",&x,&y);
            points.emplace_back(x,y);
        }

        //process
        for(int i=1;i<n1;i++){
            int j=i-1;
            trace(points[j].first,points[j].second,points[i].first,points[i].second,-2);
        }
        trace(points[0].first,points[0].second,points[n1-1].first,points[n1-1].second,-2);

        //do the queue
        deque<tuple<int,int,int>> q {};
        
        q.emplace_back(x1,y1,0);
        visited[x1][y1] = true;

        int ans {-1};
        while(!q.empty() && ans==-1){
            auto curr {q.front()};
            q.pop_front();

            x = get<0>(curr);
            y = get<1>(curr);
            int currDist {get<2>(curr)};

            for(int i=0;i<4;i++){
                int tX {x+dX[i]};
                int tY {y+dY[i]};

                if(!inGrid(tX,tY) || visited[tX][tY]) continue;
                
                visited[tX][tY] = true;
                switch(grid[tX][tY]){
                    case -2:
                        ans = currDist+1;
                        break;
                    case -1:
                        q.emplace_front(tX,tY,currDist);
                        break;
                    case 0:
                        q.emplace_back(tX,tY,currDist+1);
                        break;
                }
            }
        }

        printf("%d\n",ans);

    }
}