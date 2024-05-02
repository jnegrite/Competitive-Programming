#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int dx, dy, q;
int x, y;
long n;
long nShops[3001][1001] {};
long memo[3001][1001] {};

long performQuery(int xC, int yC, long radius){
    long ans {0};
    int x, y;
    int offset;

    if(radius==0){
        return nShops[yC][xC];
    }

    // top corner
    ans += memo[yC+radius][xC];
    ans += memo[yC+radius-1][xC];

    //left wing
    for(int i=0;i<2;i++){
        y = yC-1;
        x = xC-radius-i;

        //adjust if over the limit
        if (x < 1){
            offset = 1-x;
            x += offset;
            y -= offset;
        }

        if(y >= 1){
            ans -= memo[y][x];     
        }
    }

    //right wing
    for(int i=0;i<2;i++){
        y = yC-1;
        x = xC+radius+i;

        //adjust if over the limit
        if (x > dx){
            offset = x-dx;
            x -= offset;
            y -= offset;
        }

        if(y >= 1){
            ans -= memo[y][x];     
        }
    }

    for(int i=1;i<=2;i++){
        if(yC-radius-i>=1){
            ans += memo[yC-radius-i][xC];
        }
    }

    return ans;
}

long getBestLocation(long radius, pair<int,int> &coord){
    coord.first=1;
    coord.second=1;
    long ans {0};

    if(radius >= (dx+dy-2)){
        return n;
    }

    for(int y=1;y<=dy;++y){
        for(int x=1;x<=dx;++x){
            long localShops = performQuery(x, y, radius);
            if(localShops > ans){
                ans = localShops;
                coord.first = x;
                coord.second = y;
            }
        }
    }
    return ans;
}

int main(){
    int tc {0};

    while(scanf("%d %d %ld %d\n", &dx, &dy, &n, &q),
            dx!=0 || dy!=0 || n!=0 || q!=0){
        memset(nShops,0,sizeof(nShops));
        memset(memo,0,sizeof(memo));

        //read coffee shops first
        for(long i=0;i<n;++i){
            scanf("%d %d\n", &x, &y);
            nShops[y][x]++;
        }

        //create dp table
        int maxY {2*dy + dx};
        for(int y {1}; y<=maxY; ++y){
            for(int x{1}; x<=dx; ++x){
                long &curr {memo[y][x]};
                curr += nShops[y][x];

                if(y > 1){
                    if(x > 1){
                        curr += memo[y-1][x-1];
                    }

                    if (x < dx){
                        curr += memo[y-1][x+1];
                    }

                    if(y > 2 && x>1 && x<dx){
                        curr -= memo[y-2][x];
                    }
                }
            }
        }

        printf("Case %d:\n",++tc);

        //perform queries
        pair<int,int> coord {};
        long radius;
        long ans;
        while(q--){
            scanf("%ld\n",&radius);
            ans = getBestLocation(radius,coord);
            printf("%ld (%d,%d)\n",ans,coord.first,coord.second);
        }
    }
}