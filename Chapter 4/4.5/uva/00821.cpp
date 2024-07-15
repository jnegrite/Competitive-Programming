#include<iostream>
#include<set>

using namespace std;

int dist[101][101] {};
set<int> knownVals {};

void reset(){
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            dist[i][j] = (i==j ? 0 : 1000);
        }
    }
    knownVals.clear();
}

int main(){
    int tc {};
    while(true){
        //get data
        reset();

        int a, b;
        while(cin >> a >> b, a!=0 && b!=0){
            dist[a][b] = 1;
            knownVals.emplace(a);
            knownVals.emplace(b);
        }

        if(knownVals.empty()){
            break;
        }

        for(auto k {knownVals.begin()}; k!=knownVals.end(); ++k){
            for(auto i {knownVals.begin()}; i!=knownVals.end(); ++i){
                for(auto j {knownVals.begin()}; j!=knownVals.end(); ++j){
                    dist[*i][*j] = min(dist[*i][*j], dist[*i][*k] + dist[*k][*j]);
                }
            }
        }

        //evaluate
        double ans {};
        for(auto i {knownVals.begin()}; i!=knownVals.end(); ++i){
            for(auto j {knownVals.begin()}; j!=knownVals.end(); ++j){
                ans += dist[*i][*j];
            }
        }
        int nPoints {knownVals.size() * (knownVals.size()-1)};
        printf("Case %d: average length between pages = %.3f clicks\n",++tc,ans/nPoints);
    }
}