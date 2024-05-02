#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int d;

struct Island {
    int x {};
    int y {};
    double radar {};

    Island(int _x, int _y){
        x = _x;
        y = _y;
        radar = x + sqrt(d*d - y*y);
    }

    bool operator<(const Island &o) const{
        return radar < o.radar;
    }

    bool inRange(double radar){
        double dx {abs(x-radar)};
        return d*d >= (y*y + dx*dx);
    }
};

vector<Island> islands {};
vector<double> radars {};

int main(){
    int n;
    int tc {0};
    int x, y;
    while(scanf("%d %d\n",&n,&d),n!=0 || d!=0){
        int ans {0};
        islands.clear();
        radars.clear();

        for(int i=0;i<n;i++){
            scanf("%d %d\n",&x,&y);
            islands.push_back(Island{x,y});
            if(y>d){
                ans=-1;
                break;
            }
        }

        ++tc;
        if(ans == -1){
            printf("Case %d: -1\n",tc);
            continue;
        }

        sort(islands.begin(),islands.end());
        for(Island is: islands){
            //check if covered by any existing radar
            bool covered {false};
            for(double radar:radars){
                if(is.inRange(radar)){
                    covered = true;
                    break;
                }
            }

            if(!covered){
                radars.push_back(is.radar);
            }
        }

        printf("Case %d: %d\n",tc,radars.size());
    }
}