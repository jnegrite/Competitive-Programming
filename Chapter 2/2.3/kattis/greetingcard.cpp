#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

int dRow[12] {-2018,-1680,-1118,0,1118,1680,2018,1680,1118,0,-1118,-1680};
int dCol[12] {0,1118,1680,2018,1680,1118,0,-1118,-1680,-2018,-1680,-1118};

int main(){
    long numPoints;
    cin >> numPoints;
    long x, y;
    long ans {0};
    unordered_set<string> seenPoints {};
    while(numPoints--){
        cin >> x >> y;
        pair<long,long> curr {x,y};
        for(int i=0;i<12;i++){
            long tempX {x+dRow[i]};
            long tempY {y+dCol[i]};
            if(tempX >= 0 && tempY >= 0){
                string sTemp {to_string(tempX) + ":"+ to_string(tempY)};
                if(seenPoints.count(sTemp) > 0){
                    ans++;
                }
            }
            seenPoints.emplace(to_string(x)+":"+to_string(y));
        }
    }
    cout << ans << '\n';
}